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
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll x = 0;
  for (int i = 2; i < n; ++i) {
    x ^= a[i];
  }

  ll s = a[0] + a[1];
  
  vl xx,ss,aa;
  while(x > 0) {
    xx.push_back(x % 2);
    x >>= 1;
  }
  while(s > 0) {
    ss.push_back(s % 2);
    s >>= 1;
  }
  ll a0 = a[0];
  while(a[0] > 0) {
    aa.push_back(a[0] % 2);
    a[0] >>= 1;
  }

  int m = max({sz(xx), sz(ss), sz(aa)});
  xx.resize(m, 0);
  ss.resize(m, 0);
  aa.resize(m, 0);  

  reverse(xx.begin(), xx.end());
  reverse(ss.begin(), ss.end());  
  reverse(aa.begin(), aa.end());
  
  vvl dp1(2, vl(2, -inf));
  dp1[0][0] = 0;
  rep(i,m) {
    vvl dp2(2, vl(2, -inf));
    rep(j,2) {
      rep(k,2) {
	rep(val,(j ? 2 : aa[i] + 1)) {
	  int nk = ss[i] + 2*k - val - (val ^ xx[i]);
	  if(nk == 0 || nk == 1) {
	    chmax(dp2[j | (aa[i] > val)][nk], dp1[j][k]*2 + val);
	  }
	}
      }
    }
    swap(dp1, dp2);
  }

  ll res = max(dp1[0][0], dp1[1][0]);
  cout << (res <= 0 ? -1 : a0 - res) << "\n";
  
  return 0;
}
