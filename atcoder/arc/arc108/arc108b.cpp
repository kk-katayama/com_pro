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
  string s; cin >> s;

  vi ne(n), ba(n);
  rep(i,n) {
    ne[i] = i+1;
  }
  ne[n-1] = -1;
  rep(i,n) {
    ba[i] = i-1;
  }

  int res = 0;
  int id = 0;
  while(1) {
    if(id == -1 || ne[id] == -1 || ne[ne[id]] == -1) break;
    if(s[id] == 'f' && s[ne[id]] == 'o' && s[ne[ne[id]]] == 'x') {
      res++;
      if(ne[ne[ne[id]]] != -1) ba[ne[ne[ne[id]]]] = ba[id];
      if(ba[id] != -1) {
	ne[ba[id]] = ne[ne[ne[id]]];
	if(ba[ba[id]] != -1) {
	  id = ba[ba[id]];
	}
	else id = ba[id];
      }
      else {
	id = ne[ne[id]];
      }
    }
    else id = ne[id];
  }

  cout << n - res*3 << "\n";
  
  return 0;
}
