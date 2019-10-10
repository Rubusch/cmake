#include <display.h>

#include "engine.h"


Display::Display()
: en_(new Engine())
{
  std::cout << "Build Display!" << std::endl;
}

Display::~Display()
{
  std::cout << "ALERT!!! Selfdestruction  ..,o0O@@#*'`  " << std::endl;
  delete en_;
}
