#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  string s; cin >> s;
  int k; cin >> k;
  vector<int> d(k);
  rep(i,k) cin >> d[i];
  
  set<int> st;
  rep(i,k) st.insert(d[i]);
  
  vector<int> x;
  rep(i,10) if( st.find(i) == st.end() ) x.push_back(i);

  int n = s.size();
  const int inf = 1e+9;
  vector<vector<int>> dp(n+1, vector<int>(2, inf));
  if(x[0] == 0) dp[0][1] = x[1];
  else dp[0][1] = x[0];
  dp[0][0] = 0;
  rep(i,n) {
    int m = s[i] - '0';
    rep(j,x.size()) {
      chmin(dp[i+1][1], dp[i][1]*10 + x[j]);
      if(m == x[j]) {
	chmin(dp[i+1][0], dp[i][0]*10 + x[j]);
      }
      else if(m < x[j]) {
	chmin(dp[i+1][1], dp[i][1]*10 + x[j]);
	chmin(dp[i+1][1], dp[i][0]*10 + x[j]);
      }
    }
  }
  
  cout << min(dp[n][0], dp[n][1]) << "\n";
  
  return 0;
}
