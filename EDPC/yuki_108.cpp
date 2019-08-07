#include <iostream>
#include <algorithm>
#include <cstdio>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
int n;
int a[110];
double dp[110][110][110];
double rec(int i,int j,int k){
  if(dp[i][j][k] >= 0) return dp[i][j][k];
  int sum = i + j + k;
  double res = 0;

  if(i != 0) res += (double)i/sum * rec(i-1,j,k);
  if(j != 0) res += (double)j/sum * rec(i+1,j-1,k);
  if(k != 0) res += (double)k/sum * rec(i,j+1,k-1);
  res += (double)n/sum;

  return dp[i][j][k] = res;
}
int main()
{
  cin >> n;
  rep(i,n) cin >> a[i];

  rep(i,n+1) rep(j,n+1) rep(k,n+1) dp[i][j][k] = -1;
  dp[0][0][0] = 0;

  int one = 0,two = 0,thr = 0;
  rep(i,n){
    int x = max( 3-a[i] , 0 );
    if(x==1) one++;
    else if(x==2) two++;
    else if(x==3) thr++;
  }
  
  printf("%.7f\n", rec(one,two,thr));

  
  return 0;
}
