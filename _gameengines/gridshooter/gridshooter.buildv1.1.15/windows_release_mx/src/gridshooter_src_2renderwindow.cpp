
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2renderwindow.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2area.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_math_2algebraic_2vectorials_2types_2rect.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2app.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2event.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2style.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2font.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2image.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2texture.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2input_2keyboard.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_collections_2stack.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2rect.h"

BB_CLASS(t_sdk_0mojo_m2_app_View)
BB_CLASS(t_sdk_0mojo_m2_graphics_Shader)
BB_ENUM(t_sdk_0mojo_m2_input_Key)
BB_ENUM(t_stdlib_graphics_PixelFormat)

extern bbInt g_stdlib_system_time_Millisecs();
bbGCVar<t_stdlib_collections_Stack_1s> g_default_RenderWindow__0echoStack;

void g_default_RenderWindow_Echo(bbString l_text){
  struct f0_t : public bbGCFrame{
    t_stdlib_collections_Stack_1s* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  (f0.t0=g_default_RenderWindow__0echoStack.get())->m_Push(l_text);
}

void t_default_RenderWindow::init(){
  m__0virtualRes=t_stdlib_math_types_Vec2_1i{bbNullCtor};
  m__0mouse=t_stdlib_math_types_Vec2_1i{bbNullCtor};
  m__0adjustedMouse=t_stdlib_math_types_Vec2_1i{bbNullCtor};
}

void t_default_RenderWindow::gcMark(){
  t_sdk_0mojo_m2_app_Window::gcMark();
  bbGCMark(m_canvas);
  bbGCMark(m_camera);
  bbGCMark(m__0parallaxCam);
  bbGCMark(m__0renderTexture);
  bbGCMark(m__0renderImage);
  bbGCMark(m__0textureCanvas);
  bbGCMark(m__0windowCanvas);
}

t_default_RenderWindow::t_default_RenderWindow(bbString l_title,bbInt l_width,bbInt l_height,bbBool l_filterTextures,bbBool l_renderToTexture,t_sdk_0mojo_m2_app_WindowFlags l_flags):t_sdk_0mojo_m2_app_Window(l_title,l_width,l_height,l_flags){
  init();
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_app_Style* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  this->m_Layout(bbString(L"letterbox",9));
  this->m_ClearColor(this->m_borderColor);
  (f0.t0=this->m_Style())->m_BackgroundColor(this->m_bgColor);
  this->m_renderToTexture=l_renderToTexture;
  this->m_filterTextures=l_filterTextures;
  this->m_camera=bbGCNew<t_default_Area_1d>(0.0,0.0,bbDouble(l_width),bbDouble(l_height));
  this->m__0parallaxCam=bbGCNew<t_default_Area_1d>(0.0,0.0,bbDouble(l_width),bbDouble(l_height));
  this->m_SetVirtualResolution(l_width,l_height);
}
t_default_RenderWindow::~t_default_RenderWindow(){
}

void t_default_RenderWindow::m_WindowStart(){
  this->m_OnStart();
}

bbFloat t_default_RenderWindow::m_Top(){
  return (bbFloat(-this->m_Height())/2.0f);
}

void t_default_RenderWindow::m_SetVirtualResolution(bbInt l_width,bbInt l_height){
  struct f0_t : public bbGCFrame{
    t_default_Area_1d* t0{};
    t_sdk_0mojo_m2_graphics_Texture* t1{};
    t_sdk_0mojo_m2_graphics_Image* t2{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
      bbGCMark(t2);
    }
  }f0{};
  this->m__0virtualRes=t_stdlib_math_types_Vec2_1i{l_width,l_height};
  this->m_MinSize(t_stdlib_math_types_Vec2_1i{(l_width/2),(l_height/2)});
  (f0.t0=this->m_camera.get())->m_Width(bbDouble(l_width));
  (f0.t0=this->m_camera.get())->m_Height(bbDouble(l_height));
  (f0.t0=this->m__0parallaxCam.get())->m_Width(bbDouble(this->m_Width()));
  (f0.t0=this->m__0parallaxCam.get())->m_Height(bbDouble(this->m_Height()));
  this->m__0renderTexture=bbGCNew<t_sdk_0mojo_m2_graphics_Texture>(l_width,l_height,t_stdlib_graphics_PixelFormat(5),this->m__0flags);
  this->m__0renderImage=bbGCNew<t_sdk_0mojo_m2_graphics_Image>(f0.t1=this->m__0renderTexture.get(),((t_sdk_0mojo_m2_graphics_Shader*)0));
  (f0.t2=this->m__0renderImage.get())->m_Handle(t_stdlib_math_types_Vec2_1f{0.0f,0.0f});
  this->m__0textureCanvas=bbGCNew<t_sdk_0mojo_m2_graphics_Canvas>(f0.t2=this->m__0renderImage.get());
}

void t_default_RenderWindow::m_SelectCanvas(){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Canvas* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  if(this->m_renderToTexture){
    this->m_canvas=this->m__0textureCanvas.get();
  }else{
    this->m_canvas=this->m__0windowCanvas.get();
  }
  (f0.t0=this->m_canvas.get())->m_Clear(this->m_bgColor);
}

bbFloat t_default_RenderWindow::m_Right(){
  return (bbFloat(this->m_Width())/2.0f);
}

void t_default_RenderWindow::m_Parallax(bbFloat l_value){
  struct f0_t : public bbGCFrame{
    t_default_Area_1d* t0{};
    t_default_Area_1d* t1{};
    t_default_Area_1d* t2{};
    t_sdk_0mojo_m2_graphics_Canvas* t3{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
      bbGCMark(t2);
      bbGCMark(t3);
    }
  }f0{};
  this->m__0parallax=l_value;
  (f0.t2=this->m__0parallaxCam.get())->m_Position(((f0.t0=this->m_camera.get())->m_X()*bbDouble(this->m__0parallax)),((f0.t1=this->m_camera.get())->m_Y()*bbDouble(this->m__0parallax)));
  if(this->m__0layerInitiated){
    struct f1_t : public bbGCFrame{
      t_sdk_0mojo_m2_graphics_Canvas* t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    (f1.t0=this->m_canvas.get())->m_PopMatrix();
    this->m__0layerInitiated=false;
  }
  (f0.t3=this->m_canvas.get())->m_PushMatrix();
  (f0.t3=this->m_canvas.get())->m_Translate(bbFloat(((-(f0.t0=this->m_camera.get())->m_X()*bbDouble(this->m__0parallax))+(this->m_camera.get()->m_Width()/2.0))),bbFloat(((-(f0.t1=this->m_camera.get())->m_Y()*bbDouble(this->m__0parallax))+(this->m_camera.get()->m_Height()/2.0))));
  this->m__0layerInitiated=true;
}

void t_default_RenderWindow::m_OnWindowEvent(t_sdk_0mojo_m2_app_WindowEvent* l_event){
  t_sdk_0mojo_m2_app_EventType l_0=l_event->m_Type();
  if((l_0==t_sdk_0mojo_m2_app_EventType(17))){
  }else if((l_0==t_sdk_0mojo_m2_app_EventType(18))){
    struct f1_t : public bbGCFrame{
      t_sdk_0mojo_m2_app_AppInstance* t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    (f1.t0=g_sdk_0mojo_m2_app_App.get())->m_RequestRender();
  }else if((l_0==t_sdk_0mojo_m2_app_EventType(19))){
  }else if((l_0==t_sdk_0mojo_m2_app_EventType(20))){
  }else{
    t_sdk_0mojo_m2_app_Window::m_OnWindowEvent(l_event);
  }
}

void t_default_RenderWindow::m_OnUpdate(){
}

void t_default_RenderWindow::m_OnStart(){
}

void t_default_RenderWindow::m_OnRender(t_sdk_0mojo_m2_graphics_Canvas* l_windowCanvas){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_app_AppInstance* t0{};
    t_sdk_0mojo_m2_app_Style* t1{};
    t_sdk_0mojo_m2_graphics_Canvas* t2{};
    t_stdlib_collections_Stack_1s* t3{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
      bbGCMark(t2);
      bbGCMark(t3);
    }
  }f0{};
  (f0.t0=g_sdk_0mojo_m2_app_App.get())->m_RequestRender();
  if(!this->m__0init){
    this->m__0init=true;
    this->m_SelectCanvas();
    this->m_WindowStart();
    return;
  }
  this->m_FrameUpdate();
  (f0.t1=this->m_Style())->m_BackgroundColor(this->m_bgColor);
  this->m__0windowCanvas=l_windowCanvas;
  this->m_SelectCanvas();
  this->m__0mouse=this->m_TransformPointFromView((f0.t0=g_sdk_0mojo_m2_app_App.get())->m_MouseLocation(),((t_sdk_0mojo_m2_app_View*)0));
  this->m__0adjustedMouse.m_x=bbInt((bbDouble(this->m__0mouse.m_x)+this->m_camera.get()->m_Left()));
  this->m__0adjustedMouse.m_y=bbInt((bbDouble(this->m__0mouse.m_y)+this->m_camera.get()->m_Top()));
  this->m_Parallax(1.0f);
  this->m_FrameDraw();
  if(this->m__0layerInitiated){
    struct f1_t : public bbGCFrame{
      t_sdk_0mojo_m2_graphics_Canvas* t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    (f1.t0=this->m_canvas.get())->m_PopMatrix();
    this->m__0layerInitiated=false;
  }
  if(this->m_renderToTexture){
    struct f1_t : public bbGCFrame{
      t_sdk_0mojo_m2_graphics_Canvas* t0{};
      t_sdk_0mojo_m2_graphics_Image* t1{};
      void gcMark(){
        bbGCMark(t0);
        bbGCMark(t1);
      }
    }f1{};
    (f1.t0=this->m_canvas.get())->m_Flush();
    (f1.t0=this->m__0windowCanvas.get())->m_DrawImage(f1.t1=this->m__0renderImage.get(),0.0f,0.0f);
  }
  (f0.t2=this->m__0textureCanvas.get())->m_Color(g_stdlib_graphics_Color_White);
  (f0.t2=this->m__0windowCanvas.get())->m_Color(g_stdlib_graphics_Color_White);
  if(this->m_debug){
    this->m_DebugInfo();
  }
  bbInt l_y=2;
  {
    struct f1_t : public bbGCFrame{
      t_stdlib_collections_Stack_1s_Iterator l_0{};
      t_stdlib_collections_Stack_1s* t0{};
      void gcMark(){
        bbGCMark(l_0);
        bbGCMark(t0);
      }
    }f1{};
    f1.l_0=(f1.t0=g_default_RenderWindow__0echoStack.get())->m_All();
    for(;!f1.l_0.m_AtEnd();f1.l_0.m_Bump()){
      struct f2_t : public bbGCFrame{
        t_sdk_0mojo_m2_graphics_Canvas* t0{};
        void gcMark(){
          bbGCMark(t0);
        }
      }f2{};
      bbString l_t=f1.l_0.m_Current();
      (f2.t0=this->m__0windowCanvas.get())->m_DrawText(l_t,5.0f,bbFloat(l_y),0.0f,0.0f);
      l_y+=bbInt((f2.t0=this->m__0windowCanvas.get())->m_Font()->m_Height());
    }
  }
  (f0.t3=g_default_RenderWindow__0echoStack.get())->m_Clear();
  if(((g_stdlib_system_time_Millisecs()-this->m__0tick)>1008)){
    this->m__0fps=bbInt(this->m__0fpscount);
    this->m__0tick=g_stdlib_system_time_Millisecs();
    this->m__0fpscount=0.0f;
  }else{
    this->m__0fpscount+=1.0f;
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyHit(t_sdk_0mojo_m2_input_Key(27),false)){
    struct f1_t : public bbGCFrame{
      t_sdk_0mojo_m2_app_AppInstance* t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    (f1.t0=g_sdk_0mojo_m2_app_App.get())->m_Terminate();
  }
}

t_stdlib_math_types_Vec2_1i t_default_RenderWindow::m_OnMeasure(){
  return this->m__0virtualRes;
}

void t_default_RenderWindow::m_OnDraw(){
}

t_stdlib_math_types_Vec2_1i t_default_RenderWindow::m_Mouse(){
  return this->m__0adjustedMouse;
}

bbFloat t_default_RenderWindow::m_Left(){
  return (bbFloat(-this->m_Width())/2.0f);
}

void t_default_RenderWindow::m_FrameUpdate(){
  this->m_OnUpdate();
}

void t_default_RenderWindow::m_FrameDraw(){
  this->m_OnDraw();
}

t_sdk_0mojo_m2_graphics_TextureFlags t_default_RenderWindow::m_Flags(){
  return this->m__0flags;
}

void t_default_RenderWindow::m_DebugInfo(){
  struct f0_t : public bbGCFrame{
    t_default_Area_1d* t0{};
    t_default_Area_1d* t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  g_default_RenderWindow_Echo((((bbString(L"Window resolution: ",19)+bbString(this->m_Frame().m_Width()))+bbString(L", ",2))+bbString(this->m_Frame().m_Height())));
  g_default_RenderWindow_Echo((((bbString(L"Virtual resolution: ",20)+bbString(this->m_Width()))+bbString(L", ",2))+bbString(this->m_Height())));
  g_default_RenderWindow_Echo((((bbString(L"Mouse:",6)+bbString(this->m_Mouse().m_x))+bbString(L",",1))+bbString(this->m_Mouse().m_y)));
  g_default_RenderWindow_Echo((((bbString(L"Camera:",7)+bbString(bbInt((f0.t0=this->m_camera.get())->m_X())))+bbString(L",",1))+bbString(bbInt((f0.t1=this->m_camera.get())->m_Y()))));
  g_default_RenderWindow_Echo((bbString(L"Layout: ",8)+this->m_Layout()));
  if(this->m_renderToTexture){
    g_default_RenderWindow_Echo(bbString(L"renderToTexture = True",22));
  }else{
    g_default_RenderWindow_Echo(bbString(L"renderToTexture = False",23));
  }
  g_default_RenderWindow_Echo((bbString(L"Camera: ",8)+(f0.t0=this->m_camera.get())->m_ToString()));
  g_default_RenderWindow_Echo((bbString(L"FPS: ",5)+bbString(this->m_FPS())));
}

void t_default_RenderWindow::m_CycleLayout(){
  bbString l_0=this->m_Layout();
  if((l_0==bbString(L"fill",4))){
    this->m_Layout(bbString(L"letterbox",9));
  }else if((l_0==bbString(L"letterbox",9))){
    this->m_Layout(bbString(L"stretch",7));
  }else if((l_0==bbString(L"stretch",7))){
    this->m_Layout(bbString(L"float",5));
  }else if((l_0==bbString(L"float",5))){
    this->m_Layout(bbString(L"letterbox",9));
  }
}

t_stdlib_math_types_Rect_1d t_default_RenderWindow::m_CameraRect(){
  struct f0_t : public bbGCFrame{
    t_default_Area_1d* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return (f0.t0=this->m__0parallaxCam.get())->m_Rect();
}

bbFloat t_default_RenderWindow::m_Bottom(){
  return (bbFloat(this->m_Height())/2.0f);
}

void mx2_gridshooter_src_2renderwindow_init_f(){
  g_default_RenderWindow__0echoStack=bbGCNew<t_stdlib_collections_Stack_1s>();
}

struct mx2_gridshooter_src_2renderwindow_roots_t : bbGCRoot{
  void gcMark(){
    bbGCMark(g_default_RenderWindow__0echoStack.get());
  }
}mx2_gridshooter_src_2renderwindow_roots;
