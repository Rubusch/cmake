/*
 */

#include "engine.h"
#include "display.h"
#include "navigation.h"

#include <iostream>

using namespace std;


int main()
{
  auto engine = new Engine();
  auto screen = new Display();
  auto radar = new Navigation();

  delete engine screen radar;
  cout << "READY." << endl;
  return 0;
}
