
#ifndef MX2_COMMANCHE_COMMANCHE_H
#define MX2_COMMANCHE_COMMANCHE_H

#include <bbmonkey.h>

#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2window.h"

BB_CLASS(t_sdk_0mojo_m2_graphics_Canvas)
BB_CLASS(t_sdk_0mojo_m2_graphics_Image)
BB_CLASS(t_stdlib_graphics_Pixmap)

BB_CLASS(t_default_tCamera)
BB_CLASS(t_default_MyWindow)

extern bbInt g_default_WIDTH;
extern bbInt g_default_HEIGHT;
extern bbInt g_default_MAPW;
extern bbInt g_default_MAPH;
extern bbGCVar<t_stdlib_graphics_Pixmap> g_default_Cmap;
extern bbGCVar<t_stdlib_graphics_Pixmap> g_default_Dmap;
extern bbGCVar<t_stdlib_graphics_Pixmap> g_default_PmapDest;
extern bbGCVar<t_sdk_0mojo_m2_graphics_Image> g_default_image;
extern bbFloat g_default_depth;
extern bbGCVar<t_default_tCamera> g_default_Camera;

void bbMain();

struct t_default_tCamera : public bbObject{
  typedef t_default_tCamera *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_tCamera";}

  bbFloat m_x{512.0f};
  bbFloat m_y{800.0f};
  bbFloat m_height{78.0f};
  bbFloat m_angle{0.0f};
  bbFloat m_v{-100.0f};

  ~t_default_tCamera();

  t_default_tCamera(){
  }
};

struct t_default_MyWindow : public t_sdk_0mojo_m2_app_Window{
  typedef t_default_MyWindow *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_MyWindow";}

  bbGCVar<t_stdlib_graphics_Pixmap> m_pm{};
  bbGCVar<t_sdk_0mojo_m2_graphics_Image> m_img{};

  void gcMark();

  t_default_MyWindow(bbString l_title,bbInt l_width,bbInt l_height,t_sdk_0mojo_m2_app_WindowFlags l_flags);
  ~t_default_MyWindow();

  void m_UpdateSim();
  void m_UpdateCamera();
  void m_Raycast(bbInt l_line,bbFloat l_x1,bbFloat l_y1,bbFloat l_x2,bbFloat l_y2,bbFloat l_d);
  void m_OnRender(t_sdk_0mojo_m2_graphics_Canvas* l_canvas);
  void m_LoadMap();

  t_default_MyWindow(){
  }
};

#endif
