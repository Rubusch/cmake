/*
  RESOURCE
  https://dmerej.info/blog/post/chuck-norris-part-1-cmake-ninja
  original example by Dimitri Merejkowsky

  author: Lothar Rubusch
 */
#pragma once

#include <string>

class ChuckNorris
{
public:
  ChuckNorris() = default;
  std::string getFact();
};
