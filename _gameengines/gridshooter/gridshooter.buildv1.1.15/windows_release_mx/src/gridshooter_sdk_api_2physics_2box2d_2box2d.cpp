
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_sdk_api_2physics_2box2d_2box2d.h"

b2Vec2 g_sdk_api_box2d_Vec2_1d_to_Tb2Vec2_2(t_stdlib_math_types_Vec2_1d *l_self){
  return b2Vec2{bbFloat((*l_self).m_x),bbFloat((*l_self).m_y)};
}

x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d::~x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d(){
}

int bbCompare(const x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d&x,const x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d&y){
  return 0;
}

void mx2_gridshooter_sdk_api_2physics_2box2d_2box2d_init_f(){
}
