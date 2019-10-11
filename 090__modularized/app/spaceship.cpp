/*
 */

#include "capacitor.h"
#include "warp.h"
#include "navigation.h"

#include <iostream>

using namespace std;


int main()
{
  auto capacitor = new Capacitor();
  auto screen = new Warp();
  auto radar = new Navigation();

  delete capacitor;
  delete screen;
  delete radar;
  cout << "READY." << endl;
  return 0;
}
