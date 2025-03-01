
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2sprite.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2map.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2image.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

extern bbInt g_monkey_math_Clamp_1i(bbInt l_value,bbInt l_min,bbInt l_max);
extern bbInt g_stdlib_system_time_Millisecs();
void t_default_Sprite::init(){
  m_animations=bbGCNew<t_stdlib_collections_Map_1sTt_default_AnimationClip_2>();
  m__0anim=bbString{};
}

void t_default_Sprite::gcMark(){
  t_default_GameGraphics::gcMark();
  bbGCMark(m_animations);
}

t_default_Sprite::t_default_Sprite(bbString l_ImagePath,bbInt l_Totalframes,bbInt l_cellWidth,bbInt l_cellHeight,bbBool l_filter){
  init();
  this->m_images=this->m_LoadFrames(l_ImagePath,l_Totalframes,l_cellWidth,l_cellHeight,l_filter,false);
  this->m_Handle(t_stdlib_math_types_Vec2_1f{0.5f,0.5f});
  this->m_Reset();
}
t_default_Sprite::~t_default_Sprite(){
}

void t_default_Sprite::m_Reset(){
  this->m__0startTime=g_stdlib_system_time_Millisecs();
}

bbInt t_default_Sprite::m_Duration(bbString l_anim){
  struct f0_t : public bbGCFrame{
    t_default_AnimationClip* l_a{};
    t_stdlib_collections_Map_1sTt_default_AnimationClip_2* t0{};
    void gcMark(){
      bbGCMark(l_a);
      bbGCMark(t0);
    }
  }f0{};
  f0.l_a=(f0.t0=this->m_animations.get())->m_Get(l_anim);
  if(!bbBool(f0.l_a)){
    return bbInt(0);
  }
  this->m__0period=bbInt((bbFloat((1000/this->m_frameRate))/this->m_timeScale));
  return (this->m__0period*f0.l_a->m_Count());
}

void t_default_Sprite::m_Draw(t_sdk_0mojo_m2_graphics_Canvas* l_canvas,bbString l_anim,bbFloat l_x,bbFloat l_y,bbFloat l_rotation,bbFloat l_scaleX,bbFloat l_scaleY,bbInt l_time){
  struct f0_t : public bbGCFrame{
    t_default_AnimationClip* l__0anim{};
    t_stdlib_collections_Map_1sTt_default_AnimationClip_2* t0{};
    void gcMark(){
      bbGCMark(l__0anim);
      bbGCMark(t0);
    }
  }f0{};
  f0.l__0anim=(f0.t0=this->m_animations.get())->m_Get(l_anim);
  if((this->m_debug||!bbBool(f0.l__0anim))){
    struct f1_t : public bbGCFrame{
      t_sdk_0mojo_m2_graphics_Image* t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    bbFloat l_w=(f1.t0=this->m_images[this->m__0frame].get())->m_Width();
    bbFloat l_h=(f1.t0=this->m_images[this->m__0frame].get())->m_Height();
    this->m_DrawOutline(l_canvas,l_x,l_y,l_w,l_h,l_rotation,l_scaleX,l_scaleY);
  }
  if(!bbBool(f0.l__0anim)){
    l_canvas->m_DrawText(((bbString(L"Sprite: AnimationClip '",23)+l_anim)+bbString(L"' is undefined",14)),l_x,l_y,0.0f,0.0f);
    return;
  }
  if((l_time<bbInt(0))){
    this->m__0time=(g_stdlib_system_time_Millisecs()-this->m__0startTime);
  }else{
    this->m__0time=l_time;
  }
  this->m__0period=bbInt((bbFloat((1000/this->m_frameRate))/this->m_timeScale));
  if(f0.l__0anim->m_loop){
    struct f1_t : public bbGCFrame{
      bbArray<bbInt> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    this->m__0listFrame=(this->m__0time%((f1.t0=f0.l__0anim->m_frame).length()*this->m__0period));
    this->m__0clampedListFrame=g_monkey_math_Clamp_1i((this->m__0listFrame/this->m__0period),bbInt(0),((f1.t0=f0.l__0anim->m_frame).length()-1));
  }else{
    struct f1_t : public bbGCFrame{
      bbArray<bbInt> t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    this->m__0clampedListFrame=g_monkey_math_Clamp_1i((this->m__0time/this->m__0period),bbInt(0),((f1.t0=f0.l__0anim->m_frame).length()-1));
  }
  this->m__0frame=f0.l__0anim->m_frame[this->m__0clampedListFrame];
  if(bbBool(this->m_images)){
    struct f1_t : public bbGCFrame{
      t_sdk_0mojo_m2_graphics_Image* t0{};
      void gcMark(){
        bbGCMark(t0);
      }
    }f1{};
    l_canvas->m_DrawImage(f1.t0=this->m_images[this->m__0frame].get(),l_x,l_y,l_rotation,l_scaleX,l_scaleY);
  }else{
    l_canvas->m_DrawText(bbString(L"Sprite: No image loaded",23),l_x,l_y,0.0f,0.0f);
  }
}

void t_default_Sprite::m_AddAnimationClip(bbString l__0id,bbArray<bbInt> l__0frames,bbBool l__0loop){
  struct f0_t : public bbGCFrame{
    t_default_AnimationClip* l_animClip{};
    t_stdlib_collections_Map_1sTt_default_AnimationClip_2* t0{};
    void gcMark(){
      bbGCMark(l_animClip);
      bbGCMark(t0);
    }
  }f0{};
  f0.l_animClip=bbGCNew<t_default_AnimationClip>();
  f0.l_animClip->m_id=l__0id;
  f0.l_animClip->m_loop=l__0loop;
  f0.l_animClip->m_frame=l__0frames;
  (f0.t0=this->m_animations.get())->m_Add(l__0id,f0.l_animClip);
}

void t_default_AnimationClip::gcMark(){
  bbGCMark(m_frame);
}
t_default_AnimationClip::~t_default_AnimationClip(){
}

bbInt t_default_AnimationClip::m_Count(){
  struct f0_t : public bbGCFrame{
    bbArray<bbInt> t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  return (f0.t0=this->m_frame).length();
}

void mx2_gridshooter_gamegraphics_2src_2sprite_init_f(){
}
