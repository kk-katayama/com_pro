#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int M = 30*7;
  map<int, double> dp;
  auto rec = [&](auto f, int i)-> double{
	       if(i >= M) return 0;
	       if(dp[i] != 0) return dp[i];
	       double res = 1;
	       res += f(f, i + 40)/9;
	       res += f(f, i + 30)*2/9;
	       res += f(f, i + 25)*2/9;
	       res += f(f, i + 20)/9;
	       res += f(f, i + 15)*2/9;
	       res += f(f, i + 10)/9;
	       return dp[i] = res;
	     };
  printf("%.7f\n", rec(rec, 0));
  return 0;
}
