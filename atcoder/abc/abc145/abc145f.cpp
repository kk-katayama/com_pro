#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vl = vector<ll>;
vector<ll> compress(vector<ll> a) {
  ll n = a.size();
  vector<ll> vals;
  rep(i,n) vals.push_back(a[i]);

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  vector<ll> res;
  rep(i,n) {
    ll id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    res.push_back(id);
  }

  return res;
}

int main()
{
  ll n,k; cin >> n >> k;
  vector<ll> h(n+1);
  h[0] = 0;
  rep1(i,n) cin >> h[i];

  vector<ll> com = compress(h);
  map<ll,ll> mp, mp2;
  ll lmax = 0;
  rep(i,n+1) {
    mp[com[i]] = h[i];
    chmax(lmax, com[i]);
  }
  
  using vll = vector<vl>;
  using vlll = vector<vll>;
  ll inf = 1e+15;
  vlll dp(n+2, vll(k+1, vl(lmax+1, inf)));
  dp[0][0][0] = 0;
  rep(i,n+1) {
    rep(j,k+1) {
      rep(l,lmax+1) {
	if(j != k) chmin(dp[i+1][j+1][l], dp[i][j][l]);
	chmin(dp[i+1][j][com[i]], dp[i][j][l] + max((ll)0, h[i] - mp[l]));
      }
    }
  }
  
  ll res = inf;
  rep(j,k+1) {
    rep(l,lmax+1) {
      chmin(res, dp[n+1][j][l]);
    }
  }
  cout << res << "\n";
  
  return 0;
}
