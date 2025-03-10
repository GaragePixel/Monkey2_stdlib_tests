Namespace myapp

#Import "<stdlib>"
#Import "<sdk_mojo>"

#Import "assets/miramar-skybox.jpg"
#Import "assets/water_normal0.png"
#Import "assets/water_normal1.png"

Using stdlib..
Using sdk_mojo.m2..
Using sdk_mojo.m3..

Class MyWindow Extends Window
	
	Field _scene:Scene
	
	Field _camera:Camera
	
	Field _light:Light
	
	Field _water:Model
	
	Method New( title:String="Simple mojo app",width:Int=640,height:Int=480,flags:WindowFlags=WindowFlags.Resizable )

		Super.New( title,width,height,flags )
		
		_scene=New Scene
		
		_scene.SkyTexture=Texture.Load( "asset::miramar-skybox.jpg",TextureFlags.FilterMipmap|TextureFlags.Cubemap|TextureFlags.Envmap )
		
		'create camera
		'
		_camera=New Camera( self )
		_camera.Move( 0,10,-10 )
		_camera.AddComponent<FlyBehaviour>()
		
		'create light
		'
		_light=New Light
		_light.Rotate( 54,144,0 )	'calibrated so specular highlight matches sun on sky texture!
		
		'create water material
		'
		Local waterMaterial:=New WaterMaterial
		
		waterMaterial.ScaleTextureMatrix( 10,10 )
		
		waterMaterial.ColorFactor=Color.SeaGreen
		
		waterMaterial.NormalTextures=New Texture[]( 
			Texture.Load( "asset::water_normal0.png",TextureFlags.WrapST|TextureFlags.FilterMipmap ),
			Texture.Load( "asset::water_normal1.png",TextureFlags.WrapST|TextureFlags.FilterMipmap ) )
		
		waterMaterial.Velocities=New Vec2f[]( 
			New Vec2f( .01,.03 ),
			New Vec2f( .02,.05 ) )
		
		'create water
		'
		_water=Model.CreateBox( New Boxf( -50,-1,-50,50,0,50 ),1,1,1,waterMaterial )
	End
	
	Method OnRender( canvas:Canvas ) Override
	
		RequestRender()
		
		_scene.Update()
		
		_scene.Render( canvas )
	End
	
End

Function Main()

	New AppInstance
	
	New MyWindow
	
	App.Run()
End
