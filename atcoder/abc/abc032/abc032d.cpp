#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n,W; cin >> n >> W;
  vector<ll> v(n),w(n);
  rep(i,n) cin >> v[i] >> w[i];

  using pi = pair<ll,ll>;
  if(n <= 30) {
    vector<pi> a,b;
    ll an = n/2, bn = n - n/2;
    // a
    rep(mask, (1 << an)) {
      ll vsum = 0, wsum = 0;
      rep(i,an) {
	if((mask >> i) & 1) {
	  vsum += v[i];
	  wsum += w[i];
	}
      }
      a.push_back({wsum, vsum});
    }
    sort(a.begin(), a.end());
    rep(i,a.size()-1) {
      if(a[i].second >= a[i+1].second) {
	a.erase(a.begin() + (i+1));
	i--;
      }
    }
    // b
    rep(mask, (1 << bn)) {
      ll vsum = 0, wsum = 0;
      rep(i,bn) {
	if((mask >> i) & 1) {
	  vsum += v[i + an];
	  wsum += w[i + an];
	}
      }
      b.push_back({wsum, vsum});
    }
    sort(b.begin(), b.end());
    rep(i,b.size()-1) {
      if(b[i].second >= b[i+1].second) {
	b.erase(b.begin() + (i+1));
	i--;
      }
    }
    //
    int right = b.size() - 1;
    ll res = 0;
    rep(left,a.size()) {
      while(W < a[left].first + b[right].first) {
	right--;
	if(right < 0) break;
      }
      if(right < 0) break;
      chmax(res, a[left].second + b[right].second);
    }
    cout << res << "\n";
  }
  else {
    ll wmax = 0;
    rep(i,n) chmax(wmax, w[i]);
    if(wmax <= 1000) {
      vector<vector<ll>> dp(n+1, vector<ll>(wmax*n+1, 0));
      rep(i,n) {
	rep(j,wmax*n+1) {
	  if(j - w[i] >= 0) dp[i+1][j] = max(dp[i][j], dp[i+1][j - w[i]] + v[i]);
	  else dp[i+1][j] = dp[i][j];
	}
      }
      cout << dp[n][min(W, wmax*n)] << "\n";
    }
    else {
      ll vmax = 0;
      rep(i,n) chmax(vmax, v[i]);
      vector<vector<ll>> dp(n+1, vector<ll>(vmax*n + 1, 1e+9));
      dp[0][0] = 0;
      rep(i,n) {
	rep(j,vmax*n + 1) {
	  if(j - v[i] >= 0) dp[i+1][j] = min(dp[i][j], dp[i+1][j - v[i]] + w[i]);
	  else dp[i+1][j] = dp[i][j];
	}
      }
      ll res = 0;
      rep(i,vmax*n + 1) {
	if(dp[n][i] <= W) chmax(res, (ll)i);
      }
      cout << res << "\n";
    }
  }
  return 0;
}
