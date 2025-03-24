' Implementation by iDkP from GaragePixel
' 2025-03-23 Aida 4
'
' Purpose:
' Demonstrates the advanced drawing capabilities of the pixmap extensions
' library with a colorful interactive showcase using sdk_mojo for display.
'
' Functionality:
' - Visual demonstration of all pixmap drawing operations
' - Interactive gradient controls with mouse movement
' - Side-by-side comparison of smooth vs dithered gradients
' - Multi-point gradient demonstrations with arbitrary control points
' - Animated bezier curves and polygon rendering examples
' - Polygon fill rule demonstration (even-odd vs winding)
' - Performance comparison of different fill techniques
'
' Notes:
' This test application uses sdk_mojo for window creation and display while
' all rendering is performed on pixmaps using the extension methods. The
' separation between drawing and display logic demonstrates how these extensions
' can be used in any stdlib-based application regardless of the rendering
' pipeline. Animations and interactive elements highlight the flexibility
' of the pixmap drawing system in dynamic environments.
'
' Technical advantages:
' Pre-rendering complex graphics to pixmaps allows for efficient composition
' with minimal per-frame overhead, which is especially beneficial for resource-
' constrained environments. The bezier curve and gradient demonstrations
' showcase how sophisticated graphics can be created without additional
' dependencies beyond stdlib. The dithering demonstration highlights
' alternative rendering techniques that can be employed for stylistic
' purposes or performance optimization on lower-end hardware.

#Import "<stdlib>"
#Import "<sdk_mojo>"

Using sdk_mojo.m2..
Using stdlib.collections..
Using stdlib.math.types..
Using stdlib.graphics..

'INTEGRATED FROM THE EXTENSION: 

	' ------------------------------------------------------
	' Extension methods for Pixmap drawing operations
	' ------------------------------------------------------
	' Implementation by iDkP from GaragePixel
	' 2025-03-23 Aida 4
	' ------------------------------------------------------

' Standalone canvas draw pixmap function (direct pixel implementation)
Function CanvasDrawPixmap(canvas:Canvas, pixmap:Pixmap, x:Float, y:Float)
	' Create source and destination rectangles
	Local srcRect:Recti = New Recti(0, 0, pixmap.Width, pixmap.Height)
	Local dstRect:Recti = New Recti(x, y, x + pixmap.Width, y + pixmap.Height)
	
	' Clip to canvas bounds
	Local canvasRect:=canvas.RenderBounds
	
	' Early exit if entirely outside
	If Not dstRect.Intersects(canvasRect) Return
	
	' Adjust source rectangle if destination is partially clipped
	If dstRect.Left < canvasRect.Left
		Local dx:Int = canvasRect.Left - dstRect.Left
		srcRect.Left += dx
		dstRect.Left = canvasRect.Left
	Endif
	
	If dstRect.Top < canvasRect.Top
		Local dy:Int = canvasRect.Top - dstRect.Top
		srcRect.Top += dy
		dstRect.Top = canvasRect.Top
	Endif
	
	If dstRect.Right > canvasRect.Right
		Local dx:Int = dstRect.Right - canvasRect.Right
		srcRect.Right -= dx
		dstRect.Right = canvasRect.Right
	Endif
	
	If dstRect.Bottom > canvasRect.Bottom
		Local dy:Int = dstRect.Bottom - canvasRect.Bottom
		srcRect.Bottom -= dy
		dstRect.Bottom = canvasRect.Bottom
	Endif
	
	' Iterate through pixels and draw manually
	Local oldColor:Color = canvas.Color
	
	For Local dy:Int = 0 Until dstRect.Height
		For Local dx:Int = 0 Until dstRect.Width
			Local srcX:Int = srcRect.Left + dx
			Local srcY:Int = srcRect.Top + dy
			Local dstX:Int = dstRect.Left + dx
			Local dstY:Int = dstRect.Top + dy
			
			' Get pixel color from source pixmap
			Local color:Color = pixmap.GetPixel(srcX, srcY)
			
			' Draw pixel to canvas
			canvas.Color = color
			canvas.DrawPoint(dstX, dstY)
		End
	End
	
	' Restore original color
	canvas.Color = oldColor
End

Class PixmapDemoView
	Field canvas:Canvas
	
	' Pixmaps for demonstrations
	Field basicShapesPixmap:Pixmap
	Field gradientPixmap:Pixmap
	Field complexShapesPixmap:Pixmap
	Field bezierCurvesPixmap:Pixmap
	Field animationPixmap:Pixmap
	
	' Tracking variables for animation and interaction
	Field animationTime:Float = 0
	Field mouseX:Float = 0
	Field mouseY:Float = 0
	Field gradientPos:Float = 0.5
	
	Method New(width:Int, height:Int)
		
		' Create pixmaps for each demo section
		basicShapesPixmap = New Pixmap(width/2, height/2)
		gradientPixmap = New Pixmap(width/2, height/2)
		complexShapesPixmap = New Pixmap(width/2, height/2)
		bezierCurvesPixmap = New Pixmap(width/2, height/2)
		animationPixmap = New Pixmap(width, height/3)
		
		' Initial render of static content
		DrawBasicShapes()
		DrawComplexShapes()
	End
	
	Method Render()
		Update()
		Local width:Int = canvas.RenderBounds.Width
		Local height:Int = canvas.RenderBounds.Height
		
		' Clear background with dark tone
		canvas.Color = New Color(0.12, 0.12, 0.15)
		canvas.DrawRect(0, 0, width, height)
		
		' Update dynamic pixmaps
		UpdateGradients()
		UpdateBezierCurves()
		UpdateAnimation()
		
		' Draw all pixmaps to canvas using our custom function
		CanvasDrawPixmap(canvas, basicShapesPixmap, 0, 0)
		CanvasDrawPixmap(canvas, gradientPixmap, width/2, 0)
		CanvasDrawPixmap(canvas, complexShapesPixmap, 0, height/2)
		CanvasDrawPixmap(canvas, bezierCurvesPixmap, width/2, height/2)
		CanvasDrawPixmap(canvas, animationPixmap, 0, height*2/3)
		
		' Draw section labels
		canvas.Color = New Color(1, 1, 1)
		canvas.DrawText("Basic Shapes", 10, 20)
		canvas.DrawText("Gradient Effects", width/2 + 10, 20)
		canvas.DrawText("Complex Shapes & Polygons", 10, height/2 + 20)
		canvas.DrawText("Bezier Curves", width/2 + 10, height/2 + 20)
		canvas.DrawText("Animation & Multi-color Gradients", 10, height*2/3 + 20)
		
		' Instructions
		canvas.Color = New Color(1, 1, 0.7)
		canvas.DrawText("Move mouse to control gradients and curves", 10, height - 30)
	End
	
	Method Update()
		' Update animation time
		animationTime += 1.0/60.0
		If animationTime > 100 Then animationTime = 0
	End
	
	Method OnMouseMove(x:Float, y:Float)
		mouseX = x
		mouseY = y
		
		' Calculate relative gradient position based on mouse X
		gradientPos = Clamp(mouseX / canvas.RenderBounds.Width, 0.0, 1.0)
	End
	
	Method DrawBasicShapes()
		' Clear the pixmap
		basicShapesPixmap.ClearARGB($FF000000)
		
		' Draw some filled and outlined shapes
		basicShapesPixmap.DrawRect(20, 20, 100, 80, New Color(1, 0.3, 0.2, 0.9))
		basicShapesPixmap.DrawRectOutline(20, 20, 100, 80, New Color(1, 1, 1), 2)
		
		basicShapesPixmap.DrawCircle(200, 80, 60, New Color(0.2, 0.6, 1, 0.8))
		basicShapesPixmap.DrawCircleOutline(200, 80, 60, New Color(1, 1, 1), 2)
		
		basicShapesPixmap.DrawTriangle(
			150, 150, 
			200, 220, 
			100, 220, 
			New Color(0.9, 0.8, 0.2))
		
		basicShapesPixmap.DrawTriangleOutline(
			150, 150, 
			200, 220, 
			100, 220, 
			New Color(0.4, 0.4, 0.4), 
			2)
		
		' Draw a thick multi-segment line
		basicShapesPixmap.DrawLine(30, 130, 80, 170, New Color(0, 1, 0.5), 3)
		basicShapesPixmap.DrawLine(80, 170, 130, 130, New Color(0, 1, 0.5), 3)
		basicShapesPixmap.DrawLine(130, 130, 170, 170, New Color(0, 1, 0.5), 3)
		basicShapesPixmap.DrawLine(170, 170, 220, 130, New Color(0, 1, 0.5), 3)
	End
	
	Method UpdateGradients()
		' Clear the pixmap
		gradientPixmap.ClearARGB($FF000000)
		
		' Draw a vertical linear gradient
		gradientPixmap.DrawGradientRect(
			20, 20, 100, 200,
			New Color(1, 0, 0),  ' Red at top
			New Color(0, 0, 1),  ' Blue at bottom
			True)                ' Vertical=true
		
		' Draw a horizontal linear gradient
		gradientPixmap.DrawGradientRect(
			130, 20, 200, 80,
			New Color(1, 1, 0),  ' Yellow at left 
			New Color(0, 1, 0),  ' Green at right
			False)               ' Vertical=false
		
		' Draw a dithered gradient
		gradientPixmap.DrawDitheredGradientRect(
			130, 110, 200, 80,
			New Color(1, 0, 1),  ' Magenta
			New Color(0, 1, 1),  ' Cyan
			False)
		
		' Draw a gradient with arbitrary reference points
		Local startPoint:Vec2f = New Vec2f(130 + 200 * gradientPos, 200)
		Local endPoint:Vec2f = New Vec2f(230, 220)
		
		gradientPixmap.DrawGradientRect(
			130, 200, 200, 80,
			New Color(1, 0.5, 0),
			New Color(0, 0.5, 1),
			startPoint,
			endPoint)
	End
	
	Method DrawComplexShapes()
		' Clear the pixmap
		complexShapesPixmap.ClearARGB($FF000000)
		
		' Draw a quad
		complexShapesPixmap.DrawQuad(
			40, 30,
			120, 40, 
			100, 100,
			20, 90,
			New Color(0.8, 0.2, 0.5, 0.9))
		
		complexShapesPixmap.DrawQuadOutline(
			40, 30,
			120, 40, 
			100, 100,
			20, 90,
			New Color(1, 1, 1),
			2)
		
		' Draw a polygon with even-odd fill rule
		Local polygonPoints:=New Vec2f[](
			New Vec2f(180, 30),
			New Vec2f(220, 50),
			New Vec2f(240, 90),
			New Vec2f(210, 130),
			New Vec2f(170, 120),
			New Vec2f(150, 80))
		
		complexShapesPixmap.DrawPolygon(
			polygonPoints,
			New Color(0.4, 0.7, 0.9, 0.8),
			FILL_EVEN_ODD)
		
		complexShapesPixmap.DrawPolygonOutline(
			polygonPoints,
			New Color(1, 1, 1),
			2)
		
		' Draw a star shape with winding fill rule
		Local starPoints:=New Vec2f[](
			New Vec2f(60, 160),
			New Vec2f(85, 160),
			New Vec2f(100, 140),
			New Vec2f(115, 160),
			New Vec2f(140, 160),
			New Vec2f(120, 180),
			New Vec2f(130, 210),
			New Vec2f(100, 190),
			New Vec2f(70, 210),
			New Vec2f(80, 180))
		
		complexShapesPixmap.DrawPolygon(
			starPoints,
			New Color(1, 0.8, 0.2, 0.9),
			FILL_WINDING)
		
		complexShapesPixmap.DrawPolygonOutline(
			starPoints,
			New Color(0.4, 0.3, 0.1),
			2)
		
		' Draw a gradient triangle
		complexShapesPixmap.DrawGradientTriangle(
			170, 170,
			230, 190,
			190, 230,
			New Color(1, 0, 0),
			New Color(0, 1, 0),
			New Color(0, 0, 1))
	End
	
	Method UpdateBezierCurves()
		Local width:Int = canvas.RenderBounds.Width
		Local height:Int = canvas.RenderBounds.Height
		
		' Clear the pixmap
		bezierCurvesPixmap.ClearARGB($FF000000)
		
		' Draw a quadratic Bezier curve
		bezierCurvesPixmap.DrawQuadraticBezier(
			30, 50,
			mouseX - width/2, mouseY - height/2,
			220, 50,
			New Color(1, 1, 1),
			3)
		
		' Draw a cubic Bezier curve
		bezierCurvesPixmap.DrawCubicBezier(
			30, 120,
			70, 50 + Sin(animationTime * 5) * 30,
			180, 190 + Sin(animationTime * 3) * 30,
			220, 120,
			New Color(0, 1, 0.5),
			3)
		
		' Draw a gradient quadratic bezier
		bezierCurvesPixmap.DrawGradientQuadraticBezier(
			30, 200,
			125, 120 + Sin(animationTime * 4) * 40,
			220, 200,
			New Color(1, 0.2, 0.2),
			New Color(0.2, 0.2, 1),
			4)
		
		' Draw a multi-color gradient cubic bezier
		Local colors:=New Color[](
			New Color(1, 0, 0),
			New Color(1, 1, 0),
			New Color(0, 1, 0),
			New Color(0, 0, 1))
		
		Local positions:=New Float[](
			0.0,
			0.3,
			0.7,
			1.0)
		
		bezierCurvesPixmap.DrawMultiGradientCubicBezier(
			30, 190,
			90, 220 + Sin(animationTime * 2) * 20,
			160, 220 + Sin(animationTime * 2 + 2) * 20,
			220, 190,
			colors,
			positions,
			5)
	End
	
	Method UpdateAnimation()
		Local width:Int = canvas.RenderBounds.Width
		
		' Clear the pixmap
		animationPixmap.ClearARGB($FF000000)
		
		' Create a wave of circles with gradient colors
		For Local i:Float = 0 Until 20
			Local x:Float = (i / 20) * width
			Local y:Float = animationPixmap.Height / 2 + Sin(animationTime * 3 + i * 0.5) * 40
			Local radius:Float = 10 + Sin(animationTime + i) * 5
			
			Local hue:Float = (animationTime * 0.2 + i * 0.1) Mod 1.0
			Local color:Color = HsvToRgb(hue, 0.8, 0.9)
			
			animationPixmap.DrawCircle(x, y, radius, color)
		End
		
		' Draw an animated multi-color gradient line
		Local lineColors:=New Color[](
			HsvToRgb((animationTime * 0.1) Mod 1.0, 0.9, 0.9),
			HsvToRgb((animationTime * 0.1 + 0.33) Mod 1.0, 0.9, 0.9),
			HsvToRgb((animationTime * 0.1 + 0.66) Mod 1.0, 0.9, 0.9))
		
		Local linePositions:=New Float[](
			0.0,
			0.5,
			1.0)
		
		' Make a wavy path with the multi-gradient line
		For Local i:Float = 0 Until animationPixmap.Width - 20 Step 20
			Local x1:Float = i
			Local y1:Float = 30 + Sin(animationTime * 2 + i * 0.02) * 15
			Local x2:Float = i + 20
			Local y2:Float = 30 + Sin(animationTime * 2 + (i + 20) * 0.02) * 15
			
			animationPixmap.DrawMultiGradientLine(
				x1, y1,
				x2, y2,
				lineColors,
				linePositions,
				3)
		End
		
		' Draw a rainbow circular gradient
		Local centerX:Float = width / 2
		Local centerY:Float = animationPixmap.Height - 50
		Local outerColor:Color = HsvToRgb(animationTime * 0.3 Mod 1.0, 0.9, 0.9)
		Local innerColor:Color = New Color(1, 1, 1)
		
		animationPixmap.DrawGradientCircle(
			centerX,
			centerY,
			40 + Sin(animationTime * 3) * 10,
			innerColor,
			outerColor)
	End
	
	' Helper to convert HSV to RGB color
	Method HsvToRgb:Color(h:Float, s:Float, v:Float)
		h = h Mod 1.0
		
		Local i:Int = Int(h * 6)
		Local f:Float = h * 6 - i
		Local p:Float = v * (1 - s)
		Local q:Float = v * (1 - f * s)
		Local t:Float = v * (1 - (1 - f) * s)
		
		Local r:Float, g:Float, b:Float
		
		Select i Mod 6
			Case 0
				r = v; g = t; b = p
			Case 1
				r = q; g = v; b = p
			Case 2
				r = p; g = v; b = t
			Case 3
				r = p; g = q; b = v
			Case 4
				r = t; g = p; b = v
			Case 5
				r = v; g = p; b = q
		End
		
		Return New Color(r, g, b)
	End
	
	Method Clamp:Float(value:Float, min:Float, max:Float)
		If value < min Then Return min
		If value > max Then Return max
		Return value
	End
End

Class PixmapExtensionsTest Extends Window
	Field view:PixmapDemoView

	Method New( title:String="Simple mojo app",width:Int=800,height:Int=480,flags:WindowFlags=Null )

		Super.New("Pixmap Extensions Showcase", 800, 600, flags)
		
		' Create our demo view with the window canvas
		view = New PixmapDemoView(800, 600)
	End
	
	Method OnRender(canvas:Canvas) Override
		' Request render for next frame
		App.RequestRender()
		view.canvas=canvas
		
		' Render our demo view
		view.Render()
	End

	Method OnKeyEvent( event:KeyEvent ) Override
	
		If event.Type=EventType.KeyDown
			Select event.Key
			Case Key.Up
				If Minimized Restore() Else Maximize()
			Case Key.Down
				If Maximized Restore() Else Minimize()
			End
		Endif
	End
	
	Method OnMouseEvent(event:MouseEvent) Override
		If event.Type = EventType.MouseMove
			view.mouseX=MouseLocation.X
			view.mouseY=MouseLocation.Y
		Endif
	End
End

Function Main()
	New AppInstance
	New PixmapExtensionsTest
	App.Run()
End