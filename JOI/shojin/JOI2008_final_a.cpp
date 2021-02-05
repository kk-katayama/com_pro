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
  vi a(n);
  rep(i,n) cin >> a[i];

  vector<pi> p;
  if(a[0] == 0) {
    p.push_back({1, 0});
    p.push_back({1, 0});
  }
  else {
    p.push_back({0, 0});
    p.push_back({0, 0});
  }

  rep(i,n) {
    if(i % 2 == 0) {
      pi &x = p.back();
      if(x.first == a[i]) x.second++;
      else p.push_back({a[i], 1});
    }
    else {
      pi &x = p.back();
      if(x.first == a[i]) x.second++;
      else {
	int z = x.second + 1;
	p.pop_back();
	pi &y = p.back();
	if(y.first == a[i]) y.second += z;
	else p.push_back({a[i], z});
      }
    }
  }

  int res = 0;
  for(auto val: p) {
    auto [num, cnt] = val;
    if(num == 0) res += cnt;
  }
  cout << res << "\n";
  return 0;
}
