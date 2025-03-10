
Namespace myapp

#Import "<stdlib>"
#Import "<sdk_mojo>"

#Import "assets/miramar-skybox.jpg"
#Import "assets/terrain_256.png"
#Import "assets/mossy.pbr/@/mossy.pbr"

Using stdlib..
Using sdk_mojo.m2..
Using sdk_mojo.m3..

Class MyWindow Extends Window
	
	Field _scene:Scene
	
	Method New( title:String="Simple mojo app",width:Int=640,height:Int=480,flags:WindowFlags=WindowFlags.Resizable )

		Super.New( title,width,height,flags )
		
		CreateScene()
	End
	
	Method CreateTerrain:Model()
		
		Local box:=New Boxf( -256,0,-256,256,32,256 )
		
		Local hmap:=Pixmap.Load( "asset::terrain_256.png",PixelFormat.I8 )

		Local material:=PbrMaterial.Load( "asset::mossy.pbr" )
		material.ScaleTextureMatrix( 64,64 )
		
		'model+mesh
		Local terrain:=Model.CreateTerrain( hmap,box,material )
		terrain.CastsShadow=False
		
		Local collider:=New TerrainCollider( terrain )
		collider.Heightmap=hmap
		collider.Bounds=box
		
		Local body:=New RigidBody( terrain )
		body.Mass=0
		
		Return terrain
	End
	
	Method CreateBodies()
		
		Local material:=New PbrMaterial( Color.Brown,1,.5 )
		
		Local box:=New Boxf( -.5,.5 )
		
		Local model:=Model.CreateBox( box,1,1,1,material )
		
		Local collider:=model.AddComponent<BoxCollider>()
		collider.Box=box
		
		Local body:=model.AddComponent<RigidBody>()
			
		For Local i:=0 Until 360 Step 6
			
			Local copy:=model.Copy()
			
			copy.Rotate( 0,i,0 )
			
			copy.Move( 0,40+i*.1,Rnd( 5,10 ) )
		Next			
		
		model.Destroy()
	End

	Method CreateScene()

		_scene=New Scene
		_scene.SkyTexture=Texture.Load( "asset::miramar-skybox.jpg",TextureFlags.FilterMipmap|TextureFlags.Cubemap )
		_scene.FogColor=New Color( .75,1,0 )*.25
		_scene.FogNear=75
		_scene.FogFar=100
		
		Local camera:=New Camera( Self )
		camera.Near=.1
		camera.Far=100
		camera.Move( 0,40,0 )
		New FlyBehaviour( camera )
		
		Local light:=New Light
		light.CastsShadow=True
		light.RotateX( 45 )
		
		CreateTerrain()
		
		CreateBodies()
	End
	
	Method OnRender( canvas:Canvas ) Override

		RequestRender()
		
		_scene.Update()
		
		_scene.Render( canvas )

		canvas.DrawText( "FPS="+App.FPS,Width,0,1,0 )
	End
	
End

Function Main()
	
	New AppInstance
	
	New MyWindow
	
	App.Run()
End
