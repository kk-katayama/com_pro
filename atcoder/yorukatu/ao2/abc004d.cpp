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
  ll r,g,b; cin >> r >> g >> b;
  ll res = infll;
  for(ll rl = -800; rl <= -100; ++rl) {
    ll rr = r + rl - 1;
    for(ll gl = -500; gl <= 200; ++gl) {
      if(rr >= gl) continue;
      ll gr = g + gl - 1;
      for(ll bl = -200; bl <= 500; ++bl) {
	if(gr >= bl || rr >= bl) continue;
	ll br = b + bl - 1;
	ll tmp = 0;
	if(rr < -100) tmp += (rr - rl)*(rr - rl + 1)/2 + (-100 - rr) * r;
	else tmp += (-100 - rl)*(-100 - rl + 1)/2 + (rr + 100)*(rr + 101)/2;
	if(gr < 0) tmp += (gr - gl)*(gr - gl + 1)/2 + (0 - gr) * g;
	else if(0 < gl) tmp += (gr - gl)*(gr - gl + 1)/2 + (gl - 0) * g;
	else tmp += (0 - gl)*(0 - gl + 1)/2 + (gr + 0)*(gr + 1)/2;
	if(100 < bl) tmp += (br - bl)*(br - bl + 1)/2 + (bl - 100) * b;
	else tmp += (100 - bl)*(100 - bl + 1)/2 + (br - 100)*(br - 100 + 1)/2;
	chmin(res, tmp);
      }
    }
  }
  cout << res << "\n";
  return 0;
}
