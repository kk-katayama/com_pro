#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,m;cin >> n >> m;
  vector<string> p(n);
  rep(i,n) {
    cin >> p[i];
  }

  vector<vector<int>> cost(n, vector<int>(n, 0));
  
  rep(i,n) {
    rep(j,n) {
      rep(k,m) {
	if(p[i][k] != p[j][k] && p[i][k] != '*' && p[j][k] != '*') cost[i][j] = 1;
      }
    }
  }
  auto merge = [&](int a, int b)-> bool{
		 if(a == 0 || b == 0) return true;
  		 bool f = true;
  		 rep(i,n) {
  		   rep(j,n) {
  		     if( ((a >> i) & 1) && ((b >> j) & 1) && cost[i][j] == 1) f = false;
  		   }
  		 }
  		 return f;
  	       };

  int inf = 1e+9;
  vector<int> dp((1 << n), 0);
  dp[0] = 1;
  auto rec = [&](auto f, int mask)-> int{
	       if(dp[mask] > 0) return dp[mask];
  	       int res = inf;
  	       for (int i = mask; i > 0; i = (i-1) & mask) {
		 if(i == mask) continue;
  		 if(merge(i, mask-i)) {
  		   chmin(res, max(f(f, i), f(f, mask - i)));
  		 }
  		 else {
  		   chmin(res, f(f, i) + f(f, mask - i));
  		 }
  	       }
  	       return dp[mask] = (res == inf ? 1 : res);
  	     };

  cout << rec(rec,(1 << n) - 1) << "\n";
  
  return 0;
}
