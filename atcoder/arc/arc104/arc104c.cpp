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
  vi lis(2*n + 1, 0);
  rep(i,n) {
    int a,b; cin >> a >> b;
    if(a != -1 && lis[a] != 0) {
      cout << "No" << "\n";
      return 0;
    }
    if(b != -1 && lis[b] != 0) {
      cout << "No" << "\n";
      return 0;
    }    
    if(a != -1 && b != -1) {
      lis[a] = b;
      lis[b] = a;
    }
    else if(a != -1) {
      lis[a] = -1;
    }
    else if(b != -1) {
      lis[b] = -2;
    }
  }
  
  vvi dp(2*n+1, vi(2*n+1, 0));
  rep1(w,2*n-1) {
    if(w % 2 == 0) continue;
    rep1(l,2*n-1) {
      if(2*n < l + w) break;
      int r = l + w;
      for(int i = l+1; i < r; ++i) {
	dp[l][r] |= (dp[l][i] & dp[i+1][r]);
      }
      int m = (w + 1) / 2;
      int f = 1;
      rep(i,m) {
	int j = i + l;
	if((lis[j] == 0 && lis[j+m] == 0) || (lis[j] == 0 && lis[j+m] == -2) || (lis[j] == -1 && lis[j+m] == 0) || (lis[j] == j + m)) {
	}
	else {
	  f = 0;
	}
      }
      dp[l][r] |= f;
    }
  }

  cout << (dp[1][2*n] ? "Yes" : "No") << "\n";

  
  return 0;
}
