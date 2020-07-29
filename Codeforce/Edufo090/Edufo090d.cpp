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
  int t; cin >> t;
  while(t-- > 0) {
    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll res = 0;
    rep(i,n) if(i % 2 == 0) res += a[i];
    ll tmp = 0;
    ll sum = 0;
    ll mini = 0;
    rep(i,n) {
      if(i % 2 == 0) {
	sum -= a[i];
      }
      else {
	sum += a[i];
	chmin(mini, sum);
	chmax(tmp, sum - mini);
      }
    }
    ll tmp2 = 0;
    sum = 0;
    mini = 0;
    rep1(i,n-1) {
      if(i % 2 == 0) {
	sum -= a[i];
	chmin(mini, sum);
	chmax(tmp2, sum - mini);
      }
      else {
	sum += a[i];
      }      
    }
    cout << res + max(tmp, tmp2) << "\n";
  }
  return 0;
}
