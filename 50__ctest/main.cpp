#include <iostream>
#include <cstdlib>

#include "a.h"

using namespace std;

int main(int argc, char* argv[])
{
  auto a = new A(atoi(argv[0]));

  delete a;

  return 0;
}
