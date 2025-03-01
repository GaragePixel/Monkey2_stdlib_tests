
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2gamegraphics.h"

#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_debug.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2image.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2texture.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2linear_2matrices_2affines_2affinemat3.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2rect.h"

BB_CLASS(t_sdk_0mojo_m2_graphics_Shader)

void g_default_GameGraphics_DrawRectOutline(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,bbInt l_left,bbInt l_top,bbInt l_width,bbInt l_height){
  l_canvas->m_DrawLine(bbFloat(l_left),bbFloat(l_top),bbFloat((l_left+l_width)),bbFloat(l_top));
  l_canvas->m_DrawLine(bbFloat(l_left),bbFloat(l_top),bbFloat(l_left),bbFloat((l_top+l_height)));
  l_canvas->m_DrawLine(bbFloat(l_left),bbFloat((l_top+l_height)),bbFloat((l_left+l_width)),bbFloat((l_top+l_height)));
  l_canvas->m_DrawLine(bbFloat((l_left+l_width)),bbFloat(l_top),bbFloat((l_left+l_width)),bbFloat((l_top+l_height)));
}

void t_default_GameGraphics::init(){
  m__0handle=t_stdlib_math_types_Vec2_1f{bbNullCtor};
}

void t_default_GameGraphics::gcMark(){
  bbGCMark(m_images);
}
t_default_GameGraphics::~t_default_GameGraphics(){
}

bbDouble t_default_GameGraphics::m_Width(){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Image* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return bbDouble((f0.t0=this->m_images[bbInt(0)].get())->m_Width());
}

bbArray<bbGCVar<t_sdk_0mojo_m2_graphics_Image>> t_default_GameGraphics::m_LoadFrames(bbString l_path,bbInt l_numFrames,bbInt l_cellWidth,bbInt l_cellHeight,bbBool l_filter,bbBool l_padded){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Image* l_atlasImg{};
    t_sdk_0mojo_m2_graphics_Texture* l_atlasTextture{};
    bbArray<bbGCVar<t_sdk_0mojo_m2_graphics_Image>> l_imgs{};
    void gcMark(){
      bbGCMark(l_atlasImg);
      bbGCMark(l_atlasTextture);
      bbGCMark(l_imgs);
    }
  }f0{};
  f0.l_atlasTextture=g_sdk_0mojo_m2_graphics_Texture_Load(l_path,t_sdk_0mojo_m2_graphics_TextureFlags(0),false);
  bbAssert(bbBool(f0.l_atlasTextture),((bbString(L" \n \nGameGraphics: Image ",24)+l_path)+bbString(L" not found.\n \n",14)));
  f0.l_atlasImg=bbGCNew<t_sdk_0mojo_m2_graphics_Image>(f0.l_atlasTextture,((t_sdk_0mojo_m2_graphics_Shader*)0));
  f0.l_imgs=bbArray<bbGCVar<t_sdk_0mojo_m2_graphics_Image>>(l_numFrames);
  if((bbFloat(l_cellHeight)==f0.l_atlasImg->m_Height())){
    bbInt l_x=bbInt(0);
    bbInt l_width=l_cellWidth;
    if(l_padded){
      l_x+=1;
      l_width-=2;
    }
    {
      bbInt l_i=bbInt(0);
      for(;(l_i<l_numFrames);l_i+=1){
        bbInt l_x0=((l_i*l_cellWidth)+l_x);
        bbInt l_y0=bbInt(0);
        f0.l_imgs[l_i]=bbGCNew<t_sdk_0mojo_m2_graphics_Image>(f0.l_atlasImg,t_stdlib_math_types_Rect_1i{l_x0,l_y0,(l_x0+l_cellWidth),l_cellHeight});
      }
    }
  }else{
    bbInt l_x=bbInt(0);
    bbInt l_width=l_cellWidth;
    bbInt l_y=bbInt(0);
    bbInt l_height=l_cellHeight;
    bbFloat l_columns=(f0.l_atlasImg->m_Width()/bbFloat(l_width));
    if(l_padded){
      l_x+=1;
      l_y+=1;
      l_width-=2;
      l_height-=2;
    }
    {
      bbInt l_i=bbInt(0);
      for(;(l_i<l_numFrames);l_i+=1){
        bbFloat l_fx=(std::fmod(bbFloat(l_i),l_columns)*bbFloat(l_cellWidth));
        bbFloat l_fy=((bbFloat(l_i)/l_columns)*bbFloat(l_cellHeight));
        f0.l_imgs[l_i]=bbGCNew<t_sdk_0mojo_m2_graphics_Image>(f0.l_atlasImg,t_stdlib_math_types_Rect_1i{bbInt((l_fx+bbFloat(l_x))),bbInt((l_fy+bbFloat(l_y))),bbInt((l_fx+bbFloat(l_cellWidth))),bbInt((l_fy+bbFloat(l_cellHeight)))});
      }
    }
  }
  f0.l_atlasImg=((t_sdk_0mojo_m2_graphics_Image*)0);
  return f0.l_imgs;
}

bbDouble t_default_GameGraphics::m_Height(){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Image* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return bbDouble((f0.t0=this->m_images[bbInt(0)].get())->m_Height());
}

void t_default_GameGraphics::m_Handle(t_stdlib_math_types_Vec2_1f l_handle){
  this->m__0handle=l_handle;
  {
    struct f1_t : public bbGCFrame{
      bbArray<bbGCVar<t_sdk_0mojo_m2_graphics_Image>> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    bbInt l_0=bbInt(0);
    bbInt l_1=(f1.t0=this->m_images).length();
    for(;(l_0<l_1);l_0+=1){
      struct f2_t : public bbGCFrame{
        t_sdk_0mojo_m2_graphics_Image* l_i{};
        void gcMark(){
          bbGCMark(l_i);
        }
      }f2{};
      f2.l_i=this->m_images[l_0].get();
      f2.l_i->m_Handle(this->m__0handle);
    }
  }
}

t_stdlib_math_types_Vec2_1f t_default_GameGraphics::m_Handle(){
  return this->m__0handle;
}

void t_default_GameGraphics::m_DrawOutline(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,bbFloat l_x,bbFloat l_y,bbFloat l_width,bbFloat l_height,bbFloat l_rz,bbFloat l_sx,bbFloat l_sy){
  t_stdlib_math_matrices_affinemat3_AffineMat3_1f l_matrix=l_canvas->m_Matrix();
  l_canvas->m_Translate(l_x,l_y);
  l_canvas->m_Rotate(l_rz);
  l_canvas->m_Scale(l_sx,l_sy);
  g_default_GameGraphics_DrawRectOutline(l_canvas,bbInt(-(l_width*this->m_Handle().m_X())),bbInt(-(l_height*this->m_Handle().m_Y())),bbInt(l_width),bbInt(l_height));
  l_canvas->m_Matrix(l_matrix);
}

void mx2_gridshooter_gamegraphics_2gamegraphics_init_f(){
}
