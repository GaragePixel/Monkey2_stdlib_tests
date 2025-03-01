
#ifndef MX2_GRIDSHOOTER_GAMEGRAPHICS_2SRC_2TILEGRAPHICS_H
#define MX2_GRIDSHOOTER_GAMEGRAPHICS_2SRC_2TILEGRAPHICS_H

#include <bbmonkey.h>

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2gamegraphics.h"

BB_STRUCT(t_stdlib_math_types_Rect_1d)

BB_CLASS(t_default_TileGraphics)

struct t_default_TileGraphics : public t_default_GameGraphics{
  typedef t_default_TileGraphics *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_TileGraphics";}

  bbDouble m_tileWidth{};
  bbDouble m_tileHeight{};
  bbDouble m_drawScaleX{};
  bbDouble m_drawScaleY{};
  bbDouble m_viewLeft{};
  bbDouble m_viewTop{};
  bbDouble m_viewRight{};
  bbDouble m_viewBottom{};
  bbInt m_tileStartX{};
  bbInt m_tileStartY{};
  bbInt m_tileEndX{};
  bbInt m_tileEndY{};

  ~t_default_TileGraphics();

  void m_GetVisibleTiles(bbDouble l_x,bbDouble l_y,bbDouble l_scale,t_stdlib_math_types_Rect_1d l_camera);

  t_default_TileGraphics(){
  }
};

#endif
