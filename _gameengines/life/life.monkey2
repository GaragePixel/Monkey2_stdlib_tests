
'An implementation of Conway's Game of Life

'http://en.wikipedia.org/wiki/Conway's_Game_of_Life

'To try different patterns, pause the 'game', click cells,
'then unpause.

'For best performance run in "Release" mode.

#Import "<stdlib>"
#Import "<sdk_mojo>"

Using stdlib..
Using sdk_mojo.m2..

Function Main()

	New AppInstance
	
	New LifeApp(1280, 720)
	
	App.Run()
End

'------------------------------

Class LifeApp Extends Window

	Field iterations:UInt				'number of iterations
	Field lastMS:ULong					'time of last iteration 
	
	Field speed:UInt					'iterations per second
	Field speedMin:UInt = 1
	Field speedMax:UInt = 20	
	
	Field paused:Bool
	Field suspended:Bool

	Field grid:CellGrid					
	Field gridRenderer:GridRenderer	
	Field gridArea:Recti				'canvas area to draw the grid image onto
	Field initialized:Bool = False		'false if grid and gridRenderer objects not yet created 

	Field fontHeight:UInt = 30			'should be able to get this value from canvas.Font.Height but can't yet?

	Field cellWidthPixels:UInt = 16
	Field cellHeightPixels:UInt = 16

	Method New(width:Int, height:Int)

		Super.New("Conway's Game of Life", width, height)
		
		ClearColor = Color.Black

		'Disable vsync if possible.
		SwapInterval = 0

	End
	
	'Create and initialize a cell grid and an associated Grid rendering object.
	Method Start:Void()
		
		paused = True
		
		iterations = 0
		speed = speedMax / 2
		
		'Grid's top left pixel coordinate
		Local gridTL := New Vec2i(10, fontHeight + 10)
		
		'Grid's bottom right pixel coordinate
		Local gridBR := New Vec2i(Width - 10, Height - fontHeight - 10)
		
		'Define a target area on which to draw the grid, using the above vectors
		gridArea = New Recti(gridTL, gridBR)
		
		'Calculate grid size based on the draw area's dimensions 
		'and desired cell size in pixels.
		Local gridCols := Floor(gridArea.Width / cellWidthPixels)
		Local gridRows := Floor(gridArea.Height / cellHeightPixels)
		
		'Create the grid of cells.
		grid = New CellGrid(gridCols, gridRows)		
		
		'Create the grid renderer, passing in a reference to the grid and the cell pixel dimensions.
		gridRenderer = New GridRenderer(grid, cellWidthPixels, cellHeightPixels)

		SeedRnd(Microsecs())
		
		paused = False
		
		lastMS = Millisecs()
	
		'Call the garbage collector. Maybe it can free some memory (or maybe not) 
		'if this Start method was called during a WindowResize event.
		GCCollect()
	
	End
	
	Method OnWindowEvent(event:WindowEvent) Override
	
		If event.Type = EventType.WindowResized

			'Make a new grid and associated grid renderer based
			'on the window's new dimensions.
			Start()
			
			App.RequestRender()
				
		Elseif event.Type = EventType.WindowClose
			
			App.Terminate()
			
		Elseif event.Type=EventType.WindowGainedFocus
		
			suspended=False
			
			App.RequestRender()	'kick start rendering...
			
		Elseif event.Type=EventType.WindowLostFocus
		
			suspended=True
					
		Endif
		
	End
	
	Method OnKeyEvent( event:KeyEvent ) Override
	
		If event.Type = EventType.KeyUp
				
			Select event.Key
		
				Case Key.Escape
					App.Terminate()
		
				Case Key.Space
					paused = Not paused	
					
				Case Key.Up
					SpeedUp()
					
				Case Key.Down
					SpeedDown()
					
				Case Key.Tab
					gridRenderer.ToggleGridOverlay()	
					
				Case Key.Enter
					'Reset, but retain the current speed.
					grid.Init()
					iterations = 0
					
				Case Key.C
					grid.Clear()

			End
		
		Endif
		
	End
	
	Method OnMouseEvent( event:MouseEvent ) Override
		
		Select event.Type
			Case EventType.MouseDown
				If event.Button = 1
					'if the clicked coordinate matches a cell then toggle it alive/dead.  
					Local cell:Cell = gridRenderer.GetCell(event.Location.X - gridArea.TopLeft.X, event.Location.Y - gridArea.TopLeft.Y)
					If cell Then cell.ToggleDead()
				Endif
				
		End
	
	End
	
	Method OnRender(canvas:Canvas) Override
	
		If Not initialized
			'This small If block only runs once at the start of the program.
			'(Mojo must finish "constructing" before the Window's Width and Height properties
			'return correct results - used in the Start method). 
			Start()
			initialized = True
		Endif
		
		If Not suspended App.RequestRender()

		canvas.Color = Color.White

		gridRenderer.Render()

		Local statusLine := "Iterations: " + iterations + "      FPS: " + Fps() + "      Speed: " + speed + "      "

		canvas.DrawText(statusLine, 10, 10)
		canvas.DrawText("[Space] - pause,    [Enter] - new,    [Up][Down] - speed,    [Tab] - toggle grid,    [c] - clear,    [Left-Click] - Toggle cell alive/dead" , 10, Height - fontHeight)

		canvas.DrawImage(gridRenderer.Image, gridArea.TopLeft.X, gridArea.TopLeft.Y)

		If paused
			canvas.Color = Color.Red
			canvas.DrawText("PAUSED - Press [space] to resume", 10 + canvas.Font.TextWidth(statusLine), 10)
		endif

		'---
		
		'Update the grid at the current speed (iterations per second). 
		
		If Not paused
			
			If Millisecs() >= (lastMS + (1000 / speed)) 
				grid.Iterate()
				iterations += 1
				lastMS = Millisecs()
			Endif
		Endif

		'---

	End
	
	Method SpeedUp:Void()
		If speed >= speedMax Then Return
		speed += 1
	End
	
	Method SpeedDown:Void()
		If speed <= speedMin Then Return
		speed -= 1
	End
	
End


'----------------------------------

'This class renders a cell grid to an image. It can also return
'a cell reference based on a given pixel coordinate.

Class GridRenderer

	Field _grid:CellGrid
	
	'Dimensions of the rectangle to render per cell.
	Field _rw:UInt, _rh:UInt

	'Image on which to render the grid. (And an associated canvas).
	Field _image:Image
	Field _iCanvas:Canvas
	
	Field _showGridOverlay:Bool
	
	Method New(grid:CellGrid, rw:UInt, rh:UInt) 
		_grid = grid
		_rw = rw
		_rh = rh
		_image = New Image(_grid.Cols * _rw + 1, _grid.Rows * _rh + 1)
		_iCanvas = New Canvas(_image)
		_showGridOverlay = True
	End	

	Property Image:Image()
		Return _image
	End

	Method ToggleGridOverlay:Void()
		_showGridOverlay = Not _showGridOverlay
	End

	Method GetCell:Cell(x:Float, y:Float)
		
		'Return a cell reference if a given pixel coordinate falls inside it. 		
		Local col:UByte = Floor(x / _rw)
		Local row:UByte = Floor(y / _rh)
		
		'Null will be returned if col or row are invalid. 
		Return _grid.GetCell(col, row)

	End
	
	Method Render:Void()
		
		'Render the grid (and overlay lines if necessary) onto the image canvas.
		
		_iCanvas.Clear(Color.Black)
	
		For Local c:Int = 0 until _grid.Cols
			For Local r:Int = 0 Until _grid.Rows
				Local curCell:Cell = _grid.GetCell(c, r)
				_iCanvas.Color = Color.DarkGrey
				If Not(curCell.Dead) Then _iCanvas.Color = Color.Green
				_iCanvas.DrawRect((c * _rw), (r * _rh), _rw, _rh)	
			Next
		Next

		If _showGridOverlay
			_iCanvas.Color = Color.Grey
			For Local x := 0 To _image.Width Step _rw
				_iCanvas.DrawLine(x, 0, x, _image.Height) 
			Next
			For Local y := 0 to _image.Height Step _rh
				_iCanvas.DrawLine(0, y, _image.Width, y) 
			Next
		Endif

		_iCanvas.Flush()

	End

End


'----------------------------------

'A cell can either be dead or alive.
'Pending dead = killed off in the second pass of the current iteration.

Class Cell

	Field _dead:Bool
	Field _pendingDead:Bool
	Field _col:UInt, _row:UInt
	
	Method New()
		Dead = True
		PendingDead = False
	End
	
	Method ToggleDead:Void()
		_dead = Not _dead
		_pendingDead = _dead
	End
	
	Method ApplyPending:Void()
		Dead = PendingDead
	End
	
	Property Dead:Bool()
		Return _dead
	Setter (value:Bool)
		_dead = value
	End
		
	Property PendingDead:Bool()
		Return _pendingDead
	Setter (value:Bool)
		_pendingDead = value
	End
	
	Property Col:UInt()
		Return _col
	Setter (value:UInt)
		_col = value
	End
	
	Property Row:UInt()
		Return _row
	Setter (value:UInt)
		_row = value
	End
	
End


'----------------------------------


Class CellGrid

	Field cols:UInt
	Field rows:UInt
	Field data:Cell[,]

	Method New(cols:UInt, rows:UInt)

		Self.cols = cols
		Self.rows = rows

		data = New Cell[cols, rows]
		For Local c:UInt = 0 Until cols
			For Local r:UInt = 0 Until rows
				data[c, r] = New Cell()
				data[c, r].Col = c
				data[c, r].Row = r
			Next
		Next

		Init()

	End

	Property Cols:UInt()
		Return cols
	End
	
	Property Rows:UInt()
		Return rows
	End

	Method GetCell:Cell(col:UInt, row:UInt)
		If (col < cols) And (col >= 0) And (row < rows) And (row >= 0)
			Return data[col, row]
		Endif
		
		Return Null
	End

	Method Clear:Void()		
		For Local c:UInt = 0 Until cols
			For Local r:UInt = 0 Until rows
				data[c, r].Dead = True
			Next
		Next
	End

	Method Init:Void()
		For Local c:UInt = 0 Until cols
			For Local r:UInt = 0 Until rows
			
				'Approx 25% of the cells will start alive
				
				If Floor(Rnd(0, 100)) <= 25 
					data[c, r].Dead = False
				Else
					data[c, r].Dead = True
				Endif
				
			Next
		Next
	End

	Method Iterate:Void()
	
		'First pass - determine what cells will live and die
		'Make the results 'pending'.
		For Local c:UInt = 0 Until cols
			For Local r:UInt = 0 Until rows
				
				Local curCell:Cell = data[c, r]
				
				curCell.PendingDead = True
				
				Local liveCount:UInt = CountLiveNeighbours(curCell.Col, curCell.Row)
						
				If curCell.Dead
					If (liveCount = 3) Then curCell.PendingDead = False
				Else
					curCell.PendingDead = False
					If (liveCount < 2) Or (liveCount > 3)
						curCell.PendingDead = True
					Endif
				Endif
				
			Next		
		Next

		'Second pass - modify the grid by applying the pending changes.
		For Local c:UInt = 0 Until cols
			For Local r:UInt = 0 Until rows
				data[c, r].ApplyPending()
			Next
		Next
		
	End

	Method CountLiveNeighbours:UInt(cc:Int, cr:Int)
	
		Local count:UInt = 0
		
		' --- Boundary checking
		
		Local startc:Int = cc - 1
		If startc < 0 Then startc = 0
		
		Local endc:Int = cc + 1
		If endc >= cols Then endc = cols - 1
		
		Local startr:Int = cr - 1
		If startr < 0 Then startr = 0
		
		Local endr:Int = cr + 1
		If endr >= rows Then endr = rows - 1

		' ---

		'Count the live neighbours of the given cell.
		For Local c:Int = startc To endc
			For Local r:Int = startr To endr
				If Not(data[c, r].Dead) Then count += 1
			End
		End
		
		'Adjust according to the given cell's status.
		If Not(data[cc, cr].Dead) Then count -= 1
		
		Return count
		
	End

End


'----------------------------------


'Frames-per-second function taken from the MX2 "Commanche" sample.
Function Fps:Float()
    
    Global FPStime:Float, frameCounter:Float, frameTimer:Float, totalFrames:Float
    
    frameCounter+= 1
    
    totalFrames+= 1
    
    If frameTimer < Millisecs()
		FPStime = frameCounter
		frameTimer = 1000 + Millisecs()
		frameCounter = 0  
    Endif
    
    Return FPStime
    
End Function
