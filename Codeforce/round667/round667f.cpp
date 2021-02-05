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
#define sz(v) (int)v.size()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  int n,k; cin >> n >> k;
  string s; cin >> s;
  string t; cin >> t;
  if(t[0] == t[1]) {
    int cnt = 0;
    rep(i,n) {
      if(s[i] == t[0]) cnt++;
    }
    cnt = min(cnt+k, n);
    cout << cnt*(cnt-1)/2 << "\n";
  }
  else {
    vvi dp1(n+1, vi(k+1, -1));
    dp1[0][0] = 0;
    rep(i,n) {
    vvi dp2(n+1, vi(k+1, -1));      
      rep(j,n+1) {
	rep(l,k+1) {
	  if(dp1[j][l] < 0) continue;
	  if(s[i] == t[0]) {
	    if(j+1 <= n) chmax(dp2[j+1][l], dp1[j][l]);
	    if(l+1 <= k) chmax(dp2[j][l+1], dp1[j][l] + j);
	  }
	  else if(s[i] == t[1]) {
	    chmax(dp2[j][l], dp1[j][l] + j);
	    if(j+1 <= n && l+1 <= k) chmax(dp2[j+1][l+1], dp1[j][l]);
	  }
	  else {
	    chmax(dp2[j][l], dp1[j][l]);
	    if(j+1 <= n && l+1 <= k) chmax(dp2[j+1][l+1], dp1[j][l]);
	    if(l+1 <= k) chmax(dp2[j][l+1], dp1[j][l] + j);	    
	  }
	}
      }
      swap(dp1, dp2);
    }

    int res = 0;
    rep(j,n+1) {
      rep(l,k+1) {
	chmax(res, dp1[j][l]);
      }
    }
    cout << res << "\n";
  }
  
  return 0;
}
