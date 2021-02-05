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
  vi t(n);
  rep(i,n) cin >> t[i];
  vector<queue<int>> Q(n),R(n);
  vector<queue<pi>> Q2(n),R2(n);
  queue<int> q;
  rep(i,m) {
    int a,b,c; cin >> a >> b >> c;
    a--; b--; c--;
    if(t[a] == 1 && t[b] == 1) {
      q.push(c);
    }
    if(t[a] == 1 && t[b] == 3) {
      Q[b].push(c);
    }
    if(t[a] == 3 && t[b] == 1) {
      R[a].push(c);
    }
    if(t[a] == 3 && t[b] == 3) {
      R2[b].push({a, c});
      Q2[a].push({b, c});      
    }    
  }

  bool f = true;
  while(!q.empty()) {
    int buf = q.front(); q.pop();
    if(t[buf] == 2) f = false;
    if(t[buf] == 1) continue;
    t[buf] = 1;
    while(!Q[buf].empty()) {
      int tmp = Q[buf].front(); Q[buf].pop();
      q.push(tmp);
    }
    while(!R[buf].empty()) {
      int tmp = R[buf].front(); R[buf].pop();
      q.push(tmp);
    }
    while(!R2[buf].empty()) {
      pi tmp = R2[buf].front(); R2[buf].pop();
      R[tmp.first].push(tmp.second);
    }
    while(!Q2[buf].empty()) {
      pi tmp = Q2[buf].front(); Q2[buf].pop();
      Q[tmp.first].push(tmp.second);
    }    
  }

  if(f) {
    rep(i,n) {
      if(t[i] == 3) cout << 2 << "\n";
      else cout << t[i] << "\n";
    }
  }
  else cout << -1 << "\n";
  
  return 0;
}
