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
  while(1) {
    int n; cin >> n;
    if(n == 0) break;
    vector<string> f(n);
    vi s(n),w(n);
    rep(i,n) {
      cin >> f[i] >> w[i] >> s[i];
    }

    vi wsum( (1<< n) );
    rep(i, (1<<n)) {
      rep(j,n) {
	if((i >> j) & 1) wsum[i] += w[j];
      }
    }

    vi dp((1<<n), inf);
    dp[0] = 0;
    rep(S,(1<<n)) {
      if(dp[S] == inf) continue;
      rep(i,n) {
	if((S >> i) & 1) continue;
	if(wsum[(1<<n)-1] - (wsum[S] + w[i]) > s[i]) continue;
	chmin(dp[S | (1 << i)], dp[S] + (__builtin_popcount(S) + 1) * w[i]);
      }
    }

    
    
    vi res;
    int mask = (1 << n) - 1;
    rep(i,n) {
      rep(j,n) {
	if((mask >> j) & 1) {
	  if(dp[mask] - (n - i)*w[j] == dp[mask - (1 << j)]) {
	    res.push_back(j);
	    mask -= (1 << j);
	    break;
	  }
	}
      }
    }

    reverse(res.begin(), res.end());
    rep(i,n) {
      cout << f[res[i]] << "\n";
    }
    
  }
  
  return 0;
}
