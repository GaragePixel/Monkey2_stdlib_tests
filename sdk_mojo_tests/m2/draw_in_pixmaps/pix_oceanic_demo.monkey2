' Oceanic Pixmap Demo
' Implementation by iDkP from GaragePixel
' 2025-03-24 Aida 4
'
' Purpose:
' Demonstrates advanced pixmap drawing techniques with an oceanic theme,
' showcasing dynamic gradients, blending effects, and interactive animations
' that respond to mouse movement.
'
' Functionality:
' - Underwater scene with dynamic lighting effects
' - Interactive wave patterns that respond to mouse movement
' - Bubble animations with physics-based trajectories
' - Deep sea gradient transitions with depth perception
' - Fish silhouettes with dynamic motion patterns
' - Coral reef formations with procedural coloration
' - Blended light rays penetrating the water's surface
'
' Notes:
' This demonstration uses pixmap-based rendering techniques rather than
' direct canvas drawing to showcase the advantages of pre-rendering complex
' visuals. The separation of rendering and display logic allows for better
' performance even with complex visual effects, as much of the heavy
' computational work happens when creating the pixmaps rather than during
' the frame rendering process. This approach is particularly useful for
' creating rich visual effects on platforms with limited resources.
'
' Technical advantages:
' Pre-computing visual elements into pixmaps provides a significant
' optimization for complex scenes that would otherwise require excessive
' per-frame calculations. The oceanic theme allows for natural-looking
' motion using simple mathematical models (sine waves, perlin noise), while
' the layered compositing approach demonstrates how to achieve depth and
' atmosphere without relying on 3D graphics capabilities. The interactive
' elements showcase how even pre-rendered pixmaps can be highly responsive
' to user input when properly implemented.

#Import "<stdlib>"
#Import "<sdk_mojo>"

Using stdlib..
Using sdk_mojo..

' Global constants for scene configuration
Const WATER_LAYERS:Int = 4
Const NUM_BUBBLES:Int = 35
Const NUM_FISH:Int = 7
Const MAX_LIGHT_RAYS:Int = 5
Const WAVE_FREQUENCY:Float = 0.5

' Fill rule constants
Const FILL_EVEN_ODD:Int = 0
Const FILL_WINDING:Int = 1

' Global color palette for oceanic theme
Global waterColors:Color[] = New Color[](
	New Color(0.05, 0.05, 0.2, 1.0),  ' Deep water
	New Color(0.0, 0.15, 0.3, 1.0),   ' Mid-depth water
	New Color(0.1, 0.2, 0.4, 0.25),   ' Shallow water
	New Color(0.2, 0.5, 0.8, 0.1))    ' Surface water

Global coralColors:Color[] = New Color[](
	New Color(0.9, 0.2, 0.3, 1.0),    ' Red coral
	New Color(0.9, 0.6, 0.2, 1.0),    ' Orange coral
	New Color(0.9, 0.9, 0.3, 1.0),    ' Yellow coral
	New Color(0.7, 0.3, 0.7, 1.0),    ' Purple coral
	New Color(0.3, 0.7, 0.4, 1.0))    ' Green coral

' Function to draw a pixmap onto a canvas preserving transparency
Function DrawPixmapWithAlpha(canvas:Canvas, pixmap:Pixmap, x:Int, y:Int)
	Local oldColor:Color = canvas.Color
	
	For Local py:Int = 0 Until pixmap.Height
		Local canvasY:Int = y + py
		If canvasY < 0 Or canvasY >= canvas.Viewport.Height Then Continue
		
		For Local px:Int = 0 Until pixmap.Width
			Local canvasX:Int = x + px
			If canvasX < 0 Or canvasX >= canvas.Viewport.Width Then Continue
			
			Local color:Color = pixmap.GetPixel(px, py)
			If color.a > 0.001
				canvas.Color = color
				canvas.DrawPoint(canvasX, canvasY)
			Endif
		Next
	Next
	
	canvas.Color = oldColor
End
	
' Underwater scene view class
Class OceanView
	Field canvas:Canvas
	Field width:Int
	Field height:Int
	Field appFPS:Int
	
	' Combined pixmap used as a backbuffer for blending
	Field backbufferPixmap:Pixmap
	
	' Pixmaps for different elements
	Field backgroundPixmap:Pixmap
	Field waterLayersPixmap:Pixmap
	Field bubblePixmap:Pixmap
	Field fishPixmap:Pixmap
	Field coralReefPixmap:Pixmap
	Field lightRaysPixmap:Pixmap
	
	' Animation and interaction state
	Field time:Float = 0.0
	Field mouseX:Float = 0.0
	Field mouseY:Float = 0.0
	Field prevMouseX:Float = 0.0
	Field prevMouseY:Float = 0.0
	Field mouseMovementX:Float = 0.0
	Field mouseMovementY:Float = 0.0
	
	' Bubble positions and properties
	Field bubbleX:Float[] = New Float[NUM_BUBBLES]
	Field bubbleY:Float[] = New Float[NUM_BUBBLES]
	Field bubbleSize:Float[] = New Float[NUM_BUBBLES]
	Field bubbleSpeed:Float[] = New Float[NUM_BUBBLES]
	Field bubblePhase:Float[] = New Float[NUM_BUBBLES]
	
	' Fish properties
	Field fishX:Float[] = New Float[NUM_FISH]
	Field fishY:Float[] = New Float[NUM_FISH]
	Field fishSize:Float[] = New Float[NUM_FISH]
	Field fishSpeed:Float[] = New Float[NUM_FISH]
	Field fishDirection:Float[] = New Float[NUM_FISH]
	
	' Light ray properties
	Field rayX:Float[] = New Float[MAX_LIGHT_RAYS]
	Field rayWidth:Float[] = New Float[MAX_LIGHT_RAYS]
	Field rayIntensity:Float[] = New Float[MAX_LIGHT_RAYS]
	
	Method New(width:Int, height:Int)
		Self.width = width
		Self.height = height
		
		' Create pixmaps for various elements
		backbufferPixmap = New Pixmap(width, height)
		backgroundPixmap = New Pixmap(width, height)
		waterLayersPixmap = New Pixmap(width, height)
		bubblePixmap = New Pixmap(width, height)
		fishPixmap = New Pixmap(width, height)
		coralReefPixmap = New Pixmap(width, height)
		lightRaysPixmap = New Pixmap(width, height)
		
		' Initialize scene elements
		InitBubbles()
		InitFish()
		InitLightRays()
		
		' Create static elements
		CreateBackground()
		CreateCoralReef()
	End
	
	Method Render()
		If canvas = Null Then Return
		
		' Update the backbuffer with all elements
		backbufferPixmap.ClearARGB($FF000000)
		
		' Copy background to backbuffer
		CopyPixmap(backgroundPixmap, backbufferPixmap, 0, 0)
		
		' Update dynamic elements
		UpdateWaterLayers()
		UpdateLightRays()
		UpdateBubbles()
		UpdateFish()
		
		' Blend dynamic elements onto backbuffer
		BlendPixmap(lightRaysPixmap, backbufferPixmap, 0, 0)
		BlendPixmap(waterLayersPixmap, backbufferPixmap, 0, 0)
		BlendPixmap(coralReefPixmap, backbufferPixmap, 0, 0)
		BlendPixmap(fishPixmap, backbufferPixmap, 0, 0)
		BlendPixmap(bubblePixmap, backbufferPixmap, 0, 0)
		
		' Draw backbuffer to canvas
		DrawPixmapWithAlpha(canvas, backbufferPixmap, 0, 0)
		
		' Draw some text information
		canvas.Color = New Color(1, 1, 1)
		canvas.DrawText("Mouse Position: " + Int(mouseX) + ", " + Int(mouseY), 10, 20)
		canvas.DrawText("Time: " + Int(time), 10, 40)
		'canvas.DrawText("FPS: " + App.FPS, 10, 60) 'For a not very clear reason, huge FPS drop like that
		canvas.DrawText("FPS: " + appFPS, 10, 60) 'For a not very clear reason, huge FPS drop like that
		canvas.DrawText("Move mouse to interact with water", 10, height - 20)
	End
	
	' Copy pixmap data directly (no alpha blending)
	Method CopyPixmap(source:Pixmap, dest:Pixmap, x:Int, y:Int)
		For Local py:Int = 0 Until source.Height
			Local destY:Int = y + py
			If destY < 0 Or destY >= dest.Height Then Continue
			
			For Local px:Int = 0 Until source.Width
				Local destX:Int = x + px
				If destX < 0 Or destX >= dest.Width Then Continue
				
				dest.SetPixel(destX, destY, source.GetPixel(px, py))
			Next
		Next
	End
	
	' Blend pixmap data with alpha
	Method BlendPixmap(source:Pixmap, dest:Pixmap, x:Int, y:Int)
		For Local py:Int = 0 Until source.Height
			Local destY:Int = y + py
			If destY < 0 Or destY >= dest.Height Then Continue
			
			For Local px:Int = 0 Until source.Width
				Local destX:Int = x + px
				If destX < 0 Or destX >= dest.Width Then Continue
				
				Local srcColor:Color = source.GetPixel(px, py)
				If srcColor.a > 0.001
					Local destColor:Color = dest.GetPixel(destX, destY)
					Local blendedColor:Color = BlendColors(destColor, srcColor)
					dest.SetPixel(destX, destY, blendedColor)
				Endif
			Next
		Next
	End
	
	' Blend two colors using alpha
	Method BlendColors:Color(back:Color, front:Color)
		Local alpha:Float = front.a
		Local invAlpha:Float = 1.0 - alpha
		
		Return New Color(
			(back.r * invAlpha) + (front.r * alpha),
			(back.g * invAlpha) + (front.g * alpha),
			(back.b * invAlpha) + (front.b * alpha),
			(back.a + front.a) * invAlpha)
	End
	
	Method Update(delta:Float)
		' Update animation time
		time += delta
		
		' Calculate mouse movement deltas
		mouseMovementX = mouseX - prevMouseX
		mouseMovementY = mouseY - prevMouseY
		
		' Store current mouse position for next frame
		prevMouseX = mouseX
		prevMouseY = mouseY
	End
	
	Method OnMouseMove(x:Float, y:Float)
		mouseX = x
		mouseY = y
	End
	
	' Initialize bubble properties
	Method InitBubbles()
		For Local i:Int = 0 Until NUM_BUBBLES
			ResetBubble(i)
			' Start bubbles at random heights
			bubbleY[i] = Rnd(0, height)
		Next
	End
	
	' Reset a bubble that has gone off-screen
	Method ResetBubble(index:Int)
		bubbleX[index] = Rnd(0, width)
		bubbleY[index] = height + Rnd(10, 50)
		bubbleSize[index] = Rnd(2, 15)
		bubbleSpeed[index] = Rnd(20, 60)
		bubblePhase[index] = Rnd(0, TwoPi)
	End
	
	' Initialize fish properties
	Method InitFish()
		For Local i:Int = 0 Until NUM_FISH
			fishX[i] = Rnd(0, width)
			fishY[i] = Rnd(height * 0.3, height * 0.7)
			fishSize[i] = Rnd(15, 40)
			fishSpeed[i] = Rnd(10, 30)
			
			' Use proper Monkey2 conditional syntax
			If Rnd(0, 1) < 0.5
				fishDirection[i] = -1
			Else
				fishDirection[i] = 1
			Endif
		Next
	End
	
	' Initialize light ray properties
	Method InitLightRays()
		For Local i:Int = 0 Until MAX_LIGHT_RAYS
			rayX[i] = Rnd(width * 0.2, width * 0.8)
			rayWidth[i] = Rnd(30, 80)
			rayIntensity[i] = Rnd(0.1, 0.4)
		Next
	End
	
	' Create static background gradient
	Method CreateBackground()
		backgroundPixmap.ClearARGB($FF000000)
		
		' Create deep blue ocean gradient background
		For Local y:Int = 0 Until height
			Local depth:Float = Float(y) / height
			Local r:Float = Lerp(0.0, 0.05, depth)
			Local g:Float = Lerp(0.0, 0.1, depth)
			Local b:Float = Lerp(0.1, 0.2, depth)
			Local color:Color = New Color(r, g, b)
			
			For Local x:Int = 0 Until width
				backgroundPixmap.SetPixel(x, y, color)
			Next
		Next
		
		' Add some subtle noise texture
		For Local i:Int = 0 Until width * height / 20
			Local x:Int = Rnd(width)
			Local y:Int = Rnd(height)
			Local brightness:Float = Rnd(0.01, 0.03)
			Local pixel:Color = backgroundPixmap.GetPixel(x, y)
			backgroundPixmap.SetPixel(x, y, New Color(
				pixel.r + brightness,
				pixel.g + brightness,
				pixel.b + brightness))
		Next
	End
	
	' Create coral reef formations
	Method CreateCoralReef()
		coralReefPixmap.ClearARGB($00000000)
		
		' Draw seafloor base
		For Local x:Int = 0 Until width
			Local floorHeight:Int = height - 40 + Sin(x * 0.05) * 15
			For Local y:Int = floorHeight Until height
				coralReefPixmap.SetPixel(x, y, New Color(0.2, 0.18, 0.15))
			Next
		Next
		
		' Draw coral formations
		For Local i:Int = 0 Until 20
			Local x:Int = Rnd(width)
			Local baseY:Int = height - 40 + Sin(x * 0.05) * 15
			Local coralHeight:Int = Rnd(20, 60)
			Local coralWidth:Int = Rnd(15, 40)
			Local colorIndex:Int = Int(Rnd(coralColors.Length))
			
			' Draw branching coral structure
			DrawCoral(coralReefPixmap, x, baseY, coralWidth, coralHeight, coralColors[colorIndex])
		Next
		
		' Add some seaweed
		For Local i:Int = 0 Until 30
			Local x:Int = Rnd(width)
			Local baseY:Int = height - 40 + Sin(x * 0.05) * 15
			Local weedHeight:Int = Rnd(30, 100)
			
			DrawSeaweed(coralReefPixmap, x, baseY, weedHeight)
		Next
	End
	
	' Draw a coral formation
	Method DrawCoral(pixmap:Pixmap, x:Int, y:Int, width:Int, height:Int, color:Color)
		' Draw main coral structure
		For Local cy:Int = 0 Until height
			Local radius:Float = width * (1.0 - Float(cy) / height) * 0.8
			Local ypos:Int = y - cy
			
			If ypos < 0 Then Continue
			
			For Local cx:Int = -radius Until radius
				Local xpos:Int = x + cx
				If xpos < 0 Or xpos >= pixmap.Width Then Continue
				
				Local dist:Float = Abs(cx) / radius
				Local alpha:Float = 1.0 - dist * dist
				
				If alpha > 0.2
					Local pixelColor:Color = New Color(
						color.r * (0.8 + Rnd(0.2)),
						color.g * (0.8 + Rnd(0.2)),
						color.b * (0.8 + Rnd(0.2)),
						alpha)
					pixmap.SetPixel(xpos, ypos, pixelColor)
				Endif
			Next
		Next
		
		' Add some branches if this is a large coral
		If width > 25
			For Local i:Int = 0 Until 3
				Local branchX:Int = x + Rnd(-width/2, width/2)
				Local branchY:Int = y - Rnd(height * 0.3, height * 0.6)
				Local branchWidth:Int = width * 0.6
				Local branchHeight:Int = height * 0.4
				
				DrawCoral(pixmap, branchX, branchY, branchWidth, branchHeight, color)
			Next
		Endif
	End
	
	' Draw swaying seaweed
	Method DrawSeaweed(pixmap:Pixmap, x:Int, baseY:Int, height:Int)
		Local segments:Int = height / 5
		Local color:Color = New Color(0.1, 0.5, 0.2, 0.9)
		Local thickness:Float = Rnd(2, 5)
		
		For Local i:Int = 0 Until segments
			Local y1:Int = baseY - i * 5
			Local y2:Int = baseY - (i + 1) * 5
			
			Local offset:Float = Sin(i * 0.3) * thickness * 3
			Local x1:Int = x + offset
			Local x2:Int = x + Sin((i + 1) * 0.3) * thickness * 3
			
			DrawThickLine(pixmap, x1, y1, x2, y2, color, thickness)
		Next
	End
	
	' Update water layers with wave animation
	Method UpdateWaterLayers()
		waterLayersPixmap.ClearARGB($00000000)
		
		For Local layer:Int = 0 Until WATER_LAYERS
			Local yOffset:Float = layer * height / WATER_LAYERS
			Local layerHeight:Float = height / WATER_LAYERS
			Local waveAmplitude:Float = (WATER_LAYERS - layer) * 5
			Local waveSpeed:Float = (WATER_LAYERS - layer) * 0.5
			
			' Mouse influence on waves
			Local mouseInfluence:Float = (mouseY / height) * 20 * (WATER_LAYERS - layer)
			
			For Local x:Int = 0 Until width
				' Calculate wave height using multiple sine waves
				Local wave1:Float = Sin((x * WAVE_FREQUENCY * 0.01) + (time * waveSpeed)) * waveAmplitude
				Local wave2:Float = Sin((x * WAVE_FREQUENCY * 0.02) + (time * waveSpeed * 1.5)) * (waveAmplitude * 0.5)
				Local wave3:Float = Sin((x * WAVE_FREQUENCY * 0.03) + (time * waveSpeed * 0.7)) * (waveAmplitude * 0.3)
				
				' Mouse position influences wave pattern
				Local distToMouse:Float = Abs(x - mouseX) / 100.0
				Local mouseWave:Float = Sin(distToMouse + time) * mouseInfluence * Max(0.0, 1.0 - distToMouse * 0.1)
				mouseWave *= mouseMovementX * 0.1
				
				Local waveHeight:Float = wave1 + wave2 + wave3 + mouseWave
				
				For Local y:Int = 0 Until layerHeight + Abs(waveHeight) + 1
					Local actualY:Int = yOffset + y + waveHeight
					If actualY < 0 Or actualY >= height Then Continue
					
					' Calculate color based on depth and position
					Local depthFactor:Float = Float(y) / layerHeight
					Local alpha:Float = Lerp(0.1, 0.4, depthFactor) * (1.0 - Float(layer) / WATER_LAYERS)
					
					If alpha > 0.01
						waterLayersPixmap.SetPixel(x, actualY, New Color(
							waterColors[layer].r,
							waterColors[layer].g,
							waterColors[layer].b,
							alpha))
					Endif
				Next
			Next
		Next
	End
	
	' Update light rays animation
	Method UpdateLightRays()
		lightRaysPixmap.ClearARGB($00000000)
		
		' Number of rays depends on mouse y position
		Local activeRays:Int = 2 + Int((1.0 - mouseY / height) * MAX_LIGHT_RAYS)
		activeRays = Clamp(activeRays, 1, MAX_LIGHT_RAYS)
		
		For Local i:Int = 0 Until activeRays
			' Animate ray position
			rayX[i] += Sin(time * 0.5 + i) * 0.5
			
			' Fix ray position if it moves off-screen
			If rayX[i] < 0 Then rayX[i] = width
			If rayX[i] >= width Then rayX[i] = 0
			
			' Ray intensity pulses over time
			Local intensity:Float = rayIntensity[i] * (0.6 + Sin(time * 0.7 + i * 1.3) * 0.4)
			
			' Draw the light ray as a gradient
			Local rayTop:Int = 0
			Local rayBottom:Int = height * 0.7 + Sin(time * 0.3 + i) * height * 0.1
			
			For Local y:Int = rayTop Until rayBottom
				Local progress:Float = Float(y - rayTop) / (rayBottom - rayTop)
				Local expandFactor:Float = Lerp(0.2, 2.0, progress)
				Local rayWidth:Float = Self.rayWidth[i] * expandFactor
				
				Local alpha:Float = intensity * (1.0 - progress * progress)
				If alpha < 0.01 Then Continue
				
				For Local x:Int = rayX[i] - rayWidth/2 Until rayX[i] + rayWidth/2
					If x < 0 Or x >= Self.width Then Continue
					
					Local distFromCenter:Float = Abs(x - rayX[i]) / (rayWidth/2)
					Local pixelAlpha:Float = alpha * (1.0 - distFromCenter * distFromCenter)
					
					If pixelAlpha > 0.01
						Local color:Color = New Color(0.5, 0.5, 0.9, pixelAlpha)
						lightRaysPixmap.SetPixel(x, y, color)
					Endif
				Next
			Next
		Next
	End
	
	' Update bubble positions and drawing
	Method UpdateBubbles()
		bubblePixmap.ClearARGB($00000000)
		
		For Local i:Int = 0 Until NUM_BUBBLES
			' Update bubble position
			bubbleY[i] -= bubbleSpeed[i] * 0.02
			bubbleX[i] += Sin(time + bubblePhase[i]) * 0.5
			
			' Reset bubble if it goes off the top
			If bubbleY[i] < -bubbleSize[i]
				ResetBubble(i)
			Endif
			
			' Draw the bubble
			DrawBubble(bubblePixmap, bubbleX[i], bubbleY[i], bubbleSize[i])
		Next
	End
	
	' Draw a single bubble
	Method DrawBubble(pixmap:Pixmap, x:Float, y:Float, size:Float)
		Local radius:Int = size
		Local shine:Float = 0.8 + Sin(time * 2) * 0.2
		
		For Local dy:Int = -radius Until radius
			For Local dx:Int = -radius Until radius
				Local distance:Float = Sqrt(dx*dx + dy*dy)
				If distance > radius Then Continue
				
				Local px:Int = x + dx
				Local py:Int = y + dy
				
				If px < 0 Or px >= pixmap.Width Or py < 0 Or py >= pixmap.Height Then Continue
				
				' Calculate bubble transparency
				Local alpha:Float = 0.1 + (1.0 - distance / radius) * 0.6
				
				' Add shine effect
				If dx > 0 And dy < 0 And distance < radius * 0.7
					alpha += (radius * 0.7 - distance) / (radius * 0.7) * shine
				Endif
				
				pixmap.SetPixel(px, py, New Color(0.9, 0.95, 1.0, alpha))
			Next
		Next
	End
	
	' Update fish positions and drawing
	Method UpdateFish()
		fishPixmap.ClearARGB($00000000)
		
		For Local i:Int = 0 Until NUM_FISH
			' Update fish position
			fishX[i] += fishSpeed[i] * 0.03 * fishDirection[i]
			fishY[i] += Sin(time * 0.6 + i) * 0.3
			
			' Reverse direction if fish hits edge of screen
			If fishX[i] < -fishSize[i] * 2
				fishDirection[i] = 1
			Elseif fishX[i] > width + fishSize[i] * 2
				fishDirection[i] = -1
			Endif
			
			' Draw the fish
			DrawFish(fishPixmap, fishX[i], fishY[i], fishSize[i], fishDirection[i])
		Next
	End
	
	' Draw a single fish
	Method DrawFish(pixmap:Pixmap, x:Float, y:Float, size:Float, direction:Float)
		' Fish body
		Local bodyPoints:Vec2f[] = New Vec2f[](
			New Vec2f(x, y),
			New Vec2f(x + size * direction, y - size / 2),
			New Vec2f(x + size * 2 * direction, y),
			New Vec2f(x + size * direction, y + size / 2))
			
		' Fish tail animation
		Local tailWag:Float = Sin(time * 5) * 5
		Local tailPoints:Vec2f[] = New Vec2f[](
			New Vec2f(x, y - size / 3),
			New Vec2f(x - size * direction, y - size / 2 + tailWag),
			New Vec2f(x - size * 1.5 * direction, y),
			New Vec2f(x - size * direction, y + size / 2 + tailWag),
			New Vec2f(x, y + size / 3))
			
		' Draw fish parts
		Local bodyColor:Color = New Color(0.8, 0.6, 0.2, 0.8)
		Local outlineColor:Color = New Color(0.0, 0.0, 0.0, 0.5)
		
		FillPolygon(pixmap, bodyPoints, bodyColor)
		FillPolygon(pixmap, tailPoints, bodyColor)
		
		' Fish eye
		Local eyeX:Int = x + size * 0.7 * direction
		Local eyeY:Int = y - size * 0.15
		Local eyeSize:Int = Max(2.0, size * 0.15)
		
		For Local dy:Int = -eyeSize Until eyeSize
			For Local dx:Int = -eyeSize Until eyeSize
				If dx*dx + dy*dy > eyeSize*eyeSize Then Continue
				
				Local px:Int = eyeX + dx
				Local py:Int = eyeY + dy
				
				If px < 0 Or px >= pixmap.Width Or py < 0 Or py >= pixmap.Height Then Continue
				
				pixmap.SetPixel(px, py, New Color(0.9, 0.95, 1.0, 0.9))
			Next
		Next
		
		' Fish eye pupil
		Local pupilX:Int = eyeX + eyeSize * 0.3 * direction
		Local pupilY:Int = eyeY
		Local pupilSize:Int = Max(1.0, eyeSize * 0.5)
		
		For Local dy:Int = -pupilSize Until pupilSize
			For Local dx:Int = -pupilSize Until pupilSize
				If dx * dx + dy * dy > pupilSize * pupilSize Then Continue
				
				Local px:Int = pupilX + dx
				Local py:Int = pupilY + dy
				
				If px < 0 Or px >= pixmap.Width Or py < 0 Or py >= pixmap.Height Then Continue
				
				pixmap.SetPixel(px, py, New Color(0.0, 0.0, 0.0, 0.9))
			Next
		Next
	End
	
	' Fill a polygon with a color
	Method FillPolygon(pixmap:Pixmap, points:Vec2f[], color:Color, fillRule:Int = FILL_EVEN_ODD)
		' Find bounds of the polygon
		Local minX:Int = pixmap.Width
		Local minY:Int = pixmap.Height
		Local maxX:Int = 0
		Local maxY:Int = 0
		
		For Local p:= Eachin points
			minX = Min(minX, Int(p.x))
			minY = Min(minY, Int(p.y))
			maxX = Max(maxX, Int(p.x))
			maxY = Max(maxY, Int(p.y))
		Next
		
		' Clip bounds to pixmap dimensions
		minX = Max(0, minX)
		minY = Max(0, minY)
		maxX = Min(pixmap.Width - 1, maxX)
		maxY = Min(pixmap.Height - 1, maxY)
		
		' Fill the polygon using point-in-polygon test
		For Local y:Int = minY Until maxY + 1
			For Local x:Int = minX Until maxX + 1
				If PointInPolygon(x, y, points, fillRule)
					pixmap.SetPixel(x, y, color)
				Endif
			Next
		Next
	End
	
	' Test if a point is inside a polygon
	Method PointInPolygon:Bool(x:Int, y:Int, points:Vec2f[], fillRule:Int)
		Local inside:Bool = False
		Local count:Int = 0
		
		For Local i:Int = 0 Until points.Length
			Local j:Int = (i + 1) Mod points.Length
			
			If ((points[i].y > y) <> (points[j].y > y)) And
			   (x < (points[j].x - points[i].x) * (y - points[i].y) / (points[j].y - points[i].y) + points[i].x)
				inside = Not inside
				count += 1
			Endif
		Next
		
		' Use different fill rules
		If fillRule = FILL_EVEN_ODD
			Return inside
		Else ' FILL_WINDING
			Return count Mod 2 = 1
		Endif
	End
	
	' Draw a thick line
	Method DrawThickLine(pixmap:Pixmap, x1:Int, y1:Int, x2:Int, y2:Int, color:Color, thickness:Float)
		Local dx:Float = x2 - x1
		Local dy:Float = y2 - y1
		Local dist:Float = Sqrt(dx*dx + dy*dy)
		
		If dist < 0.01 Then Return
		
		' Normalize direction vector
		dx /= dist
		dy /= dist
		
		' Perpendicular direction
		Local px:Float = -dy
		Local py:Float = dx
		
		' Half thickness
		Local hw:Float = thickness / 2
		
		' Define the four corners of the thick line
		Local points:Vec2f[] = New Vec2f[](
			New Vec2f(x1 + px * hw, y1 + py * hw),
			New Vec2f(x2 + px * hw, y2 + py * hw),
			New Vec2f(x2 - px * hw, y2 - py * hw),
			New Vec2f(x1 - px * hw, y1 - py * hw))
			
		' Fill the polygon
		FillPolygon(pixmap, points, color)
	End
	
	' Linear interpolation helper
	Method Lerp:Float(a:Float, b:Float, t:Float)
		Return a + (b - a) * t
	End
	
	' Clamp a value between min and max
	Method Clamp:Int(value:Int, min:Int, max:Int)
		If value < min Then Return min
		If value > max Then Return max
		Return value
	End
End

' Main application window
Class OceanicPixmapDemo Extends Window
	Field oceanView:OceanView
	Field lastTime:Double
	
	Method New()
		Super.New("Oceanic Pixmap Demo", 800, 600, WindowFlags.Resizable)
		
		oceanView = New OceanView(800, 600)
		lastTime = Millisecs() / 1000.0
	End
	
	Method OnRender(canvas:Canvas) Override
		' Set the canvas for the ocean view
		oceanView.canvas = canvas
		
		' Calculate delta time
		Local currentTime:Double = Millisecs() / 1000.0
		Local delta:Float = Float(currentTime - lastTime)
		lastTime = currentTime
		
		' Update scene
		oceanView.Update(delta)
		
		' Render scene
		oceanView.Render()
		
		' Request next frame
		App.RequestRender()
		oceanView.appFPS=App.FPS 'passed from the app to the scene object, no more FPS drop!
		'Note: Maybe it's because the pointers needs to traverse the whole app hierarchie.
		'Passing the FPS from the App's Window to a object that will stacks a draw op is
		'more short. On a low-end PC from 2015, the FPS's value should be around ~10.
		'But the scene has many transparency and blending operations. Much more than
		'older dos games. About the FPS value, after all, it's nearly CPU rendering only!
		'(the "frontbuffer" and the text is rendered via gfx acceleration).
	End
	
	Method OnMouseEvent(event:MouseEvent) Override
		If event.Type = EventType.MouseMove
			oceanView.OnMouseMove(MouseLocation.X, MouseLocation.Y)
		Endif
	End
End

Function Main()
	New AppInstance
	New OceanicPixmapDemo
	App.Run()
End