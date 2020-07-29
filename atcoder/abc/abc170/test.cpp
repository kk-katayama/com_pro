#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
  ofstream ofs("test.dat");
  ofs << 1000 << " " << 1000 << " " << 1000000 << "\n";
  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
      ofs << ".";
    }
    ofs << "\n";
  }


  return 0;
}
