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
    int n; scanf("%d", &n);
    int cnt = 0;
    int id = -1;
    vi f(n, 0);
    rep(i,n) {
      int k; scanf("%d", &k);
      bool ff = true;
      vi g(k);
      rep(j,k) scanf("%d", &g[j]);
      rep(j,k) {
	g[j]--;
	if(f[g[j]] == 0) {
	  f[g[j]] = 1;
	  ff = false;
	  cnt++;
	  break;
	}
      }
      if(ff) {
	id = i;
      }
    }
    if(cnt == n) {
      cout << "OPTIMAL" << "\n";
    }
    else {
      cout << "IMPROVE" << "\n";
      cout << id+1 << " ";
      rep(i,n) {
	if(f[i] == 0) {
	  cout << i+1 << "\n";
	  break;
	}
      }
    }
  }
  return 0;
}
