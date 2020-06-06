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
  int t;cin >> t;
  vector<ll> a(t), k(t);
  rep(i,t) cin >> a[i] >> k[i];

  rep(i,t) {
    rep(j,k[i]-1) {
      ll aa = a[i];
      ll maxi = 0, mini = 10;
      while(aa > 0) {
	ll x = aa % 10;
	chmax(maxi, x);
	chmin(mini, x);
	aa /= 10;
      }
      if(mini == 0) break;
      a[i] += maxi*mini;
    }
    cout << a[i] << "\n";
  }
  
  return 0;
}
