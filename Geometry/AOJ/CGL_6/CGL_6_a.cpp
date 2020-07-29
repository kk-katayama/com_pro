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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using pii = pair<pi,pi>;
int main()
{
  int n; cin >> n;
  vector<pii> p;
  while(n-- > 0) {
    int a,b,c,d; cin >> a >> b >> c >> d;
    if(a == c) {
      if(b > d) swap(b, d);
      p.push_back({{a, 1}, {b, d}});
    }
    else {
      if(a > c) swap(a, c);
      p.push_back({{a, 0},{b, 0}});
      p.push_back({{c, 2},{b, 0}});      
    }
  }

  sort(p.begin(), p.end());
  multiset<int> st;
  int res = 0;
  rep(i,(int)p.size()) {
    pii q = p[i];
    if(q.F.S == 0) st.insert(q.S.F);
    else if(q.F.S == 1) {
      auto it = st.lower_bound(q.S.F);
      int cnt = 0;
      while(it != st.end() && *it <= q.S.S) {
	it++;
	cnt++;
      }
      res += cnt;
    }
    else if(q.F.S == 2) {
      auto it = st.find(q.S.F); 
      st.erase(it);
    }
  }
  cout << res << "\n";
  return 0;
}
