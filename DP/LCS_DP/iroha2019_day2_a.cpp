#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct LCS{
  int n;
  int m;
  string s;
  string t;
  vector<vector<int>> dp;

  LCS(string _s,string _t){
    s = _s;
    t = _t;
    n = s.size();
    m = t.size();
    vector<int> temp(m+1,0);
    dp.assign(n+1,temp);
  }

  int solve(){
    rep(i,n){
      rep(j,m){
	if(s[i]==t[j]){
	  dp[i+1][j+1] = dp[i][j] + 1;
	}
	else{
	  dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
	}
      }
    }
    return dp[n][m];
    
  }

  //LCSの復元。solve()の後に行う
  string restore(){
  }
  
};
int main()
{
  string s,t;
  cin >> s >> t;

  LCS lcs(s,t);
  cout << lcs.solve()+1 << "\n";
  
  return 0;
}
