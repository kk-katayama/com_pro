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
int main()
{
  int n; cin >> n;
  vector<int> a(3*n);
  rep(i,3*n) {
    cin >> a[i];
    a[i]--;
  }
  
  using vi = vector<int>;
  using vii = vector<vi>;
  vii dp(n, vi(n, -1));
  int res = 0;
  int ax = 0;
  dp[a[0]][a[1]] = 0;
  rep(i,n) {
    map<pi,int> ndp;
    int k = 3*i + 2;
    if(i == n-1) {
      if(dp[a[k]][a[k]] >= 0) chmax(ndp[{a[k], a[k]}], dp[a[k]][a[k]] + 1);
      for(auto val: ndp) {
	int x = val.F.F, y = val.F.S, z = val.S;
	chmax(dp[x][y], z);
      }
      continue;
    }
    if(a[k] == a[k+1] && a[k+1] == a[k+2]) {
      res++;
      continue;
    }
    if(a[k] == a[k+1]) {
      rep(j,n) {
	if(dp[a[k]][j] >= 0) {
	  chmax(ndp[{a[k+2], j}], dp[a[k]][j] + 1);
	  chmax(ndp[{j, a[k+2]}], dp[a[k]][j] + 1);
	}
	if(dp[j][a[k]] >= 0) {
	  chmax(ndp[{a[k+2], j}], dp[j][a[k]] + 1);
	  chmax(ndp[{j, a[k+2]}], dp[j][a[k]] + 1);
	}	
      }
    }
    if(a[k+1] == a[k+2]) {
      rep(j,n) {
	if(dp[a[k+1]][j] >= 0) {
	  chmax(ndp[{a[k], j}], dp[a[k+1]][j] + 1);
	  chmax(ndp[{j, a[k]}], dp[a[k+1]][j] + 1);
	}
	if(dp[j][a[k+1]] >= 0) {
	  chmax(ndp[{a[k], j}], dp[j][a[k+1]] + 1);
	  chmax(ndp[{j, a[k]}], dp[j][a[k+1]] + 1);
	}	
      }
    }
    if(a[k] == a[k+2]) {
      rep(j,n) {
	if(dp[a[k]][j] >= 0) {
	  chmax(ndp[{a[k+1], j}], dp[a[k]][j] + 1);
	  chmax(ndp[{j, a[k+1]}], dp[a[k]][j] + 1);
	}
	if(dp[j][a[k]] >= 0) {
	  chmax(ndp[{a[k+1], j}], dp[j][a[k]] + 1);
	  chmax(ndp[{j, a[k+1]}], dp[j][a[k]] + 1);
	}	
      }
    }
    if(dp[a[k]][a[k]] >= 0) {
      chmax(ndp[{a[k+1], a[k+2]}], dp[a[k]][a[k]] + 1);
      chmax(ndp[{a[k+2], a[k+1]}], dp[a[k]][a[k]] + 1);      
    }
    if(dp[a[k+1]][a[k+1]] >= 0) {
      chmax(ndp[{a[k], a[k+2]}], dp[a[k+1]][a[k+1]] + 1);
      chmax(ndp[{a[k+2], a[k]}], dp[a[k+1]][a[k+1]] + 1);      
    }
    if(dp[a[k+2]][a[k+2]] >= 0) {
      chmax(ndp[{a[k], a[k+1]}], dp[a[k+2]][a[k+2]] + 1);
      chmax(ndp[{a[k+1], a[k]}], dp[a[k+2]][a[k+2]] + 1);      
    }

    chmax(ndp[{a[k], a[k+1]}], ax);
    chmax(ndp[{a[k+1], a[k]}], ax);
    chmax(ndp[{a[k], a[k+2]}], ax);
    chmax(ndp[{a[k+2], a[k]}], ax);
    chmax(ndp[{a[k+2], a[k+1]}], ax);
    chmax(ndp[{a[k+1], a[k+2]}], ax);        
    
    rep(j,n) {
      if(dp[a[k]][j] >= 0) {
	chmax(ndp[{a[k], j}], dp[a[k]][j]);
	chmax(ndp[{j, a[k]}], dp[a[k]][j]);
      }
      if(dp[a[k+1]][j] >= 0) {
	chmax(ndp[{a[k+1], j}], dp[a[k+1]][j]);
	chmax(ndp[{j, a[k+1]}], dp[a[k+1]][j]);
      }
      if(dp[a[k+2]][j] >= 0) {
	chmax(ndp[{a[k+2], j}], dp[a[k+2]][j]);
	chmax(ndp[{j, a[k+2]}], dp[a[k+2]][j]);
      }
      if(dp[j][a[k]] >= 0) {
	chmax(ndp[{a[k], j}], dp[j][a[k]]);
	chmax(ndp[{j, a[k]}], dp[j][a[k]]);
      }
      if(dp[j][a[k+1]] >= 0) {
	chmax(ndp[{a[k+1], j}], dp[j][a[k+1]]);
	chmax(ndp[{j, a[k+1]}], dp[j][a[k+1]]);
      }
      if(dp[j][a[k+2]] >= 0) {
	chmax(ndp[{a[k+2], j}], dp[j][a[k+2]]);
	chmax(ndp[{j, a[k+2]}], dp[j][a[k+2]]);
      }                        
    }
    for(auto val: ndp) {
      int x = val.F.F, y = val.F.S, z = val.S;
      chmax(dp[x][y], z);
      chmax(ax, z);
    }
  }


  int tmp = 0;
  rep(i,n) rep(j,n) {
    chmax(tmp, dp[i][j]);
  }
  cout << res + tmp << "\n";
  
  return 0;
}
