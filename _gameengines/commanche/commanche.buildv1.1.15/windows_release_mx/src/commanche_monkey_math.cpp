
#include "commanche.buildv1.1.15/windows_release_mx/include/commanche_monkey_math.h"

bbFloat g_monkey_math_Abs_1f(bbFloat l_x){
  if((l_x>=0.0f)){
    return l_x;
  }
  return -l_x;
}

void mx2_commanche_monkey_math_init_f(){
}
