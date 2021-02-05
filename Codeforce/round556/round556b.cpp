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
  string s; cin >> s;
  vvi tab(n+2, vi(26, n));
  for (int i = n-1; i >= 0; --i) {
    int c = int(s[i] - 'a');
    tab[i][c] = i;
    rep(j,26) {
      chmin(tab[i][j], tab[i+1][j]);
    }
  }
  using vvvi = vector<vvi>;
  vvvi dp(251, vvi(251, vi(251, n)));
  dp[0][0][0] = -1;
  vi cnt(3, 0);
  vector<string> ss(3);  
  auto update = [&](int x, int y, int z) {
    int res = inf;
    if(x-1 >= 0 && sz(ss[0]) > x-1) chmin(res, tab[dp[x-1][y][z]+1][int(ss[0][x-1] - 'a')]);
    if(y-1 >= 0 && sz(ss[1]) > y-1) chmin(res, tab[dp[x][y-1][z]+1][int(ss[1][y-1] - 'a')]);
    if(z-1 >= 0 && sz(ss[2]) > z-1) chmin(res, tab[dp[x][y][z-1]+1][int(ss[2][z-1] - 'a')]);
    return dp[x][y][z] = res;
  };
  while(m-- > 0) {
    char t; cin >> t;
    if(t == '+') {
      int a; cin >> a;
      char c; cin >> c;
      a--;
      cnt[a]++;
      ss[a].push_back(c);
      int cc = int(c - 'a');
      if(a == 0) {
	rep(j,251) {
	  rep(k,251) {
	    update(cnt[a], j, k);
	  }
	}
      }
      if(a == 1) {
	rep(i,251) {
	  rep(k,251) {
	    update(i, cnt[a], k);
	  }
	}
      }      
      if(a == 2) {
	rep(i,251) {
	  rep(j,251) {
	    update(i, j, cnt[a]);
	  }
	}
      }
      //      cout << dp[1][1][0] << "\n";
      //      cout << dp[cnt[0]][cnt[1]][cnt[2]] << "\n";
      if(dp[cnt[0]][cnt[1]][cnt[2]] < n) cout << "YES" << "\n";
      else cout << "NO" << "\n";
    }
    else {
      int a; cin >> a;
      a--;
      ss[a].pop_back();
      if(a == 0) {
	rep(j,251) {
	  rep(k,251) {
	    dp[cnt[0]][j][k] = n;
	  }
	}
      }
      if(a == 1) {
	rep(i,251) {
	  rep(k,251) {
	    dp[i][cnt[1]][k] = n;	    
	  }
	}
      }      
      if(a == 2) {
	rep(i,251) {
	  rep(j,251) {
	    dp[i][j][cnt[2]] = n;	    	    
	  }
	}
      }
      cnt[a]--;
      if(dp[cnt[0]][cnt[1]][cnt[2]] < n) cout << "YES" << "\n";
      else cout << "NO" << "\n";      
    }
  }
  
  return 0;
}
