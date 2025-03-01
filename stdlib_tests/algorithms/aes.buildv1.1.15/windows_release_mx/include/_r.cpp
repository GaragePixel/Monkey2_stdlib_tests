
#include <bbmonkey.h>
#include <bbtypeinfo_r.h>
#include <bbdeclinfo_r.h>

#include "_r.h"

extern void bbMain();
#if BB_R_default || BB_R_default__
static struct mx2_aes_aes_typeinfo : public bbClassDecls{
  mx2_aes_aes_typeinfo():bbClassDecls(bbClassTypeInfo::getNamespace("default")){
  }
  bbDeclInfo **initDecls(){
    return bbMembers(bbFunctionDecl<void>("Main",&bbMain));
  }
}_mx2_aes_aes_typeinfo;
#else
#endif