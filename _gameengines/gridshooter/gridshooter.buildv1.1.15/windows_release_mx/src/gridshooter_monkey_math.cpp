
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_monkey_math.h"

bbDouble g_monkey_math_Clamp_1d(bbDouble l_value,bbDouble l_min,bbDouble l_max){
  if((l_value<=l_min)){
    return l_min;
  }
  if((l_value>=l_max)){
    return l_max;
  }
  return l_value;
}

bbDouble g_monkey_math_Max_1d(bbDouble l_x,bbDouble l_y){
  if((l_x>=l_y)){
    return l_x;
  }
  return l_y;
}

bbDouble g_monkey_math_Min_1d(bbDouble l_x,bbDouble l_y){
  if((l_x<=l_y)){
    return l_x;
  }
  return l_y;
}

void mx2_gridshooter_monkey_math_init_f(){
}
