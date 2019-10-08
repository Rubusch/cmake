#include <iostream>

#include "config.h"

using namespace std;

int main()
{
#ifdef HAVE_RAND
  cout << "rand() is defined" << endl;
#else
  cout << "rand() is not defined" << endl;
#endif

#ifdef HAVE_EXP
  cout << "exp() is defined" << endl;
#else
  cout << "exp() is not defined" << endl;
#endif
  cout << "READY." << endl;

  return 0;
}
