'==============================================================
' DitherMatrix Simple Test Unit
' Implementation: iDkP from GaragePixel
' 2025-03-29 (Aida 4)
'==============================================================
' Purpose: Verify correct operation of the DitherMatrix class and
' its optimized threshold lookup implementations
'==============================================================

#Import "<stdlib>"
Using stdlib..

Class DitherMatrixTest

	Function CreateTestPatterns:Int[]()
		' Create a recognizable pattern for testing (diagonal gradient)
		' Values increase from top-left to bottom-right for easy visual verification
		
		Local data:Int[] = New Int[64]
		For Local y:Int = 0 Until 8
			For Local x:Int = 0 Until 8
				data[y*8+x] = (x+y) & 15  ' Values 0-15 in diagonal pattern
			Next
		Next
		Return data
	End
	
	Function CreateTestMatrices()
		Print "Creating test matrices..."
		
		Local testPattern:Int[] = CreateTestPatterns()
		
		' 1. Square power-of-2 matrix (8x8)
		Local squareData:Int[] = testPattern.Slice(0, 64)
		squareMatrix = New DitherMatrix<Int>(8, 8, squareData, 15)
		Print "  - Created square power-of-2 matrix (8x8)"
		
		' 2. Rectangular dual power-of-2 matrix (8x4)
		Local rectData:Int[] = testPattern.Slice(0, 32)
		rectMatrix = New DitherMatrix<Int>(8, 4, rectData, 15)
		Print "  - Created rectangular dual power-of-2 matrix (8x4)"
		
		' 3. Width-only power-of-2 matrix (8x5)
		Local widthData:Int[] = testPattern.Slice(0, 40)
		widthMatrix = New DitherMatrix<Int>(8, 5, widthData, 15)
		Print "  - Created width-only power-of-2 matrix (8x5)"
		
		' 4. General case matrix (7x5)
		Local generalData:Int[] = New Int[35]
		For Local y:Int = 0 Until 5
			For Local x:Int = 0 Until 7
				generalData[y*7+x] = (x+y) & 15
			Next
		Next
		generalMatrix = New DitherMatrix<Int>(7, 5, generalData, 15)
		Print "  - Created general case matrix (7x5)"
		
		Print "All test matrices created successfully"
		Print ""
	End
	
	Function TestThresholdLookup()
		Print "Testing threshold lookups..."
		
		' Test coordinates within matrix bounds
		Print "  Origin coordinate tests:"
		Print "  - Square matrix:   " + squareMatrix.GetThreshold(0, 0)
		Print "  - Rect matrix:     " + rectMatrix.GetThreshold(0, 0)
		Print "  - Width matrix:    " + widthMatrix.GetThreshold(0, 0)
		Print "  - General matrix:  " + generalMatrix.GetThreshold(0, 0)
		
		' Test coordinates at specific positions
		Print "  Pattern value tests:"
		Print "  - Square (3,2): " + squareMatrix.GetThreshold(3, 2) + " (should be 5)"
		Print "  - Rect (3,2): " + rectMatrix.GetThreshold(3, 2) + " (should be 5)"
		Print "  - Width (3,2): " + widthMatrix.GetThreshold(3, 2) + " (should be 5)"
		Print "  - General (3,2): " + generalMatrix.GetThreshold(3, 2) + " (should be 5)"
		
		' Test pattern wrapping
		Print "  Pattern wrapping tests:"
		
		' Square matrix wrapping (8x8)
		Local x1:Int = 8, y1:Int = 8  ' Should wrap to (0,0)
		Print "  - Square: (8,8) wraps to (0,0): " + squareMatrix.GetThreshold(x1, y1) + " = " + squareMatrix.GetThreshold(0, 0) + "? " + (squareMatrix.GetThreshold(x1, y1) = squareMatrix.GetThreshold(0, 0))
		
		' Rect matrix wrapping (8x4)
		Local x2:Int = 8, y2:Int = 4  ' Should wrap to (0,0)
		Print "  - Rect: (8,4) wraps to (0,0): " + rectMatrix.GetThreshold(x2, y2) + " = " + rectMatrix.GetThreshold(0, 0) + "? " + (rectMatrix.GetThreshold(x2, y2) = rectMatrix.GetThreshold(0, 0))
		
		' Width matrix wrapping (8x5)
		Local x3:Int = 8, y3:Int = 5  ' Should wrap to (0,0)
		Print "  - Width: (8,5) wraps to (0,0): " + widthMatrix.GetThreshold(x3, y3) + " = " + widthMatrix.GetThreshold(0, 0) + "? " + (widthMatrix.GetThreshold(x3, y3) = widthMatrix.GetThreshold(0, 0))
		
		' General matrix wrapping (7x5)
		Local x4:Int = 7, y4:Int = 5  ' Should wrap to (0,0)
		Print "  - General: (7,5) wraps to (0,0): " + generalMatrix.GetThreshold(x4, y4) + " = " + generalMatrix.GetThreshold(0, 0) + "? " + (generalMatrix.GetThreshold(x4, y4) = generalMatrix.GetThreshold(0, 0))
		
		Print "  Negative coordinate tests:"
		Print "  - Square: (-1,-1): " + squareMatrix.GetThreshold(-1, -1) + " (should match (7,7): " + squareMatrix.GetThreshold(7, 7) + ")"
		Print "  - Rect: (-1,-1): " + rectMatrix.GetThreshold(-1, -1) + " (should match (7,3): " + rectMatrix.GetThreshold(7, 3) + ")"
		Print "  - Width: (-1,-1): " + widthMatrix.GetThreshold(-1, -1) + " (should match (7,4): " + widthMatrix.GetThreshold(7, 4) + ")"
		Print "  - General: (-1,-1): " + generalMatrix.GetThreshold(-1, -1) + " (should match (6,4): " + generalMatrix.GetThreshold(6, 4) + ")"
		
		Print "Threshold lookup tests completed"
		Print ""
	End
	
	Function TestPerformance()
		Print "Running performance comparison..."
		
		' Number of threshold lookups to perform
		Local iterations:Int = 10000000
		Local x:Int, y:Int
		Local start:Int, elapsed:Int
		Local threshold:Int
		Local sum:Int = 0  ' To prevent optimization removing the lookup
		
		' Test square power-of-2 matrix (should be fastest)
		start = Millisecs()
		For Local i:Int = 0 Until iterations
			x = i & 7  ' Fast modulo simulation with bit masking
			y = (i Shr 3) & 7
			threshold = squareMatrix.GetThreshold(x, y)
			sum += threshold
		Next
		elapsed = Millisecs() - start
		Print "  - Square power-of-2 matrix: " + elapsed + "ms for " + iterations + " lookups"
		
		' Test rectangular dual power-of-2 matrix
		start = Millisecs()
		sum = 0
		For Local i:Int = 0 Until iterations
			x = i & 7
			y = (i Shr 3) & 3
			threshold = rectMatrix.GetThreshold(x, y)
			sum += threshold
		Next
		elapsed = Millisecs() - start
		Print "  - Rectangular dual power-of-2 matrix: " + elapsed + "ms for " + iterations + " lookups"
		
		' Test width-only power-of-2 matrix
		start = Millisecs()
		sum = 0
		For Local i:Int = 0 Until iterations
			x = i & 7
			y = (i Shr 3) Mod 5
			threshold = widthMatrix.GetThreshold(x, y)
			sum += threshold
		Next
		elapsed = Millisecs() - start
		Print "  - Width-only power-of-2 matrix: " + elapsed + "ms for " + iterations + " lookups"
		
		' Test general case matrix (should be slowest)
		start = Millisecs()
		sum = 0
		For Local i:Int = 0 Until iterations
			x = i Mod 7
			y = (i / 7) Mod 5
			threshold = generalMatrix.GetThreshold(x, y)
			sum += threshold
		Next
		elapsed = Millisecs() - start
		Print "  - General case matrix: " + elapsed + "ms for " + iterations + " lookups"
		
		Print "Performance comparison completed"
		Print ""
	End
	
	Function TestBayerMatrix()
		Print "Testing BayerMatrix factory function..."
		
		' Create 4x4 Bayer matrix
		Local bayer:DitherMatrix<Int> = DitherMatrix<Int>.BayerMatrix(4, 15)
		
		If bayer = Null
			Print "  ERROR: BayerMatrix creation failed"
			Return
		Endif
		
		Print "  - Created 4x4 Bayer matrix"
		Print "  - Matrix dimensions: " + bayer.Square
		
		' Pattern verification
		Print "  - Testing pattern distribution:"
		
		Local threshold:Int
		Local sum:Int = 0
		Local min:Int = 15
		Local max:Int = 0
		
		' Analyze pattern
		For Local y:Int = 0 Until 4
			Local row:String = "    Row " + y + ": "
			For Local x:Int = 0 Until 4
				threshold = bayer.GetThreshold(x, y)
				row += threshold + " "
				sum += threshold
				min = Min(min, threshold)
				max = Max(max, threshold)
			Next
			Print row
		Next
		
		' Statistical analysis
		Print "  - Pattern stats: min=" + min + ", max=" + max + ", avg=" + (sum / 16.0)
		Print "  - Pattern check: " + ((min >= 0 And max <= 15 And max > min) ? "VALID" Else "INVALID")
		
		Print "Bayer matrix test completed"
		Print ""
	End
	
	Function TestHalftoneMatrix()
		Print "Testing HalftoneMatrix factory function..."
		
		' Create 8x8 Halftone matrix
		Local halftone:DitherMatrix<Int> = DitherMatrix<Int>.HalftoneMatrix(64, 15)
		
		If halftone = Null
			Print "  ERROR: HalftoneMatrix creation failed"
			Return
		Endif
		
		Print "  - Created 8x8 Halftone matrix"
		
		' Get important reference points
		Local centerValue:Int = halftone.GetThreshold(4, 4)
		Local cornerValue:Int = halftone.GetThreshold(0, 0)
		Local midEdgeValue:Int = halftone.GetThreshold(4, 0)
		
		Print "  - Testing radial pattern:"
		Print "    Center value: " + centerValue + " (should be high)"
		Print "    Corner value: " + cornerValue + " (should be low)"
		Print "    Mid-edge value: " + midEdgeValue + " (should be between)"
		
		' Validate radial gradient pattern
		Print "  - Pattern check: " + ((centerValue > midEdgeValue And midEdgeValue > cornerValue) ? "VALID" Else "INVALID")
		
		Print "Halftone matrix test completed"
		Print ""
	End
End

' Define global matrices for testing
Global squareMatrix:DitherMatrix<Int>           ' Square power-of-2 (fastest)
Global rectMatrix:DitherMatrix<Int>             ' Rectangular dual power-of-2
Global widthMatrix:DitherMatrix<Int>            ' Width-only power-of-2 
Global generalMatrix:DitherMatrix<Int>          ' General case (non-power-of-2)

Function Main()
	Print "===================================="
	Print "DitherMatrix Test Unit"
	Print "Implementation: iDkP from GaragePixel"
	Print "===================================="
	Print ""
	
	' Run tests
	DitherMatrixTest.CreateTestMatrices()
	DitherMatrixTest.TestThresholdLookup()
	DitherMatrixTest.TestPerformance()
	DitherMatrixTest.TestBayerMatrix()
	DitherMatrixTest.TestHalftoneMatrix()
	
	Print "===================================="
	Print "All tests completed"
	Print "===================================="
End