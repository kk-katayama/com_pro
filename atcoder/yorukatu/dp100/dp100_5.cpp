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
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<ll>;
using vii = vector<vi>;
int main()
{
  int n; cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];

  vii dp1(n+1, vi(200, 0));
  vi dp2(n+1, 0);
  dp2[0] = 1000;
  rep(i,n) {
    rep(j,200) {
      chmax(dp1[i+1][j], dp1[i][j]);
      chmax(dp2[i+1], j + dp1[i][j] * a[i]);
    }
    chmax(dp1[i+1][dp2[i]%a[i]], dp2[i]/a[i]);
    chmax(dp2[i+1], dp2[i]);
  }
  cout << dp2[n] << "\n";
  return 0;
}
