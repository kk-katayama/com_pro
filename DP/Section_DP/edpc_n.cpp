#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
typedef long long ll;
const ll INFLL = 1e+17;
int n;
ll a[410];
ll sum[410];
ll dp[410][410];
bool f[410][410];
ll rec(int i,int j){
  if(f[i][j]) return dp[i][j];
  f[i][j] = true;
  if(i==j) return dp[i][j] = 0;
  ll res = INFLL;
  rep1(k,j-i+1){
    res = min( res , rec(i+k,j) + rec(i,i+k-1) + sum[j+1] - sum[i] );
  }
  return dp[i][j] = res;
}
int main()
{
  cin >> n;
  rep(i,n) cin >> a[i];

  rep(i,n) rep(j,n) f[i][j] = false;

  sum[0] = 0;
  rep(i,n){
    sum[i+1] = sum[i] + a[i];
  }

  cout << rec(0,n-1) << "\n";
  
  return 0;
}
