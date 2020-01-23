#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
pair<int,int> second_max(pair<int,int> a,pair<int,int> b){
  vector<int> v(0);
  v.push_back(a.first);
  v.push_back(a.second);
  v.push_back(b.first);
  v.push_back(b.second);
  sort(v.begin(), v.end());
  
  return make_pair(v[3],v[2]);
  
}
int main()
{
  int n;
  cin >> n;
  int m = (1<<n);
  vector<int> a(m);
  rep(i,m) cin >> a[i];

  vector<vector<pair<int,int>>> dp(m);
  rep(i,m) dp[i].resize(n+1);
  rep(i,m) dp[i][0] = make_pair(a[i],0);

  rep(j,n){
    rep(i,m){
      if(i&(1<<j)){
	dp[i][j+1] = second_max(dp[i][j],dp[i&~(1<<j)][j]);
      }
      else{
	dp[i][j+1] = dp[i][j];
      }
    }
  }

  vector<int> arr(m);
  rep1(i,m-1){
    arr[i] = dp[i][n].first + dp[i][n].second;
  }

  int res = 0;
  rep1(i,m-1){
    res = max(res,arr[i]);
    cout << res << "\n";
  }
  return 0;
}
