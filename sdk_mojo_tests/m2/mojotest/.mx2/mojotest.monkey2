
#Import "<stdlib>"
#Import "<sdk_mojo>"

#Import "assets/RedbrushAlpha.png"

Namespace mojotest

Using stdlib..
Using sdk_mojo.m2..

Class MojoTest Extends Window

	Field image:Image
	
	Field tx:Float,ty:Float
	Field r:Float=1,g:Float=1,b:Float=1

	Method New()
		
		ClearColor=New Color( 0,0,.5 )

		image=Image.Load( "asset::RedbrushAlpha.png" )
		image.Handle=New Vec2f( .5,.5 )
	End
	
	Method OnRender( canvas:Canvas ) Override
	
		App.RequestRender()
	
		Local sz:=Sin( Millisecs()*.0007 ) * 32
		Local sx:=32+sz,sy:=32,sw:=Width-(64+sz*2),sh:=Height-(64+sz)
		
		canvas.Scissor=New Recti( sx,sy,sx+sw,sy+sh )
		canvas.Clear( New Color( 1,32.0/255.0,0,1 ) )
		
		canvas.PushMatrix()
		
		canvas.Translate( tx,ty )
		canvas.Scale( Width/640.0,Height/480.0 )
		canvas.Translate( 320,240 )
		canvas.Rotate( Millisecs()*.0003 )
		canvas.Translate( -320,-240 )
		
		canvas.Color=New Color( .5,1,0 )
		canvas.DrawRect( 32,32,640-64,480-64 )

		canvas.Color=Color.Yellow
		For Local y:=0 Until 480
			For Local x:=16 Until 640 Step 32
				canvas.Alpha=Min( Abs( y-240.0 )/120.0,1.0 )
				canvas.DrawPoint( x,y )
			Next
		Next
		canvas.Alpha=1
		
		canvas.Color=New Color( 0,.5,1 )
		canvas.DrawOval( 64,64,640-128,480-128 )

		canvas.Color=New Color( 1,0,.5 )
		canvas.DrawLine( 32,32,640-32,480-32 )
		canvas.DrawLine( 640-32,32,32,480-32 )

		canvas.Color=New Color( r,g,b,Sin( Millisecs()*.003 ) *.5 +.5 )
		canvas.DrawImage( image,320,240 )

		canvas.Color=New Color( 1,0,.5 )
		canvas.DrawPoly( New Float[]( 140.0,232.0, 320.0,224.0, 500.0,232.0, 500.0,248.0, 320.0,256.0, 140.0,248.0 ) )
						
		canvas.Color=New Color( 1,.5,0 )
		canvas.DrawText( "The Quick Brown Fox Jumps Over The Lazy Dog",320,240,.5,.5 )
		
		canvas.PopMatrix()
		
		canvas.Scissor=Rect
		canvas.Color=Color.Red
		canvas.DrawRect( 0,0,Width,1 )
		canvas.DrawRect( Width-1,0,1,Height )
		canvas.DrawRect( 0,Height-1,Width,1 )
		canvas.DrawRect( 0,0,1,Height-1 )

		canvas.Color=Color.Blue
	
	End

End

Function Main()

	New AppInstance
	
	New MojoTest
	
	App.Run()

End
