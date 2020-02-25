#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int r,c;cin >> r >> c;
  vector<vector<int>> a(r,vector<int>(c));
  rep(i,r) rep(j,c) cin >> a[i][j];
  int res=0;
  rep(S,(1<<r)){
    int sum=0;
    rep(j,c){
      int cnt=0;
      rep(i,r){
	if((((S>>i)&1)^a[i][j])==0) cnt++;
      }
      sum += max(cnt,r-cnt);
    }
    res = max(res,sum);
  }
  cout << res << "\n";
  return 0;
}
