
#include "commanche.buildv1.1.15/windows_release_mx/include/commanche_commanche.h"

#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_math.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2app.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2image.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2texture.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2input_2keyboard.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_resources_2graphics_2color.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_resources_2graphics_2pixmap.h"

BB_CLASS(t_sdk_0mojo_m2_graphics_Shader)
BB_ENUM(t_sdk_0mojo_m2_input_Key)
BB_ENUM(t_stdlib_graphics_PixelFormat)

extern bbFloat g_monkey_math_Abs_1f(bbFloat l_x);
bbInt g_default_WIDTH;
bbInt g_default_HEIGHT;
bbInt g_default_MAPW;
bbInt g_default_MAPH;
bbGCVar<t_stdlib_graphics_Pixmap> g_default_Cmap;
bbGCVar<t_stdlib_graphics_Pixmap> g_default_Dmap;
bbGCVar<t_stdlib_graphics_Pixmap> g_default_PmapDest;
bbGCVar<t_sdk_0mojo_m2_graphics_Image> g_default_image;
bbFloat g_default_depth;
bbGCVar<t_default_tCamera> g_default_Camera;

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_monkey_main();mx2_monkey_main();
  void mx2_sdk_0mojo_main();mx2_sdk_0mojo_main();
  void mx2_stdlib_main();mx2_stdlib_main();
  void mx2_commanche_commanche_init_f();mx2_commanche_commanche_init_f();
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_app_AppInstance* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  bbGCNew<t_sdk_0mojo_m2_app_AppInstance>();
  bb_print((bbString(L"W->",3)+g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyName(t_sdk_0mojo_m2_input_Key(65655))));
  bb_print((bbString(L"A->",3)+g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyName(t_sdk_0mojo_m2_input_Key(65633))));
  bb_print((bbString(L"S->",3)+g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyName(t_sdk_0mojo_m2_input_Key(65651))));
  bb_print((bbString(L"D->",3)+g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyName(t_sdk_0mojo_m2_input_Key(65636))));
  bbGCNew<t_default_MyWindow>(bbString(L"Commanche",9),(g_default_WIDTH*2),(g_default_HEIGHT*2),t_sdk_0mojo_m2_app_WindowFlags(0));
  (f0.t0=g_sdk_0mojo_m2_app_App.get())->m_Run();
}

t_default_tCamera::~t_default_tCamera(){
}

void t_default_MyWindow::gcMark(){
  t_sdk_0mojo_m2_app_Window::gcMark();
  bbGCMark(m_pm);
  bbGCMark(m_img);
}

t_default_MyWindow::t_default_MyWindow(bbString l_title,bbInt l_width,bbInt l_height,t_sdk_0mojo_m2_app_WindowFlags l_flags):t_sdk_0mojo_m2_app_Window(l_title,l_width,l_height,l_flags){
  g_default_Camera=bbGCNew<t_default_tCamera>();
  this->m_LoadMap();
  this->m_ClearColor(g_stdlib_graphics_Color_Black);
  this->m_SwapInterval(bbInt(0));
}
t_default_MyWindow::~t_default_MyWindow(){
}

void t_default_MyWindow::m_UpdateSim(){
  bbFloat l_sinang=bbFloat(std::sin(bbDouble(g_default_Camera.get()->m_angle)));
  bbFloat l_cosang=bbFloat(std::cos(bbDouble(g_default_Camera.get()->m_angle)));
  bbFloat l_y3d=(-g_default_depth*1.5f);
  {
    bbInt l_i=bbInt(0);
    for(;(l_i<g_default_WIDTH);l_i+=1){
      bbFloat l_x3d=((bbFloat((l_i-(g_default_WIDTH/2)))*1.5f)*1.5f);
      bbFloat l_rotx=((l_cosang*l_x3d)+(l_sinang*l_y3d));
      bbFloat l_roty=((-l_sinang*l_x3d)+(l_cosang*l_y3d));
      this->m_Raycast(l_i,g_default_Camera.get()->m_x,g_default_Camera.get()->m_y,(l_rotx+g_default_Camera.get()->m_x),(l_roty+g_default_Camera.get()->m_y),bbFloat((bbDouble(l_y3d)/std::sqrt(bbDouble(((l_x3d*l_x3d)+(l_y3d*l_y3d)))))));
    }
  }
}

void t_default_MyWindow::m_UpdateCamera(){
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(65633))){
    g_default_Camera.get()->m_angle+=0.034906584999999997f;
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(65651))){
    g_default_Camera.get()->m_x+=bbFloat((4.0*std::sin(bbDouble(g_default_Camera.get()->m_angle))));
    g_default_Camera.get()->m_y+=bbFloat((4.0*std::cos(bbDouble(g_default_Camera.get()->m_angle))));
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(65636))){
    g_default_Camera.get()->m_angle-=0.034906584999999997f;
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(65655))){
    g_default_Camera.get()->m_x-=bbFloat((4.0*std::sin(bbDouble(g_default_Camera.get()->m_angle))));
    g_default_Camera.get()->m_y-=bbFloat((4.0*std::cos(bbDouble(g_default_Camera.get()->m_angle))));
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(65650))){
    g_default_Camera.get()->m_height+=2.0f;
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(65638))){
    g_default_Camera.get()->m_height-=2.0f;
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(65649))){
    g_default_Camera.get()->m_v+=2.0f;
  }
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(65637))){
    g_default_Camera.get()->m_v-=2.0f;
  }
}

void t_default_MyWindow::m_Raycast(bbInt l_line,bbFloat l_x1,bbFloat l_y1,bbFloat l_x2,bbFloat l_y2,bbFloat l_d){
  bbFloat l_dx=(l_x2-l_x1);
  bbFloat l_dy=(l_y2-l_y1);
  bbFloat l_r=bbFloat(std::sqrt(bbDouble(((l_dx*l_dx)+(l_dy*l_dy)))));
  l_dx=(l_dx/l_r);
  l_dy=(l_dy/l_r);
  bbFloat l_ymin=256.0f;
  {
    bbInt l_i=1;
    for(;(bbFloat(l_i)<(l_r-20.0f));l_i+=1){
      struct f2_t : public bbGCFrame{
        t_stdlib_graphics_Pixmap* t0{};
        void gcMark(){
          bbGCMark(t0);
        }
      }f2{};
      l_x1+=l_dx;
      l_y1+=l_dy;
      bbInt l_h=bbInt((g_default_Camera.get()->m_height-bbFloat(bbInt((((f2.t0=g_default_Dmap.get())->m_GetPixelARGB((bbInt(l_x1)&1023),(bbInt(l_y1)&1023))>>16)&255u)))));
      bbFloat l_y3=(g_monkey_math_Abs_1f(l_d)*bbFloat(l_i));
      bbInt l_z3=bbInt((((bbFloat(l_h)/l_y3)*100.0f)-g_default_Camera.get()->m_v));
      if((l_z3<bbInt(0))){
        l_z3=bbInt(0);
      }
      if((l_z3<(g_default_HEIGHT-1))){
        struct f3_t : public bbGCFrame{
          t_stdlib_graphics_Pixmap* t0{};
          void gcMark(){
            bbGCMark(t0);
          }
        }f3{};
        bbUInt l_col=(f3.t0=g_default_Cmap.get())->m_GetPixelARGB((bbInt(l_x1)&1023),(bbInt(l_y1)&1023));
        {
          bbInt l_k=l_z3;
          for(;(bbFloat(l_k)<l_ymin);l_k+=1){
            struct f5_t : public bbGCFrame{
              t_stdlib_graphics_Pixmap* t0{};
              void gcMark(){
                bbGCMark(t0);
              }
            }f5{};
            (f5.t0=g_default_PmapDest.get())->m_SetPixelARGB(l_line,l_k,l_col);
          }
        }
        if((l_ymin>bbFloat(l_z3))){
          l_ymin=bbFloat(l_z3);
        }
      }
    }
  }
}

void t_default_MyWindow::m_OnRender(t_sdk_0mojo_m2_graphics_Canvas* l_canvas){
  struct f0_t : public bbGCFrame{
    t_stdlib_graphics_Pixmap* t0{};
    t_sdk_0mojo_m2_app_AppInstance* t1{};
    t_sdk_0mojo_m2_graphics_Image* t2{};
    t_sdk_0mojo_m2_graphics_Texture* t3{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
      bbGCMark(t2);
      bbGCMark(t3);
    }
  }f0{};
  (f0.t0=g_default_PmapDest.get())->m_Clear(g_stdlib_graphics_Color_Black);
  (f0.t1=g_sdk_0mojo_m2_app_App.get())->m_RequestRender();
  this->m_UpdateCamera();
  this->m_UpdateSim();
  (f0.t3=(f0.t2=g_default_image.get())->m_Texture())->m_PastePixmap(f0.t0=g_default_PmapDest.get(),bbInt(0),bbInt(0));
  l_canvas->m_DrawRect(0.0f,0.0f,bbFloat((g_default_WIDTH*2)),bbFloat((g_default_HEIGHT*2)),f0.t2=g_default_image.get());
  l_canvas->m_DrawText(bbString(g_sdk_0mojo_m2_app_App.get()->m_FPS()),10.0f,10.0f,0.0f,0.0f);
}

void t_default_MyWindow::m_LoadMap(){
  g_default_Dmap=g_stdlib_graphics_Pixmap_Load(bbString(L"asset::D1.png",13),t_stdlib_graphics_PixelFormat(5),false);
  g_default_Cmap=g_stdlib_graphics_Pixmap_Load(bbString(L"asset::C1W.png",14),t_stdlib_graphics_PixelFormat(5),false);
  if(!bbBool(g_default_Dmap.get())){
    bb_print(bbString(L"no Dmap!",8));
  }
  if(!bbBool(g_default_Cmap.get())){
    bb_print(bbString(L"no Cmap!",8));
  }
  g_default_PmapDest=bbGCNew<t_stdlib_graphics_Pixmap>(g_default_WIDTH,g_default_HEIGHT,t_stdlib_graphics_PixelFormat(5));
  g_default_image=bbGCNew<t_sdk_0mojo_m2_graphics_Image>(g_default_WIDTH,g_default_HEIGHT,t_sdk_0mojo_m2_graphics_TextureFlags(256),((t_sdk_0mojo_m2_graphics_Shader*)0));
}

void mx2_commanche_commanche_init_f(){
  g_default_WIDTH=512;
  g_default_HEIGHT=256;
  g_default_MAPW=1024;
  g_default_MAPH=1024;
  g_default_depth=400.0f;
}

struct mx2_commanche_commanche_roots_t : bbGCRoot{
  void gcMark(){
    bbGCMark(g_default_Cmap.get());
    bbGCMark(g_default_Dmap.get());
    bbGCMark(g_default_PmapDest.get());
    bbGCMark(g_default_image.get());
    bbGCMark(g_default_Camera.get());
  }
}mx2_commanche_commanche_roots;
