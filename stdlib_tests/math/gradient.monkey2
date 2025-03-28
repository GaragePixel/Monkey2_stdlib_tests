' =======================================================
' Gradient Test Program
' Implementation by iDkP from GaragePixel
' 2025-03-28 (Aida 4)
' =======================================================

#Import "<stdlib>"
Using stdlib..

Function Main()
	Print "Gradient Test - by GaragePixel (2025)"
	Print "-----------------------------------"
	
	' Test simple 2-color gradient
	Local red:Color = New Color(1, 0, 0)
	Local blue:Color = New Color(0, 0, 1)
	Local greenInt:Int = $FF00FF00  ' Pure green (full opacity)
	Local yellowInt:Int = $FFFFFF00 ' Yellow (full opacity)
	
	' Create color-based gradient
	Local gradC:= New Gradient<Color>(red, blue)
	gradC.A = New Vec2f(0, 0)
	gradC.B = New Vec2f(100, 0)
	
	Print "Color Gradient Test:"
	Print "  Start: " + red.ToString()
	Print "  End: " + blue.ToString()
	
	' Sample at different positions
	Print "  Sampling at t=0.0: " + gradC.Sample(0.0).ToString()
	Print "  Sampling at t=0.25: " + gradC.Sample(0.25).ToString()
	Print "  Sampling at t=0.5: " + gradC.Sample(0.5).ToString()
	Print "  Sampling at t=0.75: " + gradC.Sample(0.75).ToString()
	Print "  Sampling at t=1.0: " + gradC.Sample(1.0).ToString()
	
	' Test with 2D positions
	Print "  At position (0,0): " + gradC.GetColor(0, 0).ToString()
	Print "  At position (50,0): " + gradC.GetColor(50, 0).ToString()
	Print "  At position (100,0): " + gradC.GetColor(100, 0).ToString()
	
	Print ""
	
	' Test integer-based gradient (full opacity)
	Local gradI:= New Gradient<Int>(greenInt, yellowInt)
	gradI.A = New Vec2f(0, 0)
	gradI.B = New Vec2f(0, 100)
	gradI.Type = GradientType.Radial
	
	Print "Integer Gradient Test (Radial):"
	Print "  Start: $" + Gradient<Int>.IntToHexString(greenInt)
	Print "  End: $" + Gradient<Int>.IntToHexString(yellowInt)
	
	' Sample at different positions
	Print "  Sampling at t=0.0: $" + Gradient<Int>.IntToHexString(gradI.Sample(0.0))
	Print "  Sampling at t=0.5: $" + Gradient<Int>.IntToHexString(gradI.Sample(0.5))
	Print "  Sampling at t=1.0: $" + Gradient<Int>.IntToHexString(gradI.Sample(1.0))
	
	' Test with 2D positions for radial gradient
	Print "  At position (0,0): $" + Gradient<Int>.IntToHexString(gradI.GetColor(0, 0))
	Print "  At position (0,50): $" + Gradient<Int>.IntToHexString(gradI.GetColor(0, 50))
	Print "  At position (50,50): $" + Gradient<Int>.IntToHexString(gradI.GetColor(50, 50))
	Print "  At position (0,100): $" + Gradient<Int>.IntToHexString(gradI.GetColor(0, 100))
	
	' Test offsets from the center point
	Print "  At offset (25,25): $" + Gradient<Int>.IntToHexString(gradI.GetColor(25, 25))
	Print "  At offset (75,75): $" + Gradient<Int>.IntToHexString(gradI.GetColor(75, 75))
	
	' Advanced TrueColor Integer Tests
	Print ""
	Print "TrueColor ARGB Integer Tests:"
	
	' Create different integer colors with various alpha values
	Local redARGB:Int = $FFFF0000    ' Red (full opacity)
	Local blueARGB:Int = $FF0000FF    ' Blue (full opacity)
	Local purpleARGB:Int = $FF800080  ' Purple (full opacity)
	Local transRed:Int = $80FF0000    ' Semi-transparent red (50%)
	Local transBlue:Int = $800000FF   ' Semi-transparent blue (50%)
	
	Print "  TrueColor Values:"
	Print "    Red: $" + Gradient<Int>.IntToHexString(redARGB)
	Print "    Blue: $" + Gradient<Int>.IntToHexString(blueARGB)
	Print "    Trans Red (50%): $" + Gradient<Int>.IntToHexString(transRed)
	Print "    Trans Blue (50%): $" + Gradient<Int>.IntToHexString(transBlue)
	
	' Test alpha interpolation
	Print ""
	Print "  Alpha Transition Test:"
	Local alphaGrad:= New Gradient<Int>(transRed, redARGB)
	alphaGrad.A = New Vec2f(0, 0)
	alphaGrad.B = New Vec2f(100, 0)
	
	Print "    0% along gradient: $" + Gradient<Int>.IntToHexString(alphaGrad.Sample(0.0))
	Print "    25% along gradient: $" + Gradient<Int>.IntToHexString(alphaGrad.Sample(0.25))
	Print "    50% along gradient: $" + Gradient<Int>.IntToHexString(alphaGrad.Sample(0.5))
	Print "    75% along gradient: $" + Gradient<Int>.IntToHexString(alphaGrad.Sample(0.75))
	Print "    100% along gradient: $" + Gradient<Int>.IntToHexString(alphaGrad.Sample(1.0))
	
	' Test gradient with non-zero starting point for proper position calculation
	Print ""
	Print "Offset gradient test:"
	Local offsetGrad:= New Gradient<Int>(redARGB, blueARGB)
	offsetGrad.A = New Vec2f(50, 50)
	offsetGrad.B = New Vec2f(150, 150)
	
	Print "  Start point (50,50): $" + Gradient<Int>.IntToHexString(offsetGrad.GetColor(50, 50))
	Print "  Midpoint (100,100): $" + Gradient<Int>.IntToHexString(offsetGrad.GetColor(100, 100))
	Print "  End point (150,150): $" + Gradient<Int>.IntToHexString(offsetGrad.GetColor(150, 150))
	
	Print ""
	Print "Gradient type efficiency test:"
	
	Local start:Int = Millisecs()
	Local testColor:Color
	
	' Performance test
	For Local i:Int = 0 Until 1000000
		testColor = gradC.GetColor(i Mod 100, i Mod 100)
	Next
	
	Print "  1,000,000 gradient calculations took: " + (Millisecs() - start) + "ms"
	Print "  Final color: " + testColor.ToString()
	
	' Compare TrueColor int performance vs Color object performance
	Print ""
	Print "TrueColor Int vs Color object performance:"
	
	' Color object performance
	gradC.Type = GradientType.Segment
	start = Millisecs()
	For Local i:Int = 0 Until 1000000
		testColor = gradC.GetColor(i Mod 100, i Mod 100)
	Next
	Local colorTime:Int = Millisecs() - start
	
	' TrueColor int performance
	Local testInt:Int
	gradI.Type = GradientType.Segment  
	start = Millisecs()
	For Local i:Int = 0 Until 1000000
		testInt = gradI.GetColor(i Mod 100, i Mod 100)
	Next
	Local intTime:Int = Millisecs() - start
	
	Print "  Color object gradient: " + colorTime + "ms for 1M samples"
	Print "  TrueColor int gradient: " + intTime + "ms for 1M samples"
	Print "  Performance ratio: " + (colorTime / Max(intTime, 1)) + "x"
	
	' Compare performance between different gradient types
	Print ""
	Print "Comparing gradient types performance:"
	
	' Linear gradient performance
	gradI.Type = GradientType.Segment
	start = Millisecs()
	For Local i:Int = 0 Until 1000000
		testInt = gradI.GetColor(i Mod 100, i Mod 100)
	Next
	
	Print "  Segment gradient: " + (Millisecs() - start) + "ms for 1M samples"
	
	' Directional gradient performance
	gradI.Type = GradientType.Directional
	start = Millisecs()
	For Local i:Int = 0 Until 1000000
		testInt = gradI.GetColor(i Mod 100, i Mod 100)
	Next
	
	Print "  Directional gradient: " + (Millisecs() - start) + "ms for 1M samples"
	
	' Radial gradient performance
	gradI.Type = GradientType.Radial
	start = Millisecs()
	For Local i:Int = 0 Until 1000000
		testInt = gradI.GetColor(i Mod 100, i Mod 100)
	Next
	
	Print "  Radial gradient: " + (Millisecs() - start) + "ms for 1M samples"
End