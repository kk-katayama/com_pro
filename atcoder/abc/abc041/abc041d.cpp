#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n,m;cin >> n >> m;
  vector<vector<int>> vec(n);
  rep(i,m){
    int x,y;cin >> x >> y;x--;y--;
    vec[y].push_back(x);
  }

  vector<ll> dp((1<<n),0);
  dp[0] = 1;
  rep(S,(1<<n)){
    rep(i,n){
      if((S>>i)&1) continue;
      bool f = true;
      for(int v:vec[i]) if((S>>v)&1) f = false; 
      if(f) dp[S|(1<<i)] += dp[S];
    }
  }
  cout << dp[(1<<n)-1] << "\n";
  
  return 0;
}
