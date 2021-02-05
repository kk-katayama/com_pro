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
    int n; cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    
    int res = 1;
    int root = 0;
    int cnt = 0;
    rep(i,n-1) {
      if(a[i] < a[i+1]) cnt++;
      else {
	root--;
	if(root < 0) {
	  res++;
	  root = cnt - 1;
	  cnt = 1;
	}
	else cnt++;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
