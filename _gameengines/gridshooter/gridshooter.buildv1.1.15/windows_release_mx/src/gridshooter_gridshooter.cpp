
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gridshooter.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2background.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_gamegraphics_2src_2sprite.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2actor.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2area.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2bullet.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2orb.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_src_2player.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_collections_2stack.h"
#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_stdlib_math_2algebraic_2vectorials_2types_2rect.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2app_2app.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2canvas.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2graphics_2font.h"
#include "sdk_mojo/sdk_mojo.buildv1.1.15/windows_release_mx/include/sdk_0mojo_graphics_2mojo_2input_2keyboard.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_math_2algebraic_2vectorials_2types_2vec2.h"

BB_ENUM(t_sdk_0mojo_m2_app_WindowFlags)
BB_CLASS(t_sdk_0mojo_m2_graphics_Shader)
BB_ENUM(t_sdk_0mojo_m2_graphics_TextureFlags)
BB_ENUM(t_sdk_0mojo_m2_input_Key)

extern bbDouble g_monkey_math_Clamp_1d(bbDouble l_value,bbDouble l_min,bbDouble l_max);
extern void g_stdlib_math_random_SeedRnd(bbULong l_seed);
bbFloat g_default_Game_cameraSpeed;
bbDouble g_default_Game_scrollLimitY;
bbFloat g_default_Game_scrollSpeed;

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_monkey_main();mx2_monkey_main();
  void mx2_sdk_main();mx2_sdk_main();
  void mx2_sdk_0mojo_main();mx2_sdk_0mojo_main();
  void mx2_stdlib_main();mx2_stdlib_main();
  void mx2_gridshooter_monkey_math_init_f();mx2_gridshooter_monkey_math_init_f();
  void mx2_gridshooter_sdk_api_2physics_2box2d_2box2d_init_f();mx2_gridshooter_sdk_api_2physics_2box2d_2box2d_init_f();
  void mx2_gridshooter_stdlib_collections_2map_init_f();mx2_gridshooter_stdlib_collections_2map_init_f();
  void mx2_gridshooter_stdlib_collections_2deque_init_f();mx2_gridshooter_stdlib_collections_2deque_init_f();
  void mx2_gridshooter_stdlib_collections_2list_init_f();mx2_gridshooter_stdlib_collections_2list_init_f();
  void mx2_gridshooter_stdlib_collections_2stack_init_f();mx2_gridshooter_stdlib_collections_2stack_init_f();
  void mx2_gridshooter_stdlib_collections_2container_init_f();mx2_gridshooter_stdlib_collections_2container_init_f();
  void mx2_gridshooter_stdlib_math_2algebraic_2vectorials_2types_2rect_init_f();mx2_gridshooter_stdlib_math_2algebraic_2vectorials_2types_2rect_init_f();
  void mx2_gridshooter_gamegraphics_2src_2sprite_init_f();mx2_gridshooter_gamegraphics_2src_2sprite_init_f();
  void mx2_gridshooter_gamegraphics_2src_2tilegraphics_init_f();mx2_gridshooter_gamegraphics_2src_2tilegraphics_init_f();
  void mx2_gridshooter_gamegraphics_2src_2background_init_f();mx2_gridshooter_gamegraphics_2src_2background_init_f();
  void mx2_gridshooter_gamegraphics_2gamegraphics_init_f();mx2_gridshooter_gamegraphics_2gamegraphics_init_f();
  void mx2_gridshooter_src_2area_init_f();mx2_gridshooter_src_2area_init_f();
  void mx2_gridshooter_src_2renderwindow_init_f();mx2_gridshooter_src_2renderwindow_init_f();
  void mx2_gridshooter_src_2actor_init_f();mx2_gridshooter_src_2actor_init_f();
  void mx2_gridshooter_src_2player_init_f();mx2_gridshooter_src_2player_init_f();
  void mx2_gridshooter_src_2bullet_init_f();mx2_gridshooter_src_2bullet_init_f();
  void mx2_gridshooter_src_2orb_init_f();mx2_gridshooter_src_2orb_init_f();
  void mx2_gridshooter_gridshooter_init_f();mx2_gridshooter_gridshooter_init_f();
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_app_AppInstance* t0{};
    void gcMark(){
      bbGCMark(t0);
    }
  }f0{};
  bbGCNew<t_sdk_0mojo_m2_app_AppInstance>();
  bbGCNew<t_default_Game>();
  (f0.t0=g_sdk_0mojo_m2_app_App.get())->m_Run();
}

void t_default_Game::init(){
  m_colorTint=t_stdlib_graphics_Color{0.25f,1.0f,0.5f,1.0f};
}

void t_default_Game::gcMark(){
  t_default_RenderWindow::gcMark();
  bbGCMark(m_hero);
  bbGCMark(m_bg);
  bbGCMark(m_bgGrid);
  bbGCMark(m_smallFont);
}

t_default_Game::t_default_Game():t_default_RenderWindow(bbString(L"Test",4),420,240,false,true,t_sdk_0mojo_m2_app_WindowFlags(8)){
  init();
  this->m_Layout(bbString(L"letterbox-int",13));
}
t_default_Game::~t_default_Game(){
}

void t_default_Game::m_OnUpdate(){
  struct f0_t : public bbGCFrame{
    t_default_Area_1d* t0{};
    t_default_Area_1d* t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  (f0.t1=this->m_camera.get())->m_X(((f0.t0=this->m_camera.get())->m_X()+bbDouble(g_default_Game_scrollSpeed)));
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(210))){
    struct f1_t : public bbGCFrame{
      t_default_Area_1d* t0{};
      t_default_Area_1d* t1{};
      void gcMark(){
        bbGCMark(t0);
        bbGCMark(t1);
      }
    }f1{};
    (f1.t1=this->m_camera.get())->m_Y(((f1.t0=this->m_camera.get())->m_Y()-bbDouble(g_default_Game_cameraSpeed)));
  }else if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyDown(t_sdk_0mojo_m2_input_Key(209))){
    struct f1_t : public bbGCFrame{
      t_default_Area_1d* t0{};
      t_default_Area_1d* t1{};
      void gcMark(){
        bbGCMark(t0);
        bbGCMark(t1);
      }
    }f1{};
    (f1.t1=this->m_camera.get())->m_Y(((f1.t0=this->m_camera.get())->m_Y()+bbDouble(g_default_Game_cameraSpeed)));
  }
  (f0.t1=this->m_camera.get())->m_Y(g_monkey_math_Clamp_1d((f0.t0=this->m_camera.get())->m_Y(),-g_default_Game_scrollLimitY,g_default_Game_scrollLimitY));
  g_default_Actor_UpdateAll();
  if(g_sdk_0mojo_m2_input_Keyboard.get()->m_KeyHit(t_sdk_0mojo_m2_input_Key(100),false)){
    this->m_debug=!this->m_debug;
  }
}

void t_default_Game::m_OnStart(){
  struct f0_t : public bbGCFrame{
    t_default_Sprite* l_bulletSprite{};
    t_default_Sprite* l_heroSprite{};
    t_default_Sprite* l_jetSprite{};
    t_default_Sprite* l_orbSprite{};
    t_sdk_0mojo_m2_graphics_Font* t0{};
    t_sdk_0mojo_m2_graphics_Canvas* t1{};
    bbArray<bbInt> t2{};
    void gcMark(){
      bbGCMark(l_bulletSprite);
      bbGCMark(l_heroSprite);
      bbGCMark(l_jetSprite);
      bbGCMark(l_orbSprite);
      bbGCMark(t0);
      bbGCMark(t1);
      bbGCMark(t2);
    }
  }f0{};
  g_default_Actor_camera=this->m_camera.get();
  (f0.t1=this->m_canvas.get())->m_Font(f0.t0=g_sdk_0mojo_m2_graphics_Font_Load(bbString(L"asset::classic_sans.ttf",23),10.0f,((t_sdk_0mojo_m2_graphics_Shader*)0),t_sdk_0mojo_m2_graphics_TextureFlags(12)));
  this->m_bg=bbGCNew<t_default_Background>(bbString(L"asset::starfield.png",20));
  this->m_bgGrid=bbGCNew<t_default_Background>(bbString(L"asset::grid.png",15));
  f0.l_heroSprite=bbGCNew<t_default_Sprite>(bbString(L"asset::hero.png",15),3,32,32,false);
  f0.l_heroSprite->m_AddAnimationClip(bbString(L"idle",4),f0.t2=bbArray<bbInt>({bbInt(0)},1),true);
  f0.l_heroSprite->m_AddAnimationClip(bbString(L"up",2),f0.t2=bbArray<bbInt>({1},1),true);
  f0.l_heroSprite->m_AddAnimationClip(bbString(L"down",4),f0.t2=bbArray<bbInt>({2},1),true);
  f0.l_jetSprite=bbGCNew<t_default_Sprite>(bbString(L"asset::jet.png",14),2,16,16,false);
  f0.l_jetSprite->m_AddAnimationClip(bbString(L"idle",4),f0.t2=bbArray<bbInt>({bbInt(0),1},2),true);
  f0.l_jetSprite->m_frameRate=30;
  f0.l_bulletSprite=bbGCNew<t_default_Sprite>(bbString(L"asset::bullet.png",17),5,32,32,false);
  f0.l_bulletSprite->m_AddAnimationClip(bbString(L"idle",4),f0.t2=bbArray<bbInt>({bbInt(0)},1),true);
  f0.l_bulletSprite->m_AddAnimationClip(bbString(L"hit",3),f0.t2=bbArray<bbInt>({1,2,3,4},4),false);
  f0.l_bulletSprite->m_frameRate=15;
  f0.l_orbSprite=bbGCNew<t_default_Sprite>(bbString(L"asset::orbSmall.png",19),5,16,16,false);
  f0.l_orbSprite->m_AddAnimationClip(bbString(L"idle",4),f0.t2=bbArray<bbInt>({bbInt(0),1,2,3},4),true);
  this->m_hero=bbGCNew<t_default_Player>(f0.l_heroSprite);
  g_stdlib_math_random_SeedRnd(12345ul);
  bbInt l_offset=bbInt(0);
  {
    bbInt l_n=bbInt(0);
    for(;(l_n<20);l_n+=1){
      struct f2_t : public bbGCFrame{
        t_default_Orb* l_neworb{};
        void gcMark(){
          bbGCMark(l_neworb);
        }
      }f2{};
      f2.l_neworb=bbGCNew<t_default_Orb>(f0.l_orbSprite);
      f2.l_neworb->m_Reset();
      f2.l_neworb->m_position.m_X((f2.l_neworb->m_position.m_X()+bbDouble(l_offset)));
      l_offset+=16;
    }
  }
  {
    bbInt l_n=bbInt(0);
    for(;(l_n<10);l_n+=1){
      struct f2_t : public bbGCFrame{
        t_default_Bullet* l_b{};
        t_stdlib_collections_Stack_1Tt_default_Bullet_2* t0{};
        void gcMark(){
          bbGCMark(l_b);
          bbGCMark(t0);
        }
      }f2{};
      f2.l_b=bbGCNew<t_default_Bullet>(f0.l_bulletSprite);
      (f2.t0=g_default_Actor_bulletPool.get())->m_Push(f2.l_b);
    }
  }
  g_default_Actor_player=((t_default_Actor*)(this->m_hero.get()));
  g_default_Actor_cullDistance=bbDouble(this->m_Width());
  (f0.t1=this->m_canvas.get())->m_TextureFilteringEnabled(false);
}

void t_default_Game::m_OnDraw(){
  struct f0_t : public bbGCFrame{
    t_sdk_0mojo_m2_graphics_Canvas* t0{};
    t_default_Background* t1{};
    void gcMark(){
      bbGCMark(t0);
      bbGCMark(t1);
    }
  }f0{};
  (f0.t0=this->m_canvas.get())->m_Color(this->m_colorTint);
  (f0.t0=this->m_canvas.get())->m_Alpha(1.0f);
  this->m_Parallax(0.10000000000000001f);
  (f0.t1=this->m_bg.get())->m_Draw(f0.t0=this->m_canvas.get(),0.0,0.0,1.0,this->m_CameraRect());
  (f0.t0=this->m_canvas.get())->m_Alpha(0.5f);
  (f0.t0=this->m_canvas.get())->m_DrawText(bbString(L"Monkey2 Side Scrolling Demo by Leo Santos. Press space to shoot!",64),260.0f,100.0f,0.0f,0.0f);
  (f0.t0=this->m_canvas.get())->m_Alpha(0.25f);
  this->m_Parallax(0.25f);
  (f0.t1=this->m_bgGrid.get())->m_Draw(f0.t0=this->m_canvas.get(),32.0,32.0,1.0,this->m_CameraRect());
  (f0.t0=this->m_canvas.get())->m_Alpha(0.5f);
  this->m_Parallax(1.0f);
  (f0.t1=this->m_bgGrid.get())->m_Draw(f0.t0=this->m_canvas.get(),0.0,0.0,1.0,this->m_CameraRect());
  (f0.t0=this->m_canvas.get())->m_Alpha(1.0f);
  (f0.t0=this->m_canvas.get())->m_Color(g_stdlib_graphics_Color_White);
  g_default_Actor_DrawAll(f0.t0=this->m_canvas.get());
}

void mx2_gridshooter_gridshooter_init_f(){
  g_default_Game_cameraSpeed=1.0f;
  g_default_Game_scrollLimitY=60.0;
  g_default_Game_scrollSpeed=5.0f;
}
