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
  vvl d(10, vl(10, 0));
  rep1(i,n) {
    int x = i;
    int b = x % 10;
    int a;
    while(x > 0) {
      if(x/10 == 0) {
	a = x;
      }
      x /= 10;
    }
    d[a][b]++;
  }

  ll res = 0;
  rep1(i,9) {
    rep1(j,9) {
      res += d[i][j]*d[j][i];
    }
  }
  cout << res << "\n";
  
  return 0;
}
