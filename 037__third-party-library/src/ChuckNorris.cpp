/*
  implementation uses a third party library 'sqlite3'

  RESOURCE
  https://dmerej.info/blog/post/chuck-norris-part-1-cmake-ninja
  original example by Dimitri Merejkowsky
 */


#include "ChuckNorris.h"

#include <sqlite3.h>


ChuckNorris::ChuckNorris()
{
  sqlite3_open(":memory:", &db_);

  auto const sql = R"(
CREATE TABLE chucknorris(id PRIMARY_KEY, fact VARCHAR(500));
INSERT INTO chucknorris (fact) VALUES
  ("Chuck Norris can slam a revolving door.");
INSERT INTO chucknorris (fact) VALUES
  ("Chuck Norris can kill two stones with one bird.");
  ...
  )";

  auto res = sqlite3_exec(db_, sql, 0, 0, nullptr);
}

ChuckNorris::~ChuckNorris()
{
  sqlite3_close(db_);
}

std::string ChuckNorris::getFact()
{
  // Note: error handling omitted for brevity

  sqlite3_stmt* statement;
  int rc;
  rc = sqlite3_prepare_v2(db_,
                          R"(SELECT fact FROM chucknorris ORDER BY RANDOM() LIMIT 1;)",
                          -1, &statement, 0);
/*
  if (rc != SQLITE_OK) {
    // ...
  }
// */
  rc = sqlite3_step(statement);
/*
  if (rc != SQLITE_ROW) {
    // ...
  }
// */
  auto sqlite_row = sqlite3_column_text(statement, 0);
  auto row = reinterpret_cast<const char*>(sqlite_row);
  auto res = std::string(row);
  sqlite3_finalize(statement);
  return res;
}
