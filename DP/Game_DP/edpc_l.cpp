#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
typedef long long ll;
int n;
ll a[3010];
ll dp[3010][3010];
bool f[3010][3010];
ll rec(int i,int j){
  if(f[i][j]) return dp[i][j];
  f[i][j] = true;
  if(i==j) return dp[i][j] = a[i];
  return dp[i][j] = max( a[i] - rec(i+1,j) , a[j] - rec(i,j-1));
}
int main()
{
  cin >> n;
  rep(i,n) cin >> a[i];
  
  rep(i,n) rep(j,n) f[i][j] = false;

  cout << rec(0,n-1) << "\n";
  
  return 0;
}
