
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2player.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2area.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2bullet.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2stack.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2input_2keyboard.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

BB_ENUM(t_sdk_0mojo_m2_input_Key)

extern bbDouble g_monkey_math_Clamp_1d(bbDouble l_value,bbDouble l_min,bbDouble l_max);
t_default_Player::t_default_Player(t_default_Sprite* l_sprite):t_default_Actor(l_sprite){
  this->m_name=bbString(L"player",6);
}
t_default_Player::~t_default_Player(){
}

void t_default_Player::m_OnUpdate(){
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(208))){
    this->m_position.m_X((this->m_position.m_X()-this->m_speed));
  }else if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(207))){
    this->m_position.m_X((this->m_position.m_X()+this->m_speed));
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(210))){
    this->m_position.m_Y((this->m_position.m_Y()-this->m_speed));
  }else if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(209))){
    this->m_position.m_Y((this->m_position.m_Y()+this->m_speed));
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyHit(t_sdk_0mojo_m2_input_Key(32),false)){
    struct f1_t : public bbGCFrame{
      t_default_Bullet* l_bullet{};
      t_stdlib_collections_Stack_1Tt_default_Bullet_2* t0{};
      void gcMark(){
        bbGCMark(l_bullet);
        bbGCMark(t0);
      }
    }f1{};
    f1.l_bullet=(f1.t0=g_default_Actor_bulletPool.get())->m_Get(g_default_Actor_currentBullet);
    f1.l_bullet->m_Reset();
    f1.l_bullet->m_visible=true;
    f1.l_bullet->m_position.m_X(this->m_position.m_X());
    f1.l_bullet->m_position.m_Y((this->m_position.m_Y()+4.0));
    g_default_Actor_currentBullet+=1;
    if((g_default_Actor_currentBullet>9)){
      g_default_Actor_currentBullet=bbInt(0);
    }
  }
  this->m_position.m_X(g_monkey_math_Clamp_1d(this->m_position.m_X(),g_default_Actor_camera.get()->m_Left(),g_default_Actor_camera.get()->m_Right()));
  this->m_position.m_Y(g_monkey_math_Clamp_1d(this->m_position.m_Y(),g_default_Actor_camera.get()->m_Top(),g_default_Actor_camera.get()->m_Bottom()));
  if((this->m_position.m_Y()>this->m_oldY)){
    this->m_anim=bbString(L"down",4);
  }else if((this->m_position.m_Y()<this->m_oldY)){
    this->m_anim=bbString(L"up",2);
  }else{
    this->m_anim=bbString(L"idle",4);
  }
  this->m_oldY=this->m_position.m_Y();
}

void mx2_gridshooter_src_2player_init_f(){
}
