#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n,k; cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> sum(n+1), psum(n+1);
  sum[0] = 0;
  psum[0] = 0;
  rep(i,n) {
    sum[i+1] = sum[i] + a[i];
    psum[i+1] = psum[i] + (a[i] > 0 ? a[i] : 0);
  }

  ll res = 0;
  rep(i,n-k+1) {
    ll tmp = psum[i] + psum[n] - psum[i+k];
    chmax(res, tmp);
    tmp += sum[i+k] - sum[i];
    chmax(res, tmp);    
  }
  cout << res << "\n";
  
  return 0;
}
