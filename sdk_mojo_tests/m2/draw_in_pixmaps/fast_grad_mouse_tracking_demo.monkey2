' Fast Backbuffer Gradient Demo
' Implementation by iDkP from GaragePixel
' 2025-03-24 Aida 4
'
' Purpose:
' A minimal demonstration of backbuffer-based pixmap rendering for gradients,
' showcasing both smooth and Bayer dithered patterns that track mouse position.
'
' Functionality:
' - Backbuffer implementation using pixmaps for efficient rendering
' - Smooth radial gradient that follows mouse pointer
' - Bayer dithered gradient for stylized visual effect
' - Side-by-side comparison of both gradient techniques
' - Direct mouse position tracking with immediate visual response
'
' Notes:
' This test demonstrates the backbuffer approach for pixmap rendering, where
' all pixel operations are performed on separate pixmaps, then composited to
' a main backbuffer pixmap, and finally displayed using a single Image. 
' The FPS should be around ~40 on a low-end pc from around 2015.

#Import "<stdlib>"
#Import "<sdk_mojo>"

Using stdlib..
Using sdk_mojo..

' Gradient renderer with backbuffer
Class GradientBackbuffer
	Field width:Int
	Field height:Int
	
	' Pixmaps for rendering
	Field backbufferPixmap:Pixmap      ' Final composited result
	Field smoothGradientPixmap:Pixmap  ' Smooth gradient
	Field bayerGradientPixmap:Pixmap   ' Dithered gradient
	
	' Output image for display
	Field displayImage:Image
	
	' Mouse tracking
	Field mouseX:Float = 0.5
	Field mouseY:Float = 0.5
	
	' Gradient colors
	Field startColor:Color = New Color(1, 0, 1)
	Field endColor:Color = New Color(0, 1, 0)
	
	Method New(width:Int, height:Int)
		Self.width = width
		Self.height = height
		
		' Create pixmaps for rendering
		backbufferPixmap = New Pixmap(width, height)
		smoothGradientPixmap = New Pixmap(width / 2, height)
		bayerGradientPixmap = New Pixmap(width / 2, height)
		
		' Create display image
		displayImage = New Image(backbufferPixmap)
	End
	
	Method Update(mouseX:Float, mouseY:Float)
		Self.mouseX = mouseX / width
		Self.mouseY = mouseY / height
		
		' Update gradient pixmaps
		UpdateSmoothGradient()
		UpdateBayerGradient()
		
		' Composite to backbuffer
		ComposeBackbuffer()
		
		' Update display image
		displayImage = New Image(backbufferPixmap)
	End
	
	Method Render(canvas:Canvas)
		' Draw the display image to canvas
		canvas.DrawImage(displayImage, 0, 0)
	End
	
	Method ComposeBackbuffer()
		' Clear the backbuffer
		backbufferPixmap.ClearARGB($FF000000)
		
		' Copy the gradient pixmaps to the backbuffer
		For Local y:Int = 0 Until height
			For Local x:Int = 0 Until width / 2
				backbufferPixmap.SetPixel(x, y, smoothGradientPixmap.GetPixel(x, y))
				backbufferPixmap.SetPixel(x + width / 2, y, bayerGradientPixmap.GetPixel(x, y))
			Next
		End
		
		' Draw dividing line
		For Local y:Int = 0 Until height
			backbufferPixmap.SetPixel(width / 2, y, New Color(1, 1, 1, 0.7))
		Next
		
		' Draw mouse indicator
		Local mousePosX:Int = mouseX * width
		Local mousePosY:Int = mouseY * height
		backbufferPixmap.DrawCircle(mousePosX, mousePosY, 5, New Color(1, 1, 0))
	End
	
	Method UpdateSmoothGradient()
		' Calculate reference points based on mouse position
		Local refX:Float = mouseX * width / 2
		Local refY:Float = mouseY * height
		
		' Generate smooth gradient
		For Local y:Int = 0 Until height
			For Local x:Int = 0 Until width / 2
				' Calculate distance from mouse position (normalized)
				Local dx:Float = (x - refX) / (width / 2)
				Local dy:Float = (y - refY) / height
				Local dist:Float = Sqrt(dx * dx + dy * dy)
				dist = Clamp(dist, 0.0, 1.0)
				
				' Interpolate colors
				Local r:Float = Lerp(startColor.r, endColor.r, dist)
				Local g:Float = Lerp(startColor.g, endColor.g, dist)
				Local b:Float = Lerp(startColor.b, endColor.b, dist)
				
				smoothGradientPixmap.SetPixel(x, y, New Color(r, g, b))
			Next
		End
	End
	
	Method UpdateBayerGradient()
		' Calculate reference points based on mouse position
		Local refX:Float = mouseX * width / 2
		Local refY:Float = mouseY * height
		
		' Generate dithered gradient using Bayer matrix
		For Local y:Int = 0 Until height
			For Local x:Int = 0 Until width / 2
				' Calculate distance from mouse position (normalized)
				Local dx:Float = (x - refX) / (width / 2)
				Local dy:Float = (y - refY) / height
				Local dist:Float = Sqrt(dx * dx + dy * dy)
				dist = Clamp(dist, 0.0, 1.0)
				
				' Get Bayer matrix threshold for this pixel
				Local threshold:Float = BayerMatrix[(y Mod 8) * 8 + (x Mod 8)]
				
				' Apply thresholding with small transition zone for smoother appearance
				Local ditherFactor:Float = 0.1
				Local ditheredDist:Float
				
				If dist > threshold - ditherFactor And dist < threshold + ditherFactor
					' Create a transition zone
					Local factor:Float = (dist - (threshold - ditherFactor)) / (ditherFactor * 2)
					ditheredDist = factor
				Else
					' Binary decision outside transition zone
					If dist > threshold
						ditheredDist = 1.0
					Else
						ditheredDist = 0.0
					Endif
				Endif
				
				' Interpolate colors
				Local r:Float = Lerp(startColor.r, endColor.r, ditheredDist)
				Local g:Float = Lerp(startColor.g, endColor.g, ditheredDist)
				Local b:Float = Lerp(startColor.b, endColor.b, ditheredDist)
				
				bayerGradientPixmap.SetPixel(x, y, New Color(r, g, b))
			Next
		End
	End
	
	' Linear interpolation helper
	Method Lerp:Float(a:Float, b:Float, t:Float)
		Return a + (b - a) * t
	End
	
	' Clamp helper
	Method Clamp:Float(value:Float, min:Float, max:Float)
		If value < min Then Return min
		If value > max Then Return max
		Return value
	End
End

' Main application class
Class BackbufferGradientDemo Extends Window
	Field gradientBackbuffer:GradientBackbuffer
	Field resizeTimer:Int = 0
	
	Method New()
		Super.New("Fast Backbuffer Gradient Demo - GaragePixel", 800, 600, WindowFlags.Resizable)
		
		InitializeGradients()
	End
	
	Method InitializeGradients()
		gradientBackbuffer = New GradientBackbuffer(Width, Height)
		
		' Initial update with center mouse position
		gradientBackbuffer.Update(Width / 2, Height / 2)
	End
	
	Method OnRender(canvas:Canvas) Override
		' Request next frame
		App.RequestRender()

		' Check if we need to resize
		If resizeTimer > 0
			resizeTimer -= 1
			If resizeTimer = 0
				InitializeGradients() ' Recreate gradients with new size
			Endif
		Endif
		
		' Update gradients with mouse position
		gradientBackbuffer.Update(MouseLocation.X, MouseLocation.Y)
		
		' Clear background (No need to clear the canvas)
		
		' Render from backbuffer to canvas
		gradientBackbuffer.Render(canvas)
		
		' Draw text directly to canvas
		canvas.Color = New Color(1, 1, 1)
		canvas.DrawText("Smooth Gradient", 20, 30)
		canvas.DrawText("Bayer Dithered Gradient", Width / 2 + 20, 30)
		canvas.DrawText("Using Backbuffer Technique", Width / 2 - 130, Height - 30)
		
		' Draw FPS counter
		canvas.Color = New Color(0, 1, 0)
		' If you experiment a big slow down, this is because this mojo's feature
		' was coded with the feet (not by me) and so deactivate it keep the FPS
		' above 40, while activate it make a drop at 9 FPS, wtf.
		'canvas.DrawText("FPS: " + Int(App.FPS), 20, Height - 30) 
		
		' Close the App
		If Keyboard.KeyReleased(Key.Escape) 
			'Help the gc
			gradientBackbuffer.backbufferPixmap=Null
			gradientBackbuffer.smoothGradientPixmap=Null
			gradientBackbuffer.bayerGradientPixmap=Null
			GCCollect()
			'Close the app
			App.Terminate()
		End
	End
	
	Method OnWindowEvent(event:WindowEvent) Override
		' Handle window resize
		If event.Type = EventType.WindowResized
			' Set a timer to recreate gradients after resize is complete
			' because on modern OS we have always these stupid window's animations
			resizeTimer = 10
		Elseif event.Type = EventType.WindowClose ' Close the App via window's title bar.
			'Help the gc
			gradientBackbuffer.backbufferPixmap=Null
			gradientBackbuffer.smoothGradientPixmap=Null
			gradientBackbuffer.bayerGradientPixmap=Null
			GCCollect()
			'Close the app
			App.Terminate()
		Endif
	End
End

Function Main()
	New AppInstance
	New BackbufferGradientDemo
	App.Run()
End