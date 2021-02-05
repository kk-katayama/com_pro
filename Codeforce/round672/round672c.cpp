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
  int q; cin >> q;
  while(q-- > 0) {
    int n,t; cin >> n >> t;
    vl a(n+2);
    rep1(i,n) scanf("%lld", &a[i]);
    a[0] = 0; a[n+1] = 0;
    bool f = true;
    ll res = 0;
    rep1(i,n) {
      if(f && (a[i-1] < a[i] && a[i] > a[i+1]) ) {
	res += a[i];
	f = false;
      }
      else if( (!f) && (a[i-1] > a[i] && a[i] < a[i+1]) ) {
	res -= a[i];
	f = true;
      }
    }
    cout << res << "\n";
    while(t-- > 0) {
      int x,y; scanf("%d%d", &x, &y);
      set<int> st;
      for (int i = -1; i <= 1; ++i) {
	st.insert(x + i);
	st.insert(y + i);	
      }

      for(auto id: st) {
	if(0 <= id-1 && id+1 <= n+1) {
	  if(a[id-1] < a[id] && a[id] > a[id+1]) res -= a[id];
	  if(a[id-1] > a[id] && a[id] < a[id+1]) res += a[id];	  	  
	}
      }
      swap(a[x], a[y]);
      for(auto id: st) {
	if(0 <= id-1 && id+1 <= n+1) {
	  if(a[id-1] < a[id] && a[id] > a[id+1]) res += a[id];
	  if(a[id-1] > a[id] && a[id] < a[id+1]) res -= a[id];	  	  
	}
      }      
      // x
      // if(a[x-1] < a[x] && a[x] > a[x+1]) res -= a[x];
      // if(0 <= x-2 && a[x-2] < a[x-1] && a[x-1] > a[x]) res -= a[x-1];
      // if(x+2 <= n+1 && a[x] < a[x+1] && a[x+1] > a[x+2]) res -= a[x+1];
      // if(a[x-1] > a[x] && a[x] < a[x+1]) res += a[x];
      // if(0 <= x-2 && a[x-2] > a[x-1] && a[x-1] < a[x]) res += a[x-1];
      // if(x+2 <= n+1 && a[x] > a[x+1] && a[x+1] < a[x+2]) res += a[x+1];
      // // y
      // if(a[y-1] < a[y] && a[y] > a[y+1]) res -= a[y];
      // if(0 <= y-2 && a[y-2] < a[y-1] && a[y-1] > a[y]) res -= a[y-1];
      // if(y+2 <= n+1 && a[y] < a[y+1] && a[y+1] > a[y+2]) res -= a[y+1];
      // if(a[y-1] > a[y] && a[y] < a[y+1]) res += a[y];
      // if(0 <= y-2 && a[y-2] > a[y-1] && a[y-1] < a[y]) res += a[y-1];
      // if(y+2 <= n+1 && a[y] > a[y+1] && a[y+1] < a[y+2]) res += a[y+1];
      // cout << res << "\n";
	  
      // // x
      // if(a[x-1] < a[x] && a[x] > a[x+1]) res += a[x];
      // if(0 <= x-2 && a[x-2] < a[x-1] && a[x-1] > a[x]) res += a[x-1];
      // if(x+2 <= n+1 && a[x] < a[x+1] && a[x+1] > a[x+2]) res += a[x+1];
      // if(a[x-1] > a[x] && a[x] < a[x+1]) res -= a[x];
      // if(0 <= x-2 && a[x-2] > a[x-1] && a[x-1] < a[x]) res -= a[x-1];
      // if(x+2 <= n+1 && a[x] > a[x+1] && a[x+1] < a[x+2]) res -= a[x+1];
      // // y
      // if(a[y-1] < a[y] && a[y] > a[y+1]) res += a[y];
      // if(0 <= y-2 && a[y-2] < a[y-1] && a[y-1] > a[y]) res += a[y-1];
      // if(y+2 <= n+1 && a[y] < a[y+1] && a[y+1] > a[y+2]) res += a[y+1];
      // if(a[y-1] > a[y] && a[y] < a[y+1]) res -= a[y];
      // if(0 <= y-2 && a[y-2] > a[y-1] && a[y-1] < a[y]) res -= a[y-1];
      // if(y+2 <= n+1 && a[y] > a[y+1] && a[y+1] < a[y+2]) res -= a[y+1];
      cout << res << "\n";
    }
  }
  return 0;
}
