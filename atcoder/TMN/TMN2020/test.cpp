#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main(int argc, char *argv[])
{
  ofstream ofs("test.dat");
  ofs << pow(2,18) - 1 << "\n";
  for (int i = 0; i < pow(2,18); ++i) {
    ofs << 100 << " " << 100 << "\n";
  }
  ofs << 100000 << "\n";
  for (int i = pow(2,17); i <= pow(2,17)+100000; i++) {
    ofs << i << " " << 100000 << "\n";
  }

  return 0;
}
