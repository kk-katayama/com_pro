#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int k,n;cin >> k >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int res = 1e+9;
  res = min(res , a[n-1] - a[0]);
  rep(i,n-1){
    res = min(res , k - a[i+1] + a[i] );
  }
  cout << res << "\n";
  return 0;
}
