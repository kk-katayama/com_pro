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
  int n; cin >> n;
  vi a(n),b(n);
  rep(i,n) {
    cin >> a[i] >> b[i];
  }

  int M = 1e+6;
  vi dp(M+1, 0);
  vector<vector<pi>> go(M+1), bac(M+1);
    rep(i,n) {
    go[a[i]].push_back({b[i], i});
    bac[b[i]].push_back({a[i], i});
  }
  rep(i,M+1) {
    if(i-1>=0) chmax(dp[i], dp[i-1]);
    for(auto tmp: go[i]) {
      auto [time, id] = tmp;
      chmax(dp[time], dp[i] + 1);
    }
  }
  int cnt = dp[M];
  vi mx(cnt+1, 0), mn(cnt+1, inf);
  mx[cnt] = M;
  for(int i = M; i >= 0; --i) {
    if(dp[i] == cnt) {
      if(sz(bac[i]) == 0) continue;
      for(auto tmp: bac[i]) {
        auto [time, id] = tmp;
        chmax(mx[cnt-1], time);
        chmin(mn[cnt-1], time);
      }
    }
    else {
      mn[cnt] = i+1;
      break;
    }
  }
  for(int i = cnt-1; i > 0; --i) {
    for(int j = mx[i]; j >= 0; --j) {
      if(dp[j] == i) {
        if(sz(bac[j]) == 0) continue;
        for(auto tmp: bac[j]) {
          auto [time, id] = tmp;
          chmax(mx[i-1], time);
        }
      }
      else {
        mn[i] = j+1;
        break;
      }
    }
  }
  // rep(i,cnt+1) {
  //   cout << mn[i] << " " << mx[i] << "\n";
  // }
  mn[0] = 0;
  cout << cnt << "\n";
  rep(i,cnt) {
    int idx = inf;
    int time;
    for(int j = mn[i]; j <= mx[i]; ++j) {
      if(sz(go[j]) == 0) continue;
      for(auto tmp: go[j]) {
        auto [t, id] = tmp;
        if(mn[i+1] <= t && t <= mx[i+1]) {
          if(chmin(idx, id)) time = t;
        }
      }
    }
    if(i+1<cnt) mn[i+1] = time;
    cout << idx+1;
    if(i==cnt-1) cout << "\n";
    else cout << " ";
  }
  
  return 0;
}
