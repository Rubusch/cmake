#include <iostream>

using namespace std;

int main()
{
#if defined (HAVE_LOG)
  cout << "log() is defined" << endl;
#else
  cout << "log() is not defined" << endl;
#endif

#if defined (HAVE_EXP)
  cout << "exp() is defined" << endl;
#else
  cout << "exp() is not defined" << endl;
#endif

  return 0;
}
