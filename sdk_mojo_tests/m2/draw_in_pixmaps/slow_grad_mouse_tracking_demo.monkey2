' Slow Gradient Mouse Tracking
' Implementation by iDkP from GaragePixel
' 2025-03-24 Aida 4
'
' Purpose:
' Demonstrates interactive gradient rendering techniques using pixmaps,
' with both smooth and Bayer dithered gradients that track mouse position.
'
' Functionality:
' - Smooth gradient rendering with dynamic reference points
' - Bayer dithering pattern implementation for stylized gradients
' - Interactive gradient direction controlled by mouse position
' - Side-by-side comparison of dithering techniques
' - Performance optimized pixmap manipulation
'
' Notes:
' This implementation uses pixmap-based rendering to achieve high-quality
' gradients with precise color transitions. The mouse tracking creates
' an interactive experience where gradient reference points follow cursor
' position, demonstrating how static rendering techniques can be made
' responsive through parameter adjustment rather than per-pixel recalculation.
' It's very slow because of the DrawPixmapToCanvas. Mojo isn't optimized for
' this kind of stuff. So the best way is to draw pixmaps onto pixmaps, as
' a final pixmap should acts as a "backbuffer" will this backbuffer should
' be used to create the texture of a image, and then draw this image to
' the app's canvas.


#Import "<stdlib>"
#Import "<sdk_mojo>"

Using stdlib..
Using sdk_mojo..

' Function to draw a pixmap onto a canvas
Function DrawPixmapToCanvas:Void(canvas:Canvas, pixmap:Pixmap, x:Int, y:Int)
	Local oldColor:Color = canvas.Color
	
	For Local py:Int = 0 Until pixmap.Height
		Local canvasY:Int = y + py
		If canvasY < 0 Or canvasY >= canvas.Viewport.Height Then Continue
		
		For Local px:Int = 0 Until pixmap.Width
			Local canvasX:Int = x + px
			If canvasX < 0 Or canvasX >= canvas.Viewport.Width Then Continue
			
			canvas.Color = pixmap.GetPixel(px, py)
			canvas.DrawPoint(canvasX, canvasY)
		Next
	Next
	
	canvas.Color = oldColor
End

' Gradient view handler
Class GradientView
	Field width:Int
	Field height:Int
	
	' Pixmaps for rendering
	Field smoothGradientPixmap:Pixmap
	Field bayerGradientPixmap:Pixmap
	
	' Mouse tracking
	Field mouseX:Float = 0.5
	Field mouseY:Float = 0.5
	
	' Gradient colors
	Field startColor:Color = New Color(0.2, 0.4, 1.0)
	Field endColor:Color = New Color(1.0, 0.2, 0.6)
	
	Method New(width:Int, height:Int)
		Self.width = width
		Self.height = height
		
		' Create pixmaps for rendering
		smoothGradientPixmap = New Pixmap(width / 2, height)
		bayerGradientPixmap = New Pixmap(width / 2, height)
	End
	
	Method Update(mouseX:Float, mouseY:Float)
		Self.mouseX = mouseX / width
		Self.mouseY = mouseY / height
		
		' Update both gradient types
		UpdateSmoothGradient()
		UpdateBayerGradient()
	End
	
	Method Render(canvas:Canvas)
		' Draw the gradient pixmaps side by side
		DrawPixmapToCanvas(canvas, smoothGradientPixmap, 0, 0)
		DrawPixmapToCanvas(canvas, bayerGradientPixmap, width / 2, 0)
		
		' Draw dividing line
		canvas.Color = New Color(1, 1, 1, 0.5)
		canvas.DrawLine(width / 2, 0, width / 2, height)
		
		' Draw labels
		canvas.Color = New Color(1, 1, 1)
		canvas.DrawText("Smooth Gradient", 20, 30)
		canvas.DrawText("Bayer Dithered Gradient", width / 2 + 20, 30)
		
		' Draw mouse position indicator
		Local mousePosX:Int = mouseX * width
		Local mousePosY:Int = mouseY * height
		canvas.Color = New Color(1, 1, 0)
		canvas.DrawCircle(mousePosX, mousePosY, 5)
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
		Next
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
				
				' Apply thresholding
				Local ditherFactor:Float = 0.1
				Local ditheredDist:Float = dist
				
				If dist > threshold - ditherFactor And dist < threshold + ditherFactor
					' Create a transition zone for smoother appearance
					Local factor:Float = (dist - (threshold - ditherFactor)) / (ditherFactor * 2)
					ditheredDist = factor
				Else
					' Outside transition zone, use binary decision
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
		Next
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
Class GradientMouseTracker Extends Window
	Field gradientView:GradientView
	
	Method New()
		Super.New("Slow Gradient Mouse Tracking - GaragePixel", 800, 600, WindowFlags.Resizable)
		
		gradientView = New GradientView(Width, Height)
		
		' Initial update with center mouse position
		gradientView.Update(Width / 2, Height / 2)
	End
	
	Method OnRender(canvas:Canvas) Override
		' Clear background
		canvas.Color = New Color(0.1, 0.1, 0.1)
		canvas.DrawRect(0, 0, Width, Height)
		
		' Render gradients
		gradientView.Render(canvas)
		
		' Request next frame
		App.RequestRender()
	End
	
	Method OnMouseEvent(event:MouseEvent) Override
		If event.Type = EventType.MouseMove
			gradientView.Update(MouseLocation.X, MouseLocation.Y)
		Endif
	End
End

Function Main()
	New AppInstance
	New GradientMouseTracker
	App.Run()
End