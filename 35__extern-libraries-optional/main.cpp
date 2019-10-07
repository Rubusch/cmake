#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "config.h" /* generated, version number */

#ifdef USE_MYLIB
#include "a.h"
#endif



using namespace std;

int main()
{
  cout << "version number, major: " << Basic_VERSION_MAJOR << ", minor: " << Basic_VERSION_MINOR << endl;

#ifdef USE_MYMATH
  auto a = new A();
#endif

  cout << "a created..." << endl;

#include "MathFunctions.h"
  delete a;
#endif

  return 0;
}
