#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int x,y,z;
  cin >> x >> y >> z;
  cout << (x-z)/(y+z) << "\n";
  
  return 0;
}
