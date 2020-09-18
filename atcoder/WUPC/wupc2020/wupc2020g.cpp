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
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  ll n,k,t; scanf("%lld %lld %lld", &n, &k, &t);
  vector<ll> a(n), b(n);
  rep(i,n) {
    scanf("%lld %lld", &a[i], &b[i]);	
  }

  vl dp(t+1, 0);
  rep(i,n) {
    vl ndp(t+1, 0);
    rep(j,t+1) {
      if(j - a[i] >= 0) chmax(ndp[j], max(dp[j], dp[j - a[i]] + b[i]));
      else chmax(ndp[j], dp[j]);
    }
    dp = ndp;
  }

  vl dp2(t+k+1, 0);
  rep(i,t+1) {
    rep(j,t+k+1) {
      if(j - (i + k) >= 0) chmax(dp2[j], dp2[j - (i+k)] + dp[i]);
    }
  }
  cout << dp2[t+k] << "\n";
  
  return 0;
}
