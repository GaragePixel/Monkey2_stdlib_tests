Namespace myapp

#Import "<stdlib>"
#Import "<sdk>"
#Import "<sdk_mojo>"

#Import "../assets/"
'the following import is not necessary in this case but if you put images in another directory
'it's how you can import the to asset:images/
#Import "../assets/images/@/images/" 

Using stdlib..
Using sdk..
Using sdk_mojo..

Global w_width:=1000 'initial window size
Global w_height:=700

Class Box2DgfxTest Extends Window

	Field physManager:b2Manager
	Field drawDebug:=True
	
	Method New( title:String,width:Int,height:Int,flags:WindowFlags=WindowFlags.Resizable )
		
		Super.New( title,width,height,flags )
		ClearColor=Color.Black
		'------- Initialising b2Manager (the world and all the stuff associated wth the Json) 
		physManager=New b2Manager("asset::images.json")
		
	End
	
	Method OnRender( canvas:Canvas ) Override
		
		App.RequestRender()
		
		canvas.PushMatrix()
		'centering the canvas transform on the "car"
		canvas.SetCameraByCenter(physManager.FromPhysics(physManager.GetBody("car").GetPosition()),1.7)
		physManager.StepWorld()
		physManager.DrawDebug(canvas)
		physManager.DrawBodies(canvas)
		canvas.PopMatrix()
		
		canvas.DrawText("Use up/down arrows to move the car",5,35)
		
		'
		'
		' control of the car
		'
		'
		Local MSpeed:=0.0
		If Keyboard.KeyDown(Key.Up)
			MSpeed=-3.0
		End
		If Keyboard.KeyDown(Key.Down)
			MSpeed=1.0
		End
		'Setting the motor speed of the joint called "frontwheel"
		Local frontWheelJoint:=physManager.GetJointInfo("frontwheel")
		b2JointTob2WheelJoint(frontWheelJoint.theb2Joint).SetMotorSpeed(MSpeed)
		
	End
End

Function Main()

	New AppInstance
	New Box2DgfxTest( "Box2D_test",w_width,w_height )
	App.Run()
End

Class Canvas Extension
	
	Method SetCameraByCenter(point:Vec2f,zoom:Float=1.0,rotation:Float=0,vr:Vec2f=New Vec2f(0,0))
 
		Translate(Viewport.Width/2,Viewport.Height/2)
		Scale(zoom,zoom)
		Rotate(rotation)
		Translate(-point)
 
	End
	
End