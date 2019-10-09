/*
  RESOURCE
  https://dmerej.info/blog/post/chuck-norris-part-1-cmake-ninja
  original example by Dimitri Merejkowsky

  author: Lothar Rubusch
 */
#include <ChuckNorris.h>
#include <iostream>

using namespace std;

int main()
{
  ChuckNorris chuckNorris;

  string fact = chuckNorris.getFact();

  cout << fact << endl;

  return 0;
}
