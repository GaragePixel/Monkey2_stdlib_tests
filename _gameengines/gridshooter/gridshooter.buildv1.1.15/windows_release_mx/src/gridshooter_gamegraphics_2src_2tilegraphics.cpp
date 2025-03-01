
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2tilegraphics.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_math_2algebraic_2vectorials_2types_2rect.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_math.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2image.h"

t_default_TileGraphics::~t_default_TileGraphics(){
}

void t_default_TileGraphics::m_GetVisibleTiles(bbDouble l_x,bbDouble l_y,bbDouble l_scale,t_stdlib_math_types_Rect_1d l_camera){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Image* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  this->m_tileWidth=(bbDouble((f0.t0=this->m_images[bbInt(0)].get())->m_Width())*l_scale);
  this->m_tileHeight=(bbDouble((f0.t0=this->m_images[bbInt(0)].get())->m_Height())*l_scale);
  this->m_viewLeft=(l_camera.m_Left()-l_x);
  this->m_viewRight=(l_camera.m_Right()-l_x);
  this->m_viewTop=(l_camera.m_Top()-l_y);
  this->m_viewBottom=(l_camera.m_Bottom()-l_y);
  this->m_tileStartX=bbInt(std::floor((this->m_viewLeft/this->m_tileWidth)));
  this->m_tileStartY=bbInt(std::floor((this->m_viewTop/this->m_tileHeight)));
  this->m_tileEndX=bbInt(std::ceil((this->m_viewRight/this->m_tileWidth)));
  this->m_tileEndY=bbInt(std::ceil((this->m_viewBottom/this->m_tileHeight)));
}

void mx2_gridshooter_gamegraphics_2src_2tilegraphics_init_f(){
}
