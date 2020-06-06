#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
vector<int> compress(vector<ll> a) {
  int n = a.size();
  vector<ll> vals;
  rep(i,n) vals.push_back(a[i]);

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  vector<int> res;
  rep(i,n) {
    int id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin() + 1; // 1-indexed
    res.push_back(id);
  }

  return res;
}

ll dp[310][310][310];
int main()
{
  int n,k;cin >> n >> k;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];

  vector<int> comp = compress(h);
  vector<ll> mp(n+1);
  mp[0] = 0;
  rep(i,comp.size()) mp[comp[i]] = h[i];
  
  rep(i,n+1) rep(j,k+1) rep(l,n+1) dp[i][j][l] = 1e+15;
  dp[0][0][0] = 0;
  
  rep(i,n) {
    rep(j,k+1) {
      rep(l,n+1) {
	int nl = comp[i];
	// not change
	chmin(dp[i+1][j][nl], dp[i][j][l] + max(mp[nl] - mp[l], 0LL) );
	// change
	if(j + 1 <= k) chmin(dp[i+1][j+1][l], dp[i][j][l]);
      }
    }
  }
  
  ll res = 1e+15;
  rep(j,k+1) rep(l,n+1) {
    chmin(res, dp[n][j][l]);
  }
  cout << res << "\n";
  return 0;
}
