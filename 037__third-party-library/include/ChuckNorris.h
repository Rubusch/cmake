/*
  using extern library 'sqlite3'

  RESOURCE
  https://dmerej.info/blog/post/chuck-norris-part-1-cmake-ninja
  original example by Dimitri Merejkowsky
 */
#pragma once

#include <string>
#include <sqlite3.h>


class ChuckNorris
{
public:
  ChuckNorris();
  ChuckNorris(ChuckNorris const&) = delete;
  ChuckNorris(ChuckNorris &&) = delete;
  ChuckNorris& operator=(ChuckNorris const&) = delete;
  ChuckNorris& operator=(ChuckNorris &&) = delete;
  ~ChuckNorris();

  std::string getFact();

private:
  sqlite3* db_;
};
