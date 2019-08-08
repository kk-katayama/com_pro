#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
const int INF = 1e+9;
int dp[30010];
bool C(int x,int a){
  return dp[x] > a;
}
int upper(int l,int r,int a){
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(C(mid,a)) ub=mid;
    else lb=mid;
  }
  return ub;
}
int n;
int c[30010];
int main()
{
  cin >> n;
  rep(i,n) cin >> c[i];

  rep(i,n+1) dp[i] = INF;

  rep(i,n){
    int index = upper(0,n-1,c[i]);
    dp[index] = c[i];
  }
  int res;
  rep(i,n+1){
    if(dp[i]==INF){
      res=i;
      break;
    }
  }
  cout << n-res << "\n";
  
  return 0;
}
