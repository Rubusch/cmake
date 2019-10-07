#include <iostream>

#include "a.h"

using namespace std;

int main()
{
  auto a = new A();

  cout << "do ut des!" << endl;

  delete a;

  return 0;
}
