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
  ll n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll cnt = 0;
  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i] + a[i];

  ll tmp = 0;
  rep1(i,n) {
    ll buf = sum[i] + cnt;
    if(i % 2 == 1) {
      if(buf <= 0) {
	cnt += -buf + 1;
	tmp += -buf + 1;
      }
    }
    else {
      if(buf >= 0) {
	cnt += -buf - 1;
	tmp += buf + 1;
      }      
    }
  }
  ll res = tmp;
  tmp = 0;
  cnt = 0;
  rep1(i,n) {
    ll buf = sum[i] + cnt;
    if(i % 2 == 0) {
      if(buf <= 0) {
	cnt += -buf + 1;
	tmp += -buf + 1;
      }
    }
    else {
      if(buf >= 0) {
	cnt += -buf - 1;
	tmp += buf + 1;
      }      
    }
  }

  cout << min(res, tmp) << "\n";
  
  return 0;
}
