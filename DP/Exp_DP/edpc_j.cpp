#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
double dp[310][310][310];
int main()
{
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  rep(i,n+1) rep(j,n+1) rep(k,n+1) dp[i][j][k] = -1;
  dp[0][0][0] = 0;
  
  auto rec = [&](auto f, int i, int j, int k)-> double{
	       if(i < 0 || j < 0 || k < 0) return 0;
	       if(dp[i][j][k] >= 0) return dp[i][j][k];
	       double res = n;
	       res += i*f(f, i-1, j, k);
	       res += j*f(f, i+1, j-1, k);
	       res += k*f(f, i, j+1, k-1);
	       res /= (double)(i + j + k);
	       return dp[i][j][k] = res;
	     };
  
  vector<int> cnt(3, 0);
  rep(i,n) cnt[a[i]-1]++;
  printf("%.9f\n", rec(rec, cnt[0], cnt[1], cnt[2]));
  
  return 0;
}
