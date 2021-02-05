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
  int n,k; cin >> n >> k;
  vvi c(10);
  rep(i,n) {
    int x,y; cin >> x >> y;
    y--;
    c[y].push_back(x);
  }

  rep(i,10) {
    sort(c[i].begin(), c[i].end(), [](int a, int b){
      return a > b;
    });
  }

  int res = 0;
  vvi dp(k+1, vi(11, 0));
  rep(i,10) {
    rep(j,k) {
      int sum = 0;
      rep(l,sz(c[i])+1) {
	if(j + l <= k) {
	  chmax(dp[j+l][i+1], dp[j][i] + sum + l*(l-1));
	  chmax(res, dp[j+l][i+1]);
	}
	if(l < sz(c[i])) sum += c[i][l];
      }
    }
  }
  cout << res << "\n";

  return 0;
}
