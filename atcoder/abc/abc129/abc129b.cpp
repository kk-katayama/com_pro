#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> sum(n+1);
  sum[0] = 0;
  int res = 1e+9;
  rep(i,n) sum[i+1] = sum[i]+a[i];
  rep1(i,n-1) res = min(res,abs(sum[n]-sum[i]-sum[i]));
  cout << res << "\n";
  return 0;
}
