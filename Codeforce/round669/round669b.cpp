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
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// ユークリッドの互除法で最大公約数を求める
int gcd(int a,int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
int lcm(int a,int b){
  return a*b/gcd(a,b);
}

int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    int n; cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];

    vector<bool> f(n, false);
    vi res;
    int id;
    int mx = 0;
    rep(i,n) {
      if(chmax(mx, a[i])) id = i;
    }
    res.push_back(a[id]);
    f[id] = true;
    int g = a[id];
    rep(i,n-1) {
      mx = 0;      
      rep(j,n) {
	if(f[j]) continue;
	if(chmax(mx, gcd(g, a[j]))) {
	  id = j;
	}
      }
      if(mx == 1) {
	rep(j,n) {
	  if(f[j]) continue;
	  res.push_back(a[j]);
	}
	break;
      }
      f[id] = true;
      g = mx;
      res.push_back(a[id]);
    }
    for(auto val: res) cout << val << " ";
    cout << "\n";
  }
  return 0;
}
