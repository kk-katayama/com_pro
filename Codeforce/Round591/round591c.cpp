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
  return a*b/gcd(a,b);
}

int main()
{
  int q; cin >> q;
  while(q-- > 0) {
    int n; cin >> n;
    vl p(n);
    rep(i,n) {
      cin >> p[i];
      p[i] /= 100;
    }
    ll x,a; cin >> x >> a;
    ll y,b; cin >> y >> b;
    if(x < y) {
      swap(x,y); swap(a,b);
    }
    ll k; cin >> k;
    ll c = lcm(a, b);
    sort(p.begin(), p.end(), [](ll a, ll b){
      return a > b;
    });
    int lb = 0, ub = n+1;
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      ll sum = 0;
      for (int i = 0; i < mid/c; ++i) {
	sum += p[i] * (x + y);
      }
      for (int i = mid/c; i < mid/c + mid/a - mid/c; ++i) {
	sum += p[i] * x;
      }
      for (int i = mid/a; i < mid/a + mid/b - mid/c; ++i) {
	sum += p[i] * y;
      }
      (sum >= k ? ub : lb) = mid;
    }
    cout << (ub == n+1 ? -1 : ub) << "\n";
  }
  return 0;
}
