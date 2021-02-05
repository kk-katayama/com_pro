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
  int n,m,a,b; cin >> n >> m >> a >> b;
  ll g,x,y,z; cin >> g >> x >> y >> z;
  vvl h(n, vl(m));
  rep(i,n) {
    rep(j,m) {
      h[i][j] = g;
      g = (g*x + y) % z;
    }
  }

  vvl nh(n, vl(m-b+1));
  rep(i,n) {
    deque<ll> deq;
    rep(j,b) {
      while( !deq.empty() && h[i][deq.back()] >= h[i][j]) {
	deq.pop_back();
      }
      deq.push_back(j);
    }
    for (int j = b; j < m; ++j) {
      int id = deq.front();
      nh[i][j-b] = h[i][id];
      if(id == j - b) deq.pop_front();
      while( !deq.empty() && h[i][deq.back()] >= h[i][j]) {
	deq.pop_back();
      }
      deq.push_back(j);      
    }
    int id = deq.front();
    nh[i][m-b] = h[i][id];    
  }

  ll res = 0;
  rep(j,m-b+1) {
    deque<ll> deq;
    rep(i,a) {
      while( !deq.empty() && nh[deq.back()][j] >= nh[i][j]) {
	deq.pop_back();
      }
      deq.push_back(i);
    }
    for (int i = a; i < n; ++i) {
      int id = deq.front();
      res += nh[id][j];
      if(id == i - a) deq.pop_front();
      while( !deq.empty() && nh[deq.back()][j] >= nh[i][j]) {
	deq.pop_back();
      }
      deq.push_back(i);
    }
    int id = deq.front();
    res += nh[id][j];
  }
  
  cout << res << "\n";
  
  return 0;
}
