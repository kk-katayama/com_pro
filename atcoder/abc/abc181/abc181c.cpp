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
  int n; cin >> n;
  vi x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];
  bool f = false;
  rep(i,n) {
    rep(j,n) {
      if(i >= j) continue;
      rep(k,n) {
	if(i >= k || j >= k) continue;
	vector<pi> tmp;
	tmp.push_back({x[i], y[i]});
	tmp.push_back({x[j], y[j]});
	tmp.push_back({x[k], y[k]});
	sort(tmp.begin(), tmp.end(), [](pi a, pi b) {
	  return a.first < b.first;
	});
	if(tmp[0].first == tmp[1].first && tmp[0].first == tmp[2].first) {
	  f = true;
	}
	else if(tmp[0].second == tmp[1].second && tmp[0].second == tmp[2].second) {
	  f = true;
	}	
	else {
	  int dx1 = tmp[1].first - tmp[0].first;
	  int dy1 = tmp[1].second - tmp[0].second;
	  int g1 = gcd(abs(dx1), abs(dy1));
	  int dx2 = tmp[2].first - tmp[0].first;
	  int dy2 = tmp[2].second - tmp[0].second;
	  int g2 = gcd(abs(dx2), abs(dy2));	  
	  if(dx1 / g1 == dx2 / g2 && dy1 / g1 == dy2 / g2) f = true;
	}
      }
    }
  }

  cout << (f ? "Yes" : "No") << "\n";

  
  return 0;
}
