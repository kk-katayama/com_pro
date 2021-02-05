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
  int n,k,q; cin >> n >> k >> q;
  vi a(n);
  rep(i,n) cin >> a[i];

  vector<pi> p(n);
  rep(i,n) p[i] = {a[i], i};
  sort(p.begin(), p.end());
  
  set<int> st;
  st.insert(-1);
  st.insert(n);

  int res = inf;
  rep(i,n) {
    vi c;
    for(auto it = st.begin(); it != st.end(); ++it) {
      auto it2 = it;
      ++it2;
      if(it2 == st.end()) break;
      vi b;
      for(int i = *it + 1; i < *it2; ++i) {
	b.push_back(a[i]);
      }
      sort(b.begin(), b.end());
      int m = *it2 - *it - 1;
      rep(i,m-k+1) {
	c.push_back(b[i]);
      }
    }
    if(sz(c) < q) continue;
    sort(c.begin(), c.end());
    chmin(res, c[q-1] - c[0]);
    st.insert(p[i].second);
  }
  cout << res << "\n";
  
  return 0;
}
