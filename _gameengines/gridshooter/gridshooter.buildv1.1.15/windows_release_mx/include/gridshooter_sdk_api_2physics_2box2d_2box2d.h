
#ifndef MX2_GRIDSHOOTER_SDK_API_2PHYSICS_2BOX2D_2BOX2D_H
#define MX2_GRIDSHOOTER_SDK_API_2PHYSICS_2BOX2D_2BOX2D_H

#include <bbmonkey.h>
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2box2d_2box2d.h"
#include "sdk/api/physics/box2d/Box2D/Box2D_mx2.h"

#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_api_2physics_2box2d_2box2d.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

BB_STRUCT(x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d)

b2Vec2 g_sdk_api_box2d_Vec2_1d_to_Tb2Vec2_2(t_stdlib_math_types_Vec2_1d *l_self);

struct x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d : public t_stdlib_math_types_Vec2_1d{
  typedef x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d bb_struct_type;

  using t_stdlib_math_types_Vec2_1d::m_to_s;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d";}

  ~x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d();

  x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d(){
  }

  x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d(bbNullCtor_t){
  }
};

int bbCompare(const x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d&x,const x_sdk_api_box2d_Vec2_1d_gridshooter_sdk_api_2physics_2box2d_2box2d&y);

#endif
