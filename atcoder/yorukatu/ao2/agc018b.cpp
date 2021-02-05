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
  int n,m; cin >> n >> m;
  vvi a(n, vi(m));
  rep(i,n) {
    rep(j,m) {
      cin >> a[i][j];
    }
  }

  vi id(n, 0);
  int res = inf;
  set<int> st;


  rep(j,m) {
    vi cnt(m+1, 0);
    int mx = 0;
    int idx;  
    rep(i,n) {
      while(st.find(a[i][id[i]]) != st.end() ) {
	id[i]++;
      }
      cnt[a[i][id[i]]]++;
      if(chmax(mx, cnt[a[i][id[i]]])) {
	idx = a[i][id[i]];
      }
    }
    chmin(res, mx);
    st.insert(idx);
  }  
  cout << res << "\n";
  return 0;
}
