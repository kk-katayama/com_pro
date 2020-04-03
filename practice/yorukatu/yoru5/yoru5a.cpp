#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k,m;cin >> n >> k >> m;
  vector<int> a(n-1);
  rep(i,n-1) cin >> a[i];
  int sum = 0;
  rep(i,n-1) sum += a[i];
  if( n*m - sum <= k) {
    cout << max(0, n*m - sum) << "\n";
  }
  else cout << -1 << "\n";
  return 0;
}
