/*
 */

#include "capacitor.h"
#include "display.h"
#include "navigation.h"

#include <iostream>

using namespace std;


int main()
{
  auto capacitor = new Capacitor();
  auto screen = new Display();
  auto radar = new Navigation();

  delete capacitor;
  delete screen;
  delete radar;
  cout << "READY." << endl;
  return 0;
}
