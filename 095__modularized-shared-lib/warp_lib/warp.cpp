#include <warp.h>

#include "capacitor.h"


Warp::Warp()
: en_(new Capacitor())
{
  std::cout << "Build Warp!" << std::endl;
}

Warp::~Warp()
{
  std::cout << "ALERT!!! Selfdestruction  ..,o0O@@#*'`  " << std::endl;
  delete en_;
}
