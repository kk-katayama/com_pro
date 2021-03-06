#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n,k;cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll sum = 0;
  ll res = 0;
  rep(i,k) sum += a[i];
  rep(i,n-k+1){
    res += sum;
    sum -= a[i];
    sum += a[k+i];
  }
  cout << res << "\n";
  return 0;
}
