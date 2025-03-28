
#ifndef MX2_GRIDSHOOTER_STDLIB_COLLECTIONS_2MAP_H
#define MX2_GRIDSHOOTER_STDLIB_COLLECTIONS_2MAP_H

#include <bbmonkey.h>
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_collections_2map.h"

#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"

BB_CLASS(t_default_AnimationClip)

BB_ENUM(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node_Color)

BB_CLASS(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node)
BB_STRUCT(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator)
BB_STRUCT(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator)
BB_STRUCT(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys)
BB_STRUCT(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator)
BB_STRUCT(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues)
BB_CLASS(t_stdlib_collections_Map_1sTt_default_AnimationClip_2)

struct t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node : public bbObject{
  typedef t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node";}

  bbString m__0key{};
  bbGCVar<t_default_AnimationClip> m__0value{};
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node_Color m__0color{};
  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node> m__0left{};
  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node> m__0right{};
  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node> m__0parent{};

  void gcMark();

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node(bbString l_key,t_default_AnimationClip* l_value,t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node_Color l_color,t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_parent);
  ~t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node();

  void m_Value(t_default_AnimationClip* l_value);
  t_default_AnimationClip* m_Value();
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* m_PrevNode();
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* m_NextNode();

  bbString m_Key(){
    return this->m__0key;
  }
  bbInt m_Count(bbInt l_n);
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* m_Copy(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_parent);

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node(){
  }
};

struct t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator{
  typedef t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator";}

  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node> m__0node{};

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_node);
  ~t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator();

  bbBool m_Valid();
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* m_Current();
  void m_Bump();
  bbBool m_AtEnd();

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator(){
  }

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator&x,const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator&y);

void bbGCMark(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator&);

struct t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator{
  typedef t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator";}

  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node> m__0node{};

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_node);
  ~t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator();

  bbBool m_Valid();
  bbString m_Current();
  void m_Bump();
  bbBool m_AtEnd();

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator(){
  }

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator&x,const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator&y);

void bbGCMark(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator&);

struct t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys{
  typedef t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys";}

  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2> m__0map{};

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys(t_stdlib_collections_Map_1sTt_default_AnimationClip_2* l_map);
  ~t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys();

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_KeyIterator m_All();

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys(){
  }

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys&x,const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys&y);

void bbGCMark(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys&);

struct t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator{
  typedef t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator";}

  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node> m__0node{};

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_node);
  ~t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator();

  bbBool m_Valid();
  t_default_AnimationClip* m_Current();
  void m_Bump();
  bbBool m_AtEnd();

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator(){
  }

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator&x,const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator&y);

void bbGCMark(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator&);

struct t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues{
  typedef t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues";}

  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2> m__0map{};

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues(t_stdlib_collections_Map_1sTt_default_AnimationClip_2* l_map);
  ~t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues();

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_ValueIterator m_All();

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues(){
  }

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues&x,const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues&y);

void bbGCMark(const t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues&);

struct t_stdlib_collections_Map_1sTt_default_AnimationClip_2 : public bbObject{
  typedef t_stdlib_collections_Map_1sTt_default_AnimationClip_2 *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_stdlib_collections_Map_1sTt_default_AnimationClip_2";}

  bbGCVar<t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node> m__0root{};

  void gcMark();

  t_stdlib_collections_Map_1sTt_default_AnimationClip_2(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_root);
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2();
  ~t_stdlib_collections_Map_1sTt_default_AnimationClip_2();

  void m__idxeq(bbString l_key,t_default_AnimationClip* l_value);
  t_default_AnimationClip* m__idx(bbString l_key);
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapValues m_Values();
  bbBool m_Update(bbString l_key,t_default_AnimationClip* l_value);
  bbBool m_Set(bbString l_key,t_default_AnimationClip* l_value);
  void m_RotateRight(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_node);
  void m_RotateLeft(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_node);
  void m_RemoveNode(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_node);
  bbBool m_Remove(bbString l_key);
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* m_LastNode();
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_MapKeys m_Keys();
  void m_InsertFixup(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_node);
  t_default_AnimationClip* m_Get(bbString l_key);
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* m_FirstNode();
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* m_FindNode(bbString l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_node,t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Node* l_parent);
  bbInt m_Count();
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2* m_Copy();
  bbBool m_Contains(bbString l_key);
  void m_Clear();
  t_stdlib_collections_Map_1sTt_default_AnimationClip_2_Iterator m_All();
  bbBool m_Add(bbString l_key,t_default_AnimationClip* l_value);
};

#endif
