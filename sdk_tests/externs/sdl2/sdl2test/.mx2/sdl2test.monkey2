
#Import "<stdlib>"
#Import "<sdk>"

Namespace sdl2test

Using stdlib.plugins.sdl2
Using stdlib.plugins.libc
Using sdk.api.opengl

Class SdlWindow

	Field sdlWindow:SDL_Window Ptr

	Field sdlGLContext:SDL_GLContext
	
	Method New()
	
		SDL_Init( SDL_INIT_VIDEO )
		
		libc.atexit( SDL_Quit )
		
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_ES )'COMPATIBILITY )
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION,2 )
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION,1 )
		SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER,1 )
		SDL_GL_SetAttribute( SDL_GL_RED_SIZE,8 )
		SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE,8 )
		SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE,8 )
		
		sdlWindow=SDL_CreateWindow( "SDL2 OpenGL Window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_OPENGL )
		
		sdlGLContext=SDL_GL_CreateContext( sdlWindow )
		
		SDL_GL_MakeCurrent( sdlWindow,sdlGLContext )
		
		bbglInit()
	End
	
	Method Run()
	
		Repeat
		
			Local event:SDL_Event
			
			While( SDL_PollEvent( Varptr event ) )
		
				Select event.type
					
				Case SDL_WINDOWEVENT
		
					Local wevent:=Cast<SDL_WindowEvent Ptr>( Varptr event )
			
					Select wevent->event
					
					Case SDL_WINDOWEVENT_CLOSE
					
						libc.exit_(0)
					
					End
					
				End

			Wend
			
			OnRender()
			
			SDL_GL_SwapWindow( sdlWindow )

		Forever
		
	End
	
	Method OnRender()
	
		glClearColor( 1,1,0,1 )
		
		glClear( GL_COLOR_BUFFER_BIT )
		
		glEnable( GL_SCISSOR_TEST )
		
		For Local y:=0 Until 256
		
			glScissor( 0,y,640,1 )
			glClearColor( y/256.0,0,0,1 )
			glClear( GL_COLOR_BUFFER_BIT )
		
		Next
		
		glDisable( GL_SCISSOR_TEST )
	End
	
End


Function Main()

	Local window:=New SdlWindow
	
	window.Run()
End
