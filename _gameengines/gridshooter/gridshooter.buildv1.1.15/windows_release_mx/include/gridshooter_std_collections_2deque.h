
#ifndef MX2_GRIDSHOOTER_STD_COLLECTIONS_2DEQUE_H
#define MX2_GRIDSHOOTER_STD_COLLECTIONS_2DEQUE_H

#include <bbmonkey.h>
#include "std/std.buildv1.1.15/windows_release_mx/include/std_collections_2deque.h"

#include "gridshooter.buildv1.1.15/windows_release_mx/include/gridshooter_std_collections_2container.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"

BB_CLASS(t_default_Actor)
BB_CLASS(t_default_Bullet)

BB_STRUCT(t_std_collections_Deque_1Tt_default_Bullet_2_Iterator)
BB_CLASS(t_std_collections_Deque_1Tt_default_Bullet_2)
BB_STRUCT(t_std_collections_Deque_1Tt_default_Actor_2_Iterator)
BB_CLASS(t_std_collections_Deque_1Tt_default_Actor_2)

struct t_std_collections_Deque_1Tt_default_Bullet_2_Iterator : public virtual t_std_collections_IIterator_1Tt_default_Bullet_2{
  typedef t_std_collections_Deque_1Tt_default_Bullet_2_Iterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Deque_1Tt_default_Bullet_2_Iterator";}

  bbGCVar<t_std_collections_Deque_1Tt_default_Bullet_2> m__0deque{};
  bbInt m__0index{};

  t_std_collections_Deque_1Tt_default_Bullet_2_Iterator(t_std_collections_Deque_1Tt_default_Bullet_2* l_deque,bbInt l_index);
  ~t_std_collections_Deque_1Tt_default_Bullet_2_Iterator();

  void m_Insert(t_default_Bullet* l_value);
  void m_Erase();
  void m_Current(t_default_Bullet* l_current);
  t_default_Bullet* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_std_collections_Deque_1Tt_default_Bullet_2_Iterator(){
  }

  t_std_collections_Deque_1Tt_default_Bullet_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Deque_1Tt_default_Bullet_2_Iterator&x,const t_std_collections_Deque_1Tt_default_Bullet_2_Iterator&y);

void bbGCMark(const t_std_collections_Deque_1Tt_default_Bullet_2_Iterator&);

struct t_std_collections_Deque_1Tt_default_Bullet_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_default_Bullet_2{
  typedef t_std_collections_Deque_1Tt_default_Bullet_2 *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Deque_1Tt_default_Bullet_2";}

  bbArray<bbGCVar<t_default_Bullet>> m__0data{};
  bbInt m__0head{};
  bbInt m__0tail{};

  void gcMark();

  t_std_collections_Deque_1Tt_default_Bullet_2(bbInt l_length);
  t_std_collections_Deque_1Tt_default_Bullet_2();
  ~t_std_collections_Deque_1Tt_default_Bullet_2();

  void m__idxeq(bbInt l_index,t_default_Bullet* l_value);
  t_default_Bullet* m__idx(bbInt l_index);
  bbArray<bbGCVar<t_default_Bullet>> m_ToArray();
  void m_Set(bbInt l_index,t_default_Bullet* l_value);
  void m_Reserve(bbInt l_capacity);
  t_default_Bullet* m_RemoveLast();
  t_default_Bullet* m_RemoveFirst();
  void m_PushLast(t_default_Bullet* l_value);
  void m_PushFirst(t_default_Bullet* l_value);
  t_default_Bullet* m_PopLast();
  t_default_Bullet* m_PopFirst();
  void m_Normalize(bbInt l_capacity);
  bbInt m_Length();
  t_default_Bullet* m_Last();
  t_default_Bullet* m_Get(bbInt l_index);
  t_default_Bullet* m_First();
  bbBool m_Empty();
  bbArray<bbGCVar<t_default_Bullet>> m_Data();
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Deque_1Tt_default_Bullet_2_Iterator m_All();
  void m_AddLast(t_default_Bullet* l_value);
  void m_AddFirst(t_default_Bullet* l_value);
};

struct t_std_collections_Deque_1Tt_default_Actor_2_Iterator : public virtual t_std_collections_IIterator_1Tt_default_Actor_2{
  typedef t_std_collections_Deque_1Tt_default_Actor_2_Iterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Deque_1Tt_default_Actor_2_Iterator";}

  bbGCVar<t_std_collections_Deque_1Tt_default_Actor_2> m__0deque{};
  bbInt m__0index{};

  t_std_collections_Deque_1Tt_default_Actor_2_Iterator(t_std_collections_Deque_1Tt_default_Actor_2* l_deque,bbInt l_index);
  ~t_std_collections_Deque_1Tt_default_Actor_2_Iterator();

  void m_Insert(t_default_Actor* l_value);
  void m_Erase();
  void m_Current(t_default_Actor* l_current);
  t_default_Actor* m_Current();
  void m_Bump();
  bbBool m_AtEnd();
  void m_AssertCurrent();

  t_std_collections_Deque_1Tt_default_Actor_2_Iterator(){
  }

  t_std_collections_Deque_1Tt_default_Actor_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Deque_1Tt_default_Actor_2_Iterator&x,const t_std_collections_Deque_1Tt_default_Actor_2_Iterator&y);

void bbGCMark(const t_std_collections_Deque_1Tt_default_Actor_2_Iterator&);

struct t_std_collections_Deque_1Tt_default_Actor_2 : public bbObject,public virtual t_std_collections_IContainer_1Tt_default_Actor_2{
  typedef t_std_collections_Deque_1Tt_default_Actor_2 *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Deque_1Tt_default_Actor_2";}

  bbArray<bbGCVar<t_default_Actor>> m__0data{};
  bbInt m__0head{};
  bbInt m__0tail{};

  void gcMark();

  t_std_collections_Deque_1Tt_default_Actor_2(bbInt l_length);
  t_std_collections_Deque_1Tt_default_Actor_2();
  ~t_std_collections_Deque_1Tt_default_Actor_2();

  void m__idxeq(bbInt l_index,t_default_Actor* l_value);
  t_default_Actor* m__idx(bbInt l_index);
  bbArray<bbGCVar<t_default_Actor>> m_ToArray();
  void m_Set(bbInt l_index,t_default_Actor* l_value);
  void m_Reserve(bbInt l_capacity);
  t_default_Actor* m_RemoveLast();
  t_default_Actor* m_RemoveFirst();
  void m_PushLast(t_default_Actor* l_value);
  void m_PushFirst(t_default_Actor* l_value);
  t_default_Actor* m_PopLast();
  t_default_Actor* m_PopFirst();
  void m_Normalize(bbInt l_capacity);
  bbInt m_Length();
  t_default_Actor* m_Last();
  t_default_Actor* m_Get(bbInt l_index);
  t_default_Actor* m_First();
  bbBool m_Empty();
  bbArray<bbGCVar<t_default_Actor>> m_Data();
  void m_Clear();
  bbInt m_Capacity();
  t_std_collections_Deque_1Tt_default_Actor_2_Iterator m_All();
  void m_AddLast(t_default_Actor* l_value);
  void m_AddFirst(t_default_Actor* l_value);
};

#endif
