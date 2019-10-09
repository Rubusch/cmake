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

#ifdef USE_MYLIB
  auto a = new A();
#endif

  cout << "Created a...?" << endl;

#ifdef USE_MYLIB
  delete a;
#endif

  return 0;
}
