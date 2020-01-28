#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,a;
  cin >> h >> a;
  cout << (h+a-1)/a << "\n";
  return 0;
}
