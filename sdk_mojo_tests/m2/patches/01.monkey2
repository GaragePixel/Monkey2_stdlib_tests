
#Import "<stdlib>"
#Import "<sdk_mojo>"
#Import "../assets/C1W.png"
#Import "../assets/Tile3.png"

Using stdlib.math.types..
Using stdlib.graphics..
Using stdlib.collections..
Using sdk_mojo.m2..

'========================================================================================
'------------------------------------------------------------------------------ TEST
'========================================================================================

Public 

Function DeviceSize:Vec2i(win:Window)
	Return win.Frame.Size
End

Const WIDTH:Int =1280
Const HEIGHT:Int =720

Class MyWindow Extends Window
	
	Field myRect9:Rect9i
	Field myRect9f:Rect9f 'Only to demonstrates type conversion
	
	Field myImage:Image
	Field myCircleImg:Image
	
	Field swapOption:Int=0
	
	Method New(title:String,width:Int,height:Int,flags:WindowFlags=Null)
		Super.New(title,width,height,flags)
		
		myRect9=New Rect9i(10,10,200,200,50,150,100,100)
		
		myImage=Image.Load("asset::C1W.png")
		myCircleImg=Image.Load("asset::Tile3.png")
		
	End Method
	
	Method OnRender(canvas:Canvas) Override
		App.RequestRender()
		'----------------- Quit the app
		If Keyboard.KeyDown(Key.Escape|Key.Raw)
			App.Terminate()
		Endif	
		'----------------- Get some features
		Local winSize:=DeviceSize(Self)
		Local MousePos:=MouseLocation
		'----------------- Resize the rect9 within the App's window
		myRect9.Origin=New Vec2i(10,10)
		myRect9.Size=New Vec2i(winSize.x-20,winSize.y-20)
		'----------------- Set the marginsRect at some absolute positions (locking)
		myRect9.Pad(100,100,winSize.x-100,winSize.y-100)
		'----------------- Lock the (inner) right edge at an absolute position
		myRect9.PadRight=600
		'----------------- Use the properties to resize the rect
		myRect9.Origin=New Vec2i(20,20) ' same than TopLeft
		myRect9.BottomRight=New Vec2i(winSize.x-20,winSize.y-20)
		'----------------- Move the rect using the accremental add operator
		myRect9+=New Vec2i(10,10)
		'----------------- Move the rect without changing the edge's absolute position 
		'					(Lock mode)
		myRect9 = myRect9.ResizeOutter(150,myRect9.min.y,myRect9.max.x,myRect9.max.y)
		'----------------- Left will move with the left-edge padding keeped at 0
		myRect9.Left=100
		'----------------- Left will move, the marginsRect's left's edge is locked
		myRect9 = myRect9.ResizeLeft(50)

		'----------------- The rect9<float> is changed for a rect9<int>:
		'Comment these two lines if you want test integer rect9:
		myRect9f=myRect9
		Local r9:= myRect9f
		'uncomment this like if you want test integer rect9:
		'Local r9:= myRect9
		
		'----------------- Demonstration of fitted images:

		If Keyboard.KeyHit(Key.Enter|Key.Raw)
			swapOption+=1
		Endif

		Select swapOption
			Case 0
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.Bottom	| TileMode.Right)
			Case 1		
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.FitH		| TileMode.CenterY)
			Case 2
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.FitH		| TileMode.Top)
			Case 3
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.FitH		| TileMode.Bottom)
			Case 4
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.FitH		| TileMode.FitH)' = like Fit
			Case 5
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.FitH		| TileMode.FitV)' = like Fit
			Case 6
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.FitV		| TileMode.Left)
			Case 7
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.FitV		| TileMode.Right)
			Case 8
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.FitV		| TileMode.FitV)' = like Fit
			Case 9
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.FitV		| TileMode.CenterX)
			Case 10
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.CenterX	| TileMode.Bottom)
			Case 11
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.CenterX	| TileMode.FitV)
			Case 11
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.Bottom	| TileMode.Left)
			Case 12		
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.Fit)
			Case 13
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.Bottom	| TileMode.CenterX)
			Case 14
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.CenterY	| TileMode.Right)
			Case 15
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.CenterY	| TileMode.CenterX)
			Case 16
				canvas.Draw.Image_.Tiled(myCircleImg,r9.Inner,TileMode.CenterY	| TileMode.Left)
			Case 17
				swapOption=0
		End
		
		canvas.Draw.Image_.Rect(myImage,myRect9.CornerTopLeft)
		canvas.Draw.Image_.Rect(myImage,myRect9.CornerTopMiddle)
		canvas.Draw.Image_.Rect(myImage,myRect9.CornerTopRight)
		canvas.Draw.Image_.Rect(myImage,myRect9.CornerMiddleRight)
		canvas.Draw.Image_.Rect(myImage,myRect9.CornerBottomRight)
		canvas.Draw.Image_.Rect(myImage,myRect9.CornerBottomMiddle)
		canvas.Draw.Image_.Rect(myImage,myRect9.CornerBottomLeft)
		canvas.Draw.Image_.Rect(myImage,myRect9.CornerMiddleLeft)

		'----------------- Enlight the rect9's corner's aeras under the mouse
		canvas.Color = New Color(0,0,1,.5)
		If myRect9.CornerTopLeftContains(MousePos) 		
															canvas.DrawRect(myRect9.CornerTopLeft)
		Elseif myRect9.CornerTopMiddleContains(MousePos) 		
															canvas.DrawRect(myRect9.CornerTopMiddle)
		Elseif myRect9.CornerTopRightContains(MousePos) 		
															canvas.DrawRect(myRect9.CornerTopRight)
		Elseif myRect9.CornerMiddleLeftContains(MousePos) 		
															canvas.DrawRect(myRect9.CornerMiddleLeft)
		Elseif myRect9.CornerMiddleRightContains(MousePos) 	
															canvas.DrawRect(myRect9.CornerMiddleRight)		
		Elseif myRect9.CornerBottomLeftContains(MousePos) 		
															canvas.DrawRect(myRect9.CornerBottomLeft)
		Elseif myRect9.CornerBottomMiddleContains(MousePos) 	
															canvas.DrawRect(myRect9.CornerBottomMiddle)
		Elseif myRect9.CornerBottomRightContains(MousePos) 	
															canvas.DrawRect(myRect9.CornerBottomRight)
		Elseif myRect9.CornerMiddleContains(MousePos) 			
															canvas.Color = New Color(0,0,1,0.3)
															canvas.DrawRect(myRect9.CornerMiddle)			
		End

		'----------------- If you want test the zoom transformation:
		'myRect9=myRect9.Zoomed(Mouse.X)
		'or
		'myRect9.Zoom(Mouse.X)

		'----------------- Draw the rect9's wireframe
		'canvas.Draw.Wireframe.Patches(myRect9, New Color(1,0,0),New Color(1,1,0)) '<------------------------------ Drawn the wireframe here

		'----------------- Demonstration of the wireframe debugmode
		canvas.Draw.Rect_.Patches.Debug.GridCross( myRect9 ) '<------------------------------ Drawn the wireframe here

		'----------------- Draw some dummies at the middles of the rect9's edges
		canvas.Translate(-5,-5)
		canvas.Color = New Color(1,1,1)
		DrawText(canvas,"X",	myRect9.MiddleTop)
		DrawText(canvas,"X",	myRect9.MiddleBottom)
		DrawText(canvas,"X",	myRect9.MiddleLeft)
		DrawText(canvas,"X",	myRect9.MiddleRight)
		DrawText(canvas,"X",	myRect9.Center)
		'----------------- Draw some dummies at the rect9's corners
		DrawText(canvas,"O",	myRect9.TopLeft)
		DrawText(canvas,"O",	myRect9.BottomLeft)
		DrawText(canvas,"O",	myRect9.TopRight)
		DrawText(canvas,"O",	myRect9.BottomRight)	
		'----------------- Change the color according the OverPad-test
		If myRect9.OverPad
			canvas.Color = New Color(1,.8,1)
			'Redraw the MarginsRect with the ~new color and using the old matrix
			canvas.Translate(5,5)
			Local newcolor:=canvas.Color
			newcolor.r/=2
			newcolor.g/=2
			newcolor.b/=2
			canvas.Draw.Rect_.Patches.InnerFrame(myRect9,newcolor) '<------------------------------ Drawn the wireframe here
			canvas.Translate(-5,-5)
		Else 
			canvas.Color = New Color(.8,0,.8)
		End 
		'----------------- ZeroPad-test, change for a more enlighted color :P
		If myRect9.ZeroPad
			canvas.Translate(5,5)
			canvas.Draw.Rect_.Patches.InnerFrame(myRect9,New Color(1,1,1)) '<------------------------------ Drawn the wireframe here
			canvas.Translate(-5,-5)
		End 		
		'----------------- Draw some dummies at the middles of the rect9's marginsRect's edges
		DrawText(canvas,"x",	myRect9.InnerMiddleTop)
		DrawText(canvas,"x",	myRect9.InnerMiddleBottom)
		DrawText(canvas,"x",	myRect9.InnerMiddleLeft)
		DrawText(canvas,"x",	myRect9.InnerMiddleRight)
		DrawText(canvas,"x",	myRect9.InnerCenter)
		'----------------- Draw some dummies at the rect9's marginsRect's corners
		DrawText(canvas,"o",	myRect9.InnerTopLeft)
		DrawText(canvas,"o",	myRect9.InnerBottomLeft)
		DrawText(canvas,"o",	myRect9.InnerTopRight)
		DrawText(canvas,"o",	myRect9.InnerBottomRight)	
		'----------------- Title Rect-centered horizontally, CornerTop-centered vertically
		canvas.Color = New Color(0,1,0)
		Local title:="Rect9 example"
		'okay, it's not really x-centered ^^'
		canvas.DrawText(title,myRect9.Center.x-(4*title.Length),myRect9.CornerTopMiddle.Center.y)
		canvas.Flush()
		'----------------- Print some infos
		canvas.Color = New Color(1,1,1)
		canvas.DrawText("Resizes the window and moves the mouse around^^",20,20)
		'----------------- Print the formal data
		canvas.DrawText(myRect9,20,40)		
		canvas.DrawText("MarginsRect's right edge's absolute position : "+myRect9.PadRight,20,60)
		canvas.DrawText("Middle patch pattern mode (press [Enter] to change it) : "+swapOption,20,80)
		
		'Demonstration of copy:
'		myRect9f=myRect9
		'canvas.Rect9.DrawInnerFrame(myRect9f,New Color(0,0,1))

	End
	Function DrawText(canvas:Canvas,txt:string,pos:Vec2i)
		canvas.DrawText(txt,pos.x,pos.y)
	End
End			

Function Main()

	New AppInstance
	
	New MyWindow("",WIDTH,HEIGHT,WindowFlags.Resizable)

	App.Run()
End
