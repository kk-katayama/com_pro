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
  ll r,c,k; cin >> r >> c >> k;
  ll n; cin >> n;
  vl a(n),b(n);
  vl tate(c, 0), yoko(r, 0);
  rep(i,n) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
    yoko[a[i]]++;    
    tate[b[i]]++;
  }

  vl x(max(k+1, c+1), 0), y(max(k+1, r+1), 0);
  rep(i,r) {
    x[yoko[i]]++;
  }
  rep(i,c) {
    y[tate[i]]++;
  }
  
  ll res = 0;
  rep(i,k+1) {
    res += x[i] * y[k - i];
  }
  
  rep(i,n) {
    if(yoko[a[i]] + tate[b[i]] == k+1) res++;
    if(yoko[a[i]] + tate[b[i]] == k) res--;
  }
  cout << res << "\n";
  return 0;
}
