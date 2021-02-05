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
  vl a(n),b(n);
  rep(i,n) cin >> a[i] >> b[i];
  
  int res = 0;
  while(1) {
    int m = sz(a);
    vi c(m);
    rep(i,m) {
      ll mn = infll;
      rep(j,m) {
	if(i == j) continue;
	ll d = (a[i] - a[j])*(a[i] - a[j]) + (b[i] - b[j])*(b[i] - b[j]);
	if(chmin(mn, d) ) {
	  c[i] = j;
	}
      }
    }

    vl x,y;
    x.push_back(a[0]);
    y.push_back(b[0]);    
    rep1(i,m-1) {
      if(c[i] == 0) res++;
      else if(i == c[c[i]]) {
	continue;
      }
      else {
	x.push_back(a[i]);
	y.push_back(b[i]);
      }
    }
    if(sz(x) == 1) break;
    a = x;
    b = y;
  }

  cout << res << "\n";
  
  return 0;
}
