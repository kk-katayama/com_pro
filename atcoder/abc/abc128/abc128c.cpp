#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<vector<int>> li(m,vector<int>(n,0));
  rep(i,m){
    int k;cin >> k;
    rep(j,k){
      int x;cin >> x;x--;
      li[i][x] = 1;
    }
  }
  vector<int> p(m);
  rep(i,m) cin >> p[i];

  int res=0;
  rep(S,(1<<n)){
    bool f = true;
    rep(i,m){
      int cnt=0;
      rep(j,n){
	if(((S>>j)&1)&li[i][j]) cnt++;
      }
      if(cnt%2!=p[i]) f=false;
    }
    if(f) res++;
  }
  cout << res << "\n";
  return 0;
}
