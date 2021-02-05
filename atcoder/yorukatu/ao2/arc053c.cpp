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

  vector<pi> minus;
  vector<pi> zero;
  vector<pi> plus;

  rep(i,n) {
    if(a[i] - b[i] < 0) {
      minus.push_back({a[i], b[i]});
    }
    if(a[i] - b[i] == 0) {
      zero.push_back({a[i], b[i]});      
    }
    if(a[i] - b[i] > 0) {
      plus.push_back({a[i], b[i]});      
    }
  }

  sort(minus.begin(), minus.end());
  sort(plus.begin(), plus.end(), [](pi a, pi b) {
				   if(a.second == b.second) return a.first > b.first;
				   else return a.second > b.second;
				 });
  
  ll res = 0;
  ll tmp = 0;
  for(auto val: minus) {
    auto [aa, bb] = val;
    chmax(res, tmp + aa);
    tmp += aa - bb;
  }
  for(auto val: zero) {
    auto [aa, bb] = val;
    chmax(res, tmp + aa);
    tmp += aa - bb;
  }
  for(auto val: plus) {
    auto [aa, bb] = val;
    chmax(res, tmp + aa);
    tmp += aa - bb;
  }  
  cout << res << "\n";
  return 0;
}
