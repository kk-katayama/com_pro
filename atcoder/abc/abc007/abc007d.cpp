#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll a,b;
vector<ll> avec,bvec;
ll dp[25][10][2][2];
int main()
{
  cin >> a >> b;
  a--;
  
  while(a!=0){
    avec.push_back(a%10);
    a /= 10;
  }
  while(b!=0){
    bvec.push_back(b%10);
    b /= 10;
  }

  reverse(avec.begin(), avec.end());
  reverse(bvec.begin(), bvec.end());  
  
  int as = avec.size(),bs = bvec.size();
  
  rep(i,as+1) rep(j,10) rep(k,2) rep(l,2) dp[i][j][k][l] = 0;
  dp[0][0][0][0] = 1;
  
  rep(i,as) rep(j,10) rep(k,2) rep(l,2){
    rep(jj,(k?10:(*(avec.begin()+i)+1))){
      dp[i+1][jj][k||jj<*(avec.begin()+i)][l||jj==4||jj==9] += dp[i][j][k][l];
    }
  }
  
  ll acnt = 0;
  rep(j,10) rep(k,2) acnt += dp[as][j][k][1];

  rep(i,bs+1) rep(j,10) rep(k,2) rep(l,2) dp[i][j][k][l] = 0;
  dp[0][0][0][0] = 1;
  
  rep(i,bs) rep(j,10) rep(k,2) rep(l,2){
    rep(jj,(k?10:(*(bvec.begin()+i)+1))){
      dp[i+1][jj][k||jj<*(bvec.begin()+i)][l||jj==4||jj==9] += dp[i][j][k][l];
    }
  }
  
  ll bcnt = 0;
  rep(j,10) rep(k,2) bcnt += dp[bs][j][k][1];
  
  cout << bcnt - acnt << "\n";
  
  
  
  return 0;
}
