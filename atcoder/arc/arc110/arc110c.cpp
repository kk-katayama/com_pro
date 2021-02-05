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
  vi p(n+1);
  rep1(i,n) cin >> p[i];

  vi pos(n+1);
  rep1(i,n) pos[p[i]] = i;

  vi res;
  int id = 1;
  while(id < n) {
    int t = pos[id];
    //    cout << id << ":" << t << "\n";
    if(id == t) {
      cout << -1 << "\n";
      return 0;
    }
    int c = 1;
    for (int i = id; i <= t-2; ++i) {
      if(p[i] == id+c){
      }
      else {
	cout << -1 << "\n";
	return 0;	
      }
      c++;
    }
    for (int i = t-1; i >= id; --i) {
      res.push_back(i);
    }
    id = t;
    if(id == n) break;
    if(sz(res) >= n) break;
    p[id] = p[id-1];
  }
  if(sz(res) != n-1) cout << -1 << "\n";
  else {
    rep(i,n-1) cout << res[i] << "\n";
  }
  
  return 0;
}
