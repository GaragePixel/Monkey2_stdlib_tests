
#ifndef MX2_HELLOCHIMPMUNK_STD_COLLECTIONS_2MAP_H
#define MX2_HELLOCHIMPMUNK_STD_COLLECTIONS_2MAP_H

#include <bbmonkey.h>
#include "std/std.buildv1.1.15/windows_release_mx/include/std_collections_2map.h"

#include "chipmunk/chipmunk.buildv1.1.15/windows_release_mx/include/chipmunk_shape.h"
#include "chipmunk/chipmunk.buildv1.1.15/windows_release_mx/include/chipmunk_space.h"
#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"

BB_ENUM(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node_Color)

BB_CLASS(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node)
BB_STRUCT(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator)
BB_STRUCT(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator)
BB_STRUCT(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys)
BB_STRUCT(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator)
BB_STRUCT(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues)
BB_CLASS(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2)

struct t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node : public bbObject{
  typedef t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node";}

  cpShape* m__0key{};
  cpSpaceDebugColor m__0value{};
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node_Color m__0color{};
  bbGCVar<t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node> m__0left{};
  bbGCVar<t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node> m__0right{};
  bbGCVar<t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node> m__0parent{};

  void gcMark();

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node(cpShape* l_key,cpSpaceDebugColor l_value,t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node_Color l_color,t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_parent);
  ~t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node();

  void m_Value(cpSpaceDebugColor l_value);
  cpSpaceDebugColor m_Value();
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* m_PrevNode();
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* m_NextNode();
  cpShape* m_Key();
  bbInt m_Count(bbInt l_n);
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* m_Copy(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_parent);

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node(){
  }
};

struct t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator{
  typedef t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator";}

  bbGCVar<t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node> m__0node{};

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_node);
  ~t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator();

  bbBool m_Valid();
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* m_Current();
  void m_Bump();
  bbBool m_AtEnd();

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator(){
  }

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator&x,const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator&y);

void bbGCMark(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator&);

struct t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator{
  typedef t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator";}

  bbGCVar<t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node> m__0node{};

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_node);
  ~t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator();

  bbBool m_Valid();
  cpShape* m_Current();
  void m_Bump();
  bbBool m_AtEnd();

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator(){
  }

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator&x,const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator&y);

void bbGCMark(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator&);

struct t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys{
  typedef t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys";}

  bbGCVar<t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2> m__0map{};

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2* l_map);
  ~t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys();

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_KeyIterator m_All();

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys(){
  }

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys&x,const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys&y);

void bbGCMark(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys&);

struct t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator{
  typedef t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator";}

  bbGCVar<t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node> m__0node{};

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_node);
  ~t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator();

  bbBool m_Valid();
  cpSpaceDebugColor m_Current();
  void m_Bump();
  bbBool m_AtEnd();

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator(){
  }

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator&x,const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator&y);

void bbGCMark(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator&);

struct t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues{
  typedef t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues bb_struct_type;
  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues";}

  bbGCVar<t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2> m__0map{};

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2* l_map);
  ~t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues();

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_ValueIterator m_All();

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues(){
  }

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues(bbNullCtor_t){
  }
};

int bbCompare(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues&x,const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues&y);

void bbGCMark(const t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues&);

struct t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2 : public bbObject{
  typedef t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2 *bb_object_type;

  bbTypeInfo *typeof()const;
  const char *typeName()const{return "t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2";}

  bbGCVar<t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node> m__0root{};

  void gcMark();

  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_root);
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2();
  ~t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2();

  void m__idxeq(cpShape* l_key,cpSpaceDebugColor l_value);
  cpSpaceDebugColor m__idx(cpShape* l_key);
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapValues m_Values();
  bbBool m_Update(cpShape* l_key,cpSpaceDebugColor l_value);
  bbBool m_Set(cpShape* l_key,cpSpaceDebugColor l_value);
  void m_RotateRight(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_node);
  void m_RotateLeft(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_node);
  void m_RemoveNode(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_node);
  bbBool m_Remove(cpShape* l_key);
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* m_LastNode();
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_MapKeys m_Keys();
  void m_InsertFixup(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_node);
  cpSpaceDebugColor m_Get(cpShape* l_key);
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* m_FirstNode();
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* m_FindNode(cpShape* l_key);
  bbBool m_Empty();
  void m_DeleteFixup(t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_node,t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Node* l_parent);
  bbInt m_Count();
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2* m_Copy();
  bbBool m_Contains(cpShape* l_key);
  void m_Clear();
  t_std_collections_Map_1TcpShape_2TcpSpaceDebugColor_2_Iterator m_All();
  bbBool m_Add(cpShape* l_key,cpSpaceDebugColor l_value);
};

#endif
