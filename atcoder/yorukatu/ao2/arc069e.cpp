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
  ll n; cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];

  vi flag(n, 0);
  ll mx = 0;
  rep(i,n) {
    if(chmax(mx, a[i])) {
      flag[i] = 1;
    }
  }

  vector<pl> p(n);
  rep(i,n) {
    p[i] = {a[i], i};
  }
  
  sort(p.begin(), p.end(), [](pl a, pl b) {
			     if(a.first == b.first) {
			       return a.second > b.second;
			     }
			     else return a.first > b.first;
			   });

  ll sum = 0, id = -1;
  vl res(n, 0);
  rep(i,n) {
    auto [val, idx] = p[i];
    if(flag[idx] && id != -1) {
      res[id] += sum - i * val;
      sum = i * val;
    }
    if(flag[idx]) id = idx;
    sum += val;
  }

  res[0] += sum;
  
  rep(i,n) cout << res[i] << "\n";
  
  return 0;
}
