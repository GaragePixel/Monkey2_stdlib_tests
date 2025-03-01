
#ifndef MX2_GRIDSHOOTER_GAMEGRAPHICS_2SRC_2BACKGROUND_H
#define MX2_GRIDSHOOTER_GAMEGRAPHICS_2SRC_2BACKGROUND_H

#include <bbmonkey.h>

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2tilegraphics.h"

BB_CLASS(t_sdk_0mojo_m2_graphics_Canvas)
BB_STRUCT(t_stdlib_math_types_Rect_1d)

BB_CLASS(t_default_Background)

struct t_default_Background : public t_default_TileGraphics{
  typedef t_default_Background *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_Background";}

  bbInt m_total{};

  t_default_Background(bbString l_path);
  ~t_default_Background();

  bbString m_ToString();
  void m_Draw(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,bbDouble l_x,bbDouble l_y,bbDouble l_scale,t_stdlib_math_types_Rect_1d l_camera);

  t_default_Background(){
  }
};

#endif
