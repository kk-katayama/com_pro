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
  vi h(n);
  rep(i,n) cin >> h[i];

  vector<pi> p(n);
  rep(i,n) p[i] = {h[i], i};
  sort(p.begin(), p.end(), [](pi a, pi b){
			     return a.first > b.first;
			   });

  vi res(n, 0);
  set<int> st;
  st.insert(-1);
  st.insert(n);  
  vi v;
  rep(i,n) {
    v.push_back(p[i].second);
    auto it = st.upper_bound(p[i].second);
    auto it2 = it;
    it2--;
    res[p[i].second] = *it - *it2 - 2;
    if(i+1 < n && p[i].first == p[i+1].first) {
      
    }
    else {
      for(auto val: v) {
	st.insert(val);
      }
      v.clear();
    }
  }
  
  for(auto val: res) cout << val << "\n";
  
  return 0;
}
