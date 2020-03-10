#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;cin >> n >> k;
  int res = k;
  rep(i,n-1) res *= (k-1);
  cout << res << "\n";
  return 0;
}
