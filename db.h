/*
 * db.h
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 */

#ifndef __DB_H__
#define __DB_H__
#include <sqlite3.h>

#define SCHEMA_VERSION 1

typedef int (*db_iter_func_t)(const char *col_name, const char *thing);

int add_repo_to_db(sqlite3 *dbh, const char *alias, const char *path);
void close_db_handle(sqlite3 *dbh);
sqlite3 *get_db_handle(void);
int get_schema_version(sqlite3 *dbh);
int remove_repo_from_db(sqlite3 *dbh, const char *alias);

int foreach_repo(sqlite3 *dbh, db_iter_func_t function);
int forsome_repos(sqlite3 *dbh, db_iter_func_t function,
  const char *alias);

#endif

