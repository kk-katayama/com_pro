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
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  ll n; cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];

  vector<pl> p(n);
  rep(i,n) {
    p[i] = {a[i], i+1};
  }

  sort(p.begin(), p.end(), [](pl a, pl b){
    return a.first > b.first;
  });

  vvl dp(n+1, vl(n+1, 0));
  rep(i,n+1) {
    rep(j,n+1) {
      int k = i+j;
      if(k >= n) continue;
      if(i+1 <= n) {
	chmax(dp[i+1][j], dp[i][j] + p[k].first*abs(p[k].second - (i+1)));
      }
      if(j+1 <= n) {
	chmax(dp[i][j+1], dp[i][j] + p[k].first*abs(p[k].second - (n-j)));
      }      
    }
  }

  ll res = 0;
  rep(i,n+1) chmax(res, dp[i][n-i]);
  cout << res << "\n";
  
  return 0;
}
