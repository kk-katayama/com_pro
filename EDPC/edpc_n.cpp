#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
vector<ll> a;
vector<vector<ll>> dp;
vector<ll> sum;
ll rec(int left, int right) {
  if(left + 1 == right) return 0;
  if(dp[left][right] > 0) return dp[left][right];
  ll res = 1e+18;
  for (int i = left + 1; i < right; ++i) {
    chmin(res, rec(left, i) + rec(i, right) + sum[i] - sum[left] + sum[right] - sum[i]);
  }
  return dp[left][right] = res;
}

int main()
{
  int n;cin >> n;
  a.resize(n);
  rep(i,n) cin >> a[i];
  sum.resize(n+1, 0);
  rep(i,n) sum[i+1] = sum[i] + a[i];
  
  dp.resize(n+1, vector<ll>(n+1, 0));
  
  cout << rec(0, n) << "\n";
  
  return 0;
}
