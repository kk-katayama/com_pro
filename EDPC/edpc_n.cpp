#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i] + a[i];

  vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
  
  auto rec = [&](auto f, int l, int r)-> ll{
	       if(r - l == 1) return dp[l][r] = 0;
	       if(dp[l][r] > 0) return dp[l][r];
	       ll res = 1e+15;
	       for (int i = l+1; i < r; ++i) {
		 chmin(res, f(f, l, i) + f(f, i, r));
	       }
	       return dp[l][r] = res + sum[r] - sum[l];
	     };

  cout << rec(rec, 0, n) << "\n";
  
  return 0;
}
