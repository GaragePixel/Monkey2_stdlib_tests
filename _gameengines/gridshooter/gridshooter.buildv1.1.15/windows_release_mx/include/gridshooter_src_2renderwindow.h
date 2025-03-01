
#ifndef MX2_GRIDSHOOTER_SRC_2RENDERWINDOW_H
#define MX2_GRIDSHOOTER_SRC_2RENDERWINDOW_H

#include <bbmonkey.h>

#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2window.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_resources_2graphics_2color.h"

BB_CLASS(t_default_Area_1d)
BB_CLASS(t_sdk_0mojo_m2_app_WindowEvent)
BB_CLASS(t_sdk_0mojo_m2_graphics_Canvas)
BB_CLASS(t_sdk_0mojo_m2_graphics_Image)
BB_CLASS(t_sdk_0mojo_m2_graphics_Texture)
BB_ENUM(t_sdk_0mojo_m2_graphics_TextureFlags)
BB_CLASS(t_stdlib_collections_Stack_1s)
BB_STRUCT(t_stdlib_math_types_Rect_1d)

BB_CLASS(t_default_RenderWindow)

extern bbGCVar<t_stdlib_collections_Stack_1s> g_default_RenderWindow__0echoStack;

void g_default_RenderWindow_Echo(bbString l_text);

struct t_default_RenderWindow : public t_sdk_0mojo_m2_app_Window{
  typedef t_default_RenderWindow *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_RenderWindow";}

  bbGCVar<t_sdk_0mojo_m2_graphics_Canvas> m_canvas{};
  bbGCVar<t_default_Area_1d> m_camera{};
  bbBool m_renderToTexture{false};
  bbBool m_filterTextures{true};
  t_stdlib_graphics_Color m_bgColor{g_stdlib_graphics_Color_DarkGrey};
  t_stdlib_graphics_Color m_borderColor{g_stdlib_graphics_Color_Black};
  bbBool m_debug{false};
  bbBool m__0init{false};
  t_sdk_0mojo_m2_graphics_TextureFlags m__0flags{};
  bbFloat m__0parallax{1.0f};
  bbGCVar<t_default_Area_1d> m__0parallaxCam{};
  t_stdlib_math_types_Vec2_1i m__0virtualRes{};
  t_stdlib_math_types_Vec2_1i m__0mouse{};
  t_stdlib_math_types_Vec2_1i m__0adjustedMouse{};
  bbBool m__0layerInitiated{false};
  bbInt m__0fps{60};
  bbFloat m__0fpscount{0.0f};
  bbInt m__0tick{bbInt(0)};
  bbGCVar<t_sdk_0mojo_m2_graphics_Texture> m__0renderTexture{};
  bbGCVar<t_sdk_0mojo_m2_graphics_Image> m__0renderImage{};
  bbGCVar<t_sdk_0mojo_m2_graphics_Canvas> m__0textureCanvas{};
  bbGCVar<t_sdk_0mojo_m2_graphics_Canvas> m__0windowCanvas{};

  void init();

  void gcMark();

  t_default_RenderWindow(bbString l_title,bbInt l_width,bbInt l_height,bbBool l_filterTextures,bbBool l_renderToTexture,t_sdk_0mojo_m2_app_WindowFlags l_flags);
  ~t_default_RenderWindow();

  virtual void m_WindowStart();
  bbFloat m_Top();
  void m_SetVirtualResolution(bbInt l_width,bbInt l_height);
  void m_SelectCanvas();
  bbFloat m_Right();
  void m_Parallax(bbFloat l_value);

  bbFloat m_Parallax(){
    return this->m__0parallax;
  }
  void m_OnWindowEvent(t_sdk_0mojo_m2_app_WindowEvent* l_event);
  virtual void m_OnUpdate();
  virtual void m_OnStart();
  void m_OnRender(t_sdk_0mojo_m2_graphics_Canvas* l_windowCanvas);
  t_stdlib_math_types_Vec2_1i m_OnMeasure();
  virtual void m_OnDraw();
  t_stdlib_math_types_Vec2_1i m_Mouse();
  bbFloat m_Left();
  virtual void m_FrameUpdate();
  virtual void m_FrameDraw();
  t_sdk_0mojo_m2_graphics_TextureFlags m_Flags();

  bbInt m_FPS(){
    return this->m__0fps;
  }
  virtual void m_DebugInfo();
  void m_CycleLayout();
  t_stdlib_math_types_Rect_1d m_CameraRect();
  bbFloat m_Bottom();

  t_default_RenderWindow(){
    init();
  }
};

#endif
