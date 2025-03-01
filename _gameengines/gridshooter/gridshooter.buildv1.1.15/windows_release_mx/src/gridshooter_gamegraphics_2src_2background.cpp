
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2background.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_math_2algebraic_2vectorials_2types_2rect.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_debug.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2image.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2texture.h"

BB_CLASS(t_sdk_0mojo_m2_graphics_Shader)

extern void g_default_GameGraphics_DrawRectOutline(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,bbInt l_left,bbInt l_top,bbInt l_width,bbInt l_height);
t_default_Background::t_default_Background(bbString l_path){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Texture* l_atlasTextture{};
    t_sdk_0mojo_m2_graphics_Image* t0{};
    void gcMark(){
      bbGCMark(l_atlasTextture);
      bbGCMark(t0);
    }
  }f0{};
  f0.l_atlasTextture=g_sdk_0mojo_m2_graphics_Texture_Load(l_path,t_sdk_0mojo_m2_graphics_TextureFlags(0),false);
  bbAssert(bbBool(f0.l_atlasTextture),((bbString(L" \n \nGameGraphics: Image ",24)+l_path)+bbString(L" not found.\n \n",14)));
  this->m_images=bbArray<bbGCVar<t_sdk_0mojo_m2_graphics_Image>>({f0.t0=bbGCNew<t_sdk_0mojo_m2_graphics_Image>(f0.l_atlasTextture,((t_sdk_0mojo_m2_graphics_Shader*)0))},1);
}
t_default_Background::~t_default_Background(){
}

bbString t_default_Background::m_ToString(){
  bbString l_t=bbString{};
  l_t+=((((((((bbString(L"Background: ",12)+bbString(this->m_tileStartX))+bbString(L",",1))+bbString(this->m_tileStartY))+bbString(L"; ",2))+bbString(this->m_tileEndX))+bbString(L",",1))+bbString(this->m_tileEndY))+bbString(L"; ",2));
  l_t+=(bbString(L"Total tiles: ",13)+bbString(this->m_total));
  return l_t;
}

void t_default_Background::m_Draw(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,bbDouble l_x,bbDouble l_y,bbDouble l_scale,t_stdlib_math_types_Rect_1d l_camera){
  this->m_total=bbInt(0);
  this->m_GetVisibleTiles(l_x,l_y,l_scale,l_camera);
  {
    bbInt l_tY=this->m_tileStartY;
    for(;(l_tY<this->m_tileEndY);l_tY+=1){
      {
        bbInt l_tX=this->m_tileStartX;
        for(;(l_tX<this->m_tileEndX);l_tX+=1){
          bbDouble l_absX=((bbDouble(l_tX)*this->m_tileWidth)+l_x);
          bbDouble l_absY=((bbDouble(l_tY)*this->m_tileHeight)+l_y);
          if(bbBool(this->m_images[bbInt(0)].get())){
            struct f5_t : public bbGCFrame{
              t_sdk_0mojo_m2_graphics_Image* t0{};
              void gcMark(){
                bbGCMark(t0);
              }
            }f5{};
            this->m_total+=1;
            l_canvas->m_DrawImage(f5.t0=this->m_images[bbInt(0)].get(),bbFloat(l_absX),bbFloat(l_absY),0.0f,bbFloat(l_scale),bbFloat(l_scale));
            if(this->m_debug){
              g_default_GameGraphics_DrawRectOutline(l_canvas,bbInt(l_absX),bbInt(l_absY),bbInt(this->m_tileWidth),bbInt(this->m_tileHeight));
              l_canvas->m_DrawText(((bbString(l_tX)+bbString(L",",1))+bbString(l_tY)),bbFloat((l_absX+4.0)),bbFloat((l_absY+4.0)),0.0f,0.0f);
            }
          }
        }
      }
    }
  }
}

void mx2_gridshooter_gamegraphics_2src_2background_init_f(){
}
