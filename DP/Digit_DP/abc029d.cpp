#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
string n;
ll dp[10][10][2][10];
int main()
{
  cin >> n;

  int ns = n.size();

  rep(i,ns+1) rep(j,10) rep(k,2) rep(l,ns+1) dp[i][j][k][l] = 0;
  dp[0][0][0][0] = 1;

  rep(i,ns) rep(j,10) rep(k,2) rep(l,ns+1){
    int ni = n[i] - '0';
    rep(jj,(k?10:ni+1)){
      dp[i+1][jj][k||jj<ni][l+(jj==1)] += dp[i][j][k][l];
    }
  }

  ll res = 0;

  rep(j,10) rep(k,2) rep1(l,ns){
    res += dp[ns][j][k][l] * l;
  }

  cout << res << "\n";
  
  return 0;
}
