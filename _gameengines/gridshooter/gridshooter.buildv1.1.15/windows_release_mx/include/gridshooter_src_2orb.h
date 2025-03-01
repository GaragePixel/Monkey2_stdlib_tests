
#ifndef MX2_GRIDSHOOTER_SRC_2ORB_H
#define MX2_GRIDSHOOTER_SRC_2ORB_H

#include <bbmonkey.h>

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2actor.h"

BB_CLASS(t_default_Sprite)

BB_CLASS(t_default_Orb)

extern bbDouble g_default_Orb_cullDistance;

struct t_default_Orb : public t_default_Actor{
  typedef t_default_Orb *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_default_Orb";}

  t_default_Orb(t_default_Sprite* l_sprite);
  ~t_default_Orb();

  void m_OnUpdate();
  void m_OnReset();

  t_default_Orb(){
  }
};

#endif
