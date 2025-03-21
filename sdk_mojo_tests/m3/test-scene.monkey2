Namespace myapp3d

#Import "<stdlib>"
#Import "<sdk_mojo>"

#Reflect sdk_mojo 'FIXME

Using stdlib..
Using sdk_mojo.m2..
Using sdk_mojo.m3..

Class MyWindow Extends Window
	
	Field _scene:Scene
	Field _camera:Camera
	Field _light:Light
	Field _ground:Model
	Field _donut:Model
	
	Method New( title:String="Simple mojo3d app",width:Int=640,height:Int=480,flags:WindowFlags=WindowFlags.Resizable )
		
		Super.New( title,width,height,flags )
	End
	
	Method OnCreateWindow() Override
		
		'create editable scene
		_scene=New Scene( True )
		
		_scene.ClearColor = New Color( 0.2, 0.6, 1.0 )
		_scene.AmbientLight = _scene.ClearColor * 0.25
		_scene.FogColor = _scene.ClearColor
		_scene.FogFar = 1.0
		_scene.FogFar = 200.0
		
		'create camera
		_camera=New Camera( Self )
		_camera.AddComponent<FlyBehaviour>()
		_camera.Move( 0,2.5,-5 )
		
		'create light
		_light=New Light
		_light.CastsShadow=True
		_light.Rotate( 45, 45, 0 )
		
		'create ground
		Local groundBox:=New Boxf( -100,-1,-100,100,0,100 )
		Local groundMaterial:=New PbrMaterial( Color.Lime )
		_ground=Model.CreateBox( groundBox,1,1,1,groundMaterial )
		_ground.CastsShadow=False
		
		'create donut
		Local donutMaterial:=New PbrMaterial( Color.Red, 0.05, 0.2 )
		_donut=Model.CreateTorus( 2,.5,48,24,donutMaterial )
		_donut.Move( 0,2.5,0 )
		_donut.AddComponent<RotateBehaviour>().Speed=New Vec3f( .1,.2,.3 )
		
		_scene.Save( "test-scene.mojo3d","modules/mojo3d/tests/assets/" )
		
		_scene=Scene.Load( "test-scene.mojo3d" )
	End
	
	Method OnRender( canvas:Canvas ) Override
		
		RequestRender()
		
		_scene.Update()
		
		_scene.Render( canvas )
		
		canvas.DrawText( "FPS="+App.FPS,0,0 )
	End
	
End

Function Main()

	New AppInstance
	
	New MyWindow
	
	App.Run()
End
