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
  int R,G,B; cin >> R >> G >> B;
  vector<ll> r(R), g(G), b(B);
  rep(i,R) cin >> r[i];
  rep(i,G) cin >> g[i];
  rep(i,B) cin >> b[i];
  sort(r.begin(), r.end());
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  using vl = vector<ll>;
  using vll = vector<vl>;
  using vlll = vector<vll>;
  vlll dp(R+1, vll(G+1, vl(B+1, 0)));
  ll res = 0;
  rep(i,R+1) {
    rep(j,G+1) {
      rep(k,B+1) {
	if(i < R && j < G) {
	  chmax(dp[i+1][j+1][k], dp[i][j][k] + r[i] * g[j]);
	}
	if(i < R && k < B) {
	  chmax(dp[i+1][j][k+1], dp[i][j][k] + r[i] * b[k]);
	}
	if(j < G && k < B) {
	  chmax(dp[i][j+1][k+1], dp[i][j][k] + g[j] * b[k]);
	}
	chmax(res, dp[i][j][k]);
      }
    }
  }
  cout << res << "\n";
  return 0;
}
