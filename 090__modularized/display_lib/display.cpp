#include <display.h>

#include "engine.h"


Display::Display()
: en_(new Engine())
{
  std::cout << "Display!" << std::endl;
}

Display::~Display()
{
  std::cout << "Display::selfdestruction" << std::endl;
  delete en_;
}
