#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int p,r,q;
  cin >> p >> r >> q;
  cout << (int)min(p+r,min(r+q,q+p)) << "\n";
  return 0;
}
