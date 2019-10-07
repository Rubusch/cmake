#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "config.h" /* generated, version number */

#include "a.h"


using namespace std;

int main()
{
  cout << "version number, major: " << Basic_VERSION_MAJOR << ", minor: " << Basic_VERSION_MINOR << endl;

  auto a = new A();

  cout << "a created..." << endl;

  delete a;

  return 0;
}
