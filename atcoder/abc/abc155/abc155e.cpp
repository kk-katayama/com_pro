#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int dp[1100000][2];
int main()
{
  string s;
  cin >> s;
  int inf = 1e+9;
  reverse(s.begin(), s.end());
  s.push_back('0');
  
  int n = s.size();
  rep(i,n+1) rep(f,2) dp[i][f] = inf;
  dp[0][0]=0;
  
  rep(i,n+1){
    int d = (int)s[i]-'0';
    rep(j,10){
      rep(f,2){
	int k = j;
	if(f) k--;
	if(k>=d) dp[i+1][0] = min(dp[i+1][0],dp[i][f]+j+k-d);
	else dp[i+1][1] = min(dp[i+1][1],dp[i][f]+j+k-d+10);
      }
    }
  }


  cout << dp[n][0] << "\n";


  return 0;
}
