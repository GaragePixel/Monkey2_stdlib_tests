
#ifndef MX2_GRIDSHOOTER_SRC_2BULLET_H
#define MX2_GRIDSHOOTER_SRC_2BULLET_H

#include <bbmonkey.h>

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2actor.h"

BB_CLASS(t_default_Sprite)

BB_CLASS(t_default_Bullet)

struct t_default_Bullet : public t_default_Actor{
  typedef t_default_Bullet *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_Bullet";}

  t_default_Bullet(t_default_Sprite* l_sprite);
  ~t_default_Bullet();

  void m_OnUpdate();
  void m_OnReset();

  t_default_Bullet(){
  }
};

#endif
