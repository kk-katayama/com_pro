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
  vector<pair<ll,int>> p(n);
  rep(i,n) {
    ll tmp; cin >> tmp;
    p[i] = {tmp, i};
  }

  multiset<int> st;
  st.insert(-1);
  st.insert(-1);
  st.insert(n);
  st.insert(n);
  sort(p.begin(), p.end(), [](pair<ll, int> a, pair<ll, int> b) {
			     return a.first > b.first;
			   });

  ll res = 0;
  rep(i,n) {
    auto [val, id] = p[i];
    st.insert(id);
    auto it = st.find(id);
    it--;
    ll x2 = *it;
    it--;
    ll x1 = *it;
    it = st.find(id);
    it++;
    ll x3 = *it;
    it++;
    ll x4 = *it;
    res +=  val * ( (x2 - x1) * (x3 - id) + (x4 - x3) * (id - x2) );
  }

  cout << res << "\n";
  
  return 0;
}
