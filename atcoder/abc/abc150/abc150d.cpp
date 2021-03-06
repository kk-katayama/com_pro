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
// ユークリッドの互除法で最大公約数を求める
ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

int main()
{
  ll n,m; cin >> n >> m;
  vi a(n);
  rep(i,n) cin >> a[i];

  ll t = -1;
  rep(i,n) {
    ll buf = a[i];
    ll c = 0;
    while(buf % 2 == 0) {
      c++;
      buf /= 2;
    }
    if(t > 0 && t != c) {
      cout << 0 << "\n";
      return 0;
    }
    t = c;
  }

  ll g = 1;
  rep(i,n) {
    a[i] /= 2;
    g = lcm(g, a[i]);
  }

  if(g > m) cout << 0 << "\n";
  else {
    cout << (1 + m/g)/2 << "\n";
  }
  
  return 0;
}
