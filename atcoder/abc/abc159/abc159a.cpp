#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  int res = 0;
  if(n != 0) res += n * (n - 1) / 2;
  if(m != 0) res += m * (m - 1) / 2;
  cout << res << "\n";
  return 0;
}
