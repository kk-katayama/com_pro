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
  vvi a(n, vi(k));
  rep(i,n) {
    rep(j,k) {
      cin >> a[i][j];
    }
  }

  vi f(1000000, 0);
  vvi res(n);
  int cnt = k;
  rep(c,n) {
    rep(j,k) {
      rep(i,c+1) {
	if(cnt > (n-1-c)*j && !f[a[i][j]]) {
	  cnt--;
	  res[c].push_back(a[i][j]);
	  f[a[i][j]] = 1;
	}
      }
    }
  }

  rep(i,n) sort(res[i].begin(), res[i].end());
  
  rep(i,n) {
    for(auto val:res[i]) cout << val << " ";
    cout << "\n";
  }
  
  return 0;
}
