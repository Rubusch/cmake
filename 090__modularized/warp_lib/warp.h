#pragma once

#include <iostream>

#include "capacitor.h"

class Warp
{
public:
  Warp();
  ~Warp();

private:
  Capacitor *en_;
};
