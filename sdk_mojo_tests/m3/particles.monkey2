Namespace myapp

#Import "<stdlib>"
#Import "<sdk_mojo>"

Using stdlib..
Using sdk_mojo.m2..
Using sdk_mojo.m3..

Class MyWindow Extends Window
	
	Field _scene:Scene
	
	Field _camera:Camera
	
	Field _light:Light
	
	Field _ground:Model
	
	Field _particles:ParticleSystem
	
	Method New( title:String="Simple mojo app",width:Int=640,height:Int=480,flags:WindowFlags=WindowFlags.Resizable )

		Super.New( title,width,height,flags )
		
		_scene=Scene.GetCurrent()
		
'		_scene.SkyTexture=Texture.Load( "asset::miramar-skybox.jpg",TextureFlags.FilterMipmap|TextureFlags.Cubemap )
		
		_scene.FogColor=Color.Sky
		_scene.FogNear=20
		_scene.FogFar=1000
		
		'create camera
		'
		_camera=New Camera( Self )
		_camera.Near=.01
		_camera.Move( 0,1,-1 )
		New FlyBehaviour( _camera )
		
		'create light
		'
		_light=New Light
		_light.Rotate( 60,45,0 )	'aim directional light 'down' - Pi/2=90 degrees.
		
		'create ground
		'
		_ground=Model.CreateBox( New Boxf( -50,-1,-50,50,0,50 ),1,1,1,New PbrMaterial( Color.Green * .5 ) )
		
		_particles=New ParticleSystem( 15000 )
		_particles.RotateX( -90 )	'point upwards!
		
		Local pmaterial:=_particles.Material
'		pmaterial.ColorTexture=Texture.Load( "asset::bluspark.png",TextureFlags.FilterMipmap )
		
		Local pbuffer:=_particles.ParticleBuffer
		pbuffer.Gravity=New Vec3f( 0,-9.81,0 )	'gravity in world space in m/s^2.
		pbuffer.Duration=2.5		'how long a single particle lasts in seconds.
		pbuffer.Fade=0.0			'how long before paticle starts fading out in seconds.
		pbuffer.Colors=New Color[]( Color.White,Color.Yellow,Color.Orange,Color.Red )
		pbuffer.ConeAngle=30		'angle of particle emission cone.
		pbuffer.MinVelocity=15.0	'min particle velocity.
		pbuffer.MaxVelocity=20.0	'max particle velocity.
		pbuffer.MinSize=8.0		'min particle size.
		pbuffer.MaxSize=12.0		'max particle size.
		
		For Local an:=0 Until 360 Step 45
			
			Local pivot:=New Entity
			pivot.RotateY( an )
			pivot.MoveZ( 20 )
			pivot.Visible=True
			
			_particles.Copy( pivot )
		Next
		
	End
	
	Method OnRender( canvas:Canvas ) Override
	
		RequestRender()
		
		_scene.Update()
		
		_scene.Render( canvas )
		
		canvas.DrawText( "Width="+Width+", Height="+Height+", FPS="+App.FPS,0,0 )
	End
	
End

Function Main()
	
	New AppInstance
	
	New MyWindow
	
	App.Run()
End
