
#include "stdlib/_tests/algorithms/aes.buildv1.1.15/windows_release_mx/include/aes_aes.h"

extern bbString g_stdlib_crypto_aes_AESDecrypt(bbString l_input,bbString l_key);
extern bbString g_stdlib_crypto_aes_AESEncrypt(bbString l_input,bbString l_key);
void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_monkey_main();mx2_monkey_main();
  void mx2_stdlib_main();mx2_stdlib_main();
  void mx2_aes_aes_init_f();mx2_aes_aes_init_f();
  bbString l_value=bbString(L"Φello world",11);
  bbString l_key=bbString(L"cat",3);
  bbString l_encrypted=g_stdlib_crypto_aes_AESEncrypt(l_value,l_key);
  bbString l_decrypted=g_stdlib_crypto_aes_AESDecrypt(l_encrypted,l_key);
  bb_print(bbString(L"[results]",9));
  bb_print((bbString(L"value = ",8)+l_value));
  bb_print((bbString(L"key = ",6)+l_key));
  bb_print((bbString(L"encrypted = ",12)+l_encrypted));
  bb_print((bbString(L"decrypted = ",12)+l_decrypted));
}

void mx2_aes_aes_init_f(){
}
