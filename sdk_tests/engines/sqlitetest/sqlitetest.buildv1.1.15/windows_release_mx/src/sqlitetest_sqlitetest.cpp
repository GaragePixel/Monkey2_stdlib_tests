
#include "sqlitetest.buildv1.1.15/windows_release_mx/include/sqlitetest_sqlitetest.h"

#include "monkey/monkey.buildv1.1.15/windows_release_mx/include/monkey_types.h"
#include "sdk/sdk.buildv1.1.15/windows_release_mx/include/sdk_engines_2databases_2sqlite_2sqlite_0extern.h"
#include "stdlib/stdlib.buildv1.1.15/windows_release_mx/include/stdlib_plugins_2libc_2libc.h"

extern bbInt g_sdk_engines_sqlite_SQLITE_0OK;
extern bbInt g_sdk_engines_sqlite_SQLITE_0ROW;

void bbMain(){
  static bool done;
  if(done) return;
  done=true;
  void mx2_monkey_main();mx2_monkey_main();
  void mx2_sdk_main();mx2_sdk_main();
  void mx2_sqlitetest_sqlitetest_init_f();mx2_sqlitetest_sqlitetest_init_f();
  bb_print(bbString(sqlite3_version));
  bb_print(bbString(sqlite3_libversion()));
  bbInt l_rc{};
  sqlite3* l_db{};
  sqlite3_stmt* l_res{};
  l_rc=sqlite3_open(bbCString(bbString(L":memory:",8)),(&l_db));
  if((l_rc!=g_sdk_engines_sqlite_SQLITE_0OK)){
    bb_print((bbString(L"Failed to open DB: ",19)+bbString(sqlite3_errmsg(l_db))));
    sqlite3_close(l_db);
    return;
  }
  l_rc=sqlite3_prepare_v2(l_db,bbCString(bbString(L"SELECT SQLITE_VERSION()",23)),-1,(&l_res),((const char**)0));
  if((l_rc!=g_sdk_engines_sqlite_SQLITE_0OK)){
    bb_print((bbString(L"Failed to fetch data: ",22)+bbString(sqlite3_errmsg(l_db))));
    sqlite3_close(l_db);
    return;
  }
  l_rc=sqlite3_step(l_res);
  if((l_rc==g_sdk_engines_sqlite_SQLITE_0ROW)){
    bb_print(bbString(sqlite3_column_text(l_res,bbInt(0))));
  }
  sqlite3_finalize(l_res);
  sqlite3_close(l_db);
}

void mx2_sqlitetest_sqlitetest_init_f(){
}
