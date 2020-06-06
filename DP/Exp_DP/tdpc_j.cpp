#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n;cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];

  int s = 0;
  rep(i,n) s += (1 << x[i]);

  vector<double> dp((1 << 16), -1);
  dp[0] = 0;
  
  auto rec = [&](auto f, int mask) {
	       if(dp[mask] >= 0) return dp[mask];
	       double res = 1e+15;
	       rep1(i,14) {
		 // 111
		 if( ((mask >> (i-1)) & 1) && ((mask >> i) & 1) && ((mask >> (i+1)) & 1)) {
		   double tmp = f(f, mask - (1 << (i-1)))/3 + f(f, mask - (1 << i))/3 + f(f, mask - (1 << (i+1)))/3 + 1;
		   chmin(res, tmp);
		 }
		 // 110
		 else if( ((mask >> (i-1)) & 1) && ((mask >> i) & 1) && !((mask >> (i+1)) & 1)) {
		   double tmp = f(f, mask - (1 << (i-1)))/3 + f(f, mask - (1 << i))/3 + 1;
		   tmp *= 3./2.;
		   chmin(res, tmp);		   
		 }
		 // 101
		 else if( ((mask >> (i-1)) & 1) && !((mask >> i) & 1) && ((mask >> (i+1)) & 1)) {
		   double tmp = f(f, mask - (1 << (i-1)))/3 + f(f, mask - (1 << (i+1)))/3 + 1;
		   tmp *= 3./2.;
		   chmin(res, tmp);		   
		 }
		 // 011
		 else if( !((mask >> (i-1)) & 1) && ((mask >> i) & 1) && ((mask >> (i+1)) & 1)) {
		   double tmp = f(f, mask - (1 << i))/3 + f(f, mask - (1 << (i+1)))/3 + 1;
		   tmp *= 3./2.;
		   chmin(res, tmp);		   
		 }
		 // 100
		 else if( ((mask >> (i-1)) & 1) && !((mask >> i) & 1) && !((mask >> (i+1)) & 1)) {
		   double tmp = f(f, mask - (1 << (i-1)))/3 + 1;
		   tmp *= 3.;
		   chmin(res, tmp);		   
		 }
		 // 010
		 else if( !((mask >> (i-1)) & 1) && ((mask >> i) & 1) && !((mask >> (i+1)) & 1)) {
		   double tmp = f(f, mask - (1 << i))/3 + 1;
		   tmp *= 3.;
		   chmin(res, tmp);		   
		 }
		 // 001
		 else if( !((mask >> (i-1)) & 1) && !((mask >> i) & 1) && ((mask >> (i+1)) & 1)) {
		   double tmp = f(f, mask - (1 << (i+1)))/3 + 1;
		   tmp *= 3.;
		   chmin(res, tmp);		   
		 }		 
	       }

	       return dp[mask] = res;
	     };

  printf("%.7f\n", rec(rec, s));
  
  return 0;
}
