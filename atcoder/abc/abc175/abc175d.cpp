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
int main()
{
  ll n,k; cin >> n >> k;
  vector<ll> p(n), c(n);
  rep(i,n) {
    cin >> p[i];
    p[i]--;
  }
  rep(i,n) cin >> c[i];

  ll res = -1e+15;
  rep(i,n) {
    vector<ll> dp(1, 0);
    ll maxi = -1e+15;
    ll tmp = 0, cnt = 0;
    int idx = i;
    while(cnt < k) {
      cnt++;
      idx = p[idx];
      tmp += c[idx];
      chmax(maxi, tmp);
      dp.push_back(maxi);
      if(i == idx) break;
    }
    if(cnt < k && tmp > 0) {
      ll m = k / cnt;
      chmax(res, m * tmp + dp[k - m * cnt]);
      m--;
      chmax(res, m * tmp + maxi);	
    }
    else {
      chmax(res, maxi);
    }
  }
  cout << res << "\n";
  
  return 0;
}
