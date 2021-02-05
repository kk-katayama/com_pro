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
  vl a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  priority_queue<pl> q;
  rep(i,n) {
    if(a[i] != b[i]) q.push({b[i], i});
  }

  ll res = 0;
  while( !q.empty() ) {
    auto [val, id] = q.top(); q.pop();
    ll c = b[(id-1+n)%n] + b[(id+1)%n];
    if(val - c < a[id]) {
      cout << -1 << "\n";
      return 0;
    }
    ll cnt = (val - a[id]) / c;
    res += cnt;
    b[id] -= cnt * c;
    if(b[id] != a[id]) {
      q.push({b[id], id});
    }
  }

  cout << res << "\n";
  
  return 0;
}
