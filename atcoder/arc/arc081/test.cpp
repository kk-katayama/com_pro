#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
  ofstream ofs("test.dat");
  for (int i = 0; i < 100000; ++i) {
    int j = i % 26;
    char c = 'a' + j;
    ofs << c;
  }
  
  return 0;
}
