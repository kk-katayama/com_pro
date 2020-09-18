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
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
using ld = long double;
int main()
{
  int n; cin >> n;
  ll d; cin >> d;

  int c2 = 0, c3 = 0, c5 = 0;
  while(d % 2 == 0) {
    d /= 2;
    c2++;
  }
  while(d % 3 == 0) {
    d /= 3;
    c3++;
  }
  while(d % 5 == 0) {
    d /= 5;
    c5++;
  }  

  if(d != 1) {
    printf("%.7Lf\n", (ld)0);
    return 0;
  }

  using vd = vector<ld>;
  using vdd = vector<vd>;
  using vddd = vector<vdd>;

  vddd dp(c2+1, vdd(c3+1, vd(c5+1, 0)));
  dp[0][0][0] = 1;
  rep(i,n) {
    vddd ndp(c2+1, vdd(c3+1, vd(c5+1, 0)));
    rep(j,c2+1) {
      rep(k,c3+1) {
	rep(l,c5+1) {
	  ndp[j][k][l] += dp[j][k][l] / 6; 
	  ndp[min(c2, j+1)][k][l] += dp[j][k][l] / 6;
	  ndp[j][min(c3, k+1)][l] += dp[j][k][l] / 6;	  
	  ndp[min(c2, j+2)][k][l] += dp[j][k][l] / 6;
	  ndp[j][k][min(c5, l+1)] += dp[j][k][l] / 6;
	  ndp[min(c2, j+1)][min(c3, k+1)][l] += dp[j][k][l] / 6;	  
	}
      }
    }
    dp = ndp;
  }

  printf("%.7Lf\n", dp[c2][c3][c5]);
  
  return 0;
}
