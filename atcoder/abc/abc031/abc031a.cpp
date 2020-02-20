#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b;
  cin >> a >> b;
  cout << (int)max((a+1)*b,a*(b+1)) << "\n";
  return 0;
}
