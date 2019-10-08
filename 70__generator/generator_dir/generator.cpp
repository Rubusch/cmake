// generator

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
  ofstream generated_file;
  generated_file.open(argv[1]);
  generated_file << "#include <iostream>\nstruct A\n{\nA()\n{\n std::cout << \"a generated world!\" << std::endl;\n}\n};";
  generated_file.close();
  return 0;
}
