#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int h,w;cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  vector<vector<ll>> rsum(h,vector<ll>(w+1,0));
  rep(i,h) rep(j,w){
    if(s[i][j]=='O') rsum[i][j+1] = rsum[i][j] + 1;
    else rsum[i][j+1] = rsum[i][j];
  }
  vector<vector<ll>> csum(h+1,vector<ll>(w,0));
  rep(j,w) rep(i,h){
    if(s[i][j]=='I') csum[i+1][j] = csum[i][j] + 1;
    else csum[i+1][j] = csum[i][j];
  }

  ll res = 0;
  rep(i,h) rep(j,w){
    if(s[i][j]=='J'){
      res += (rsum[i][w]-rsum[i][j])*(csum[h][j]-csum[i][j]);
    }
  }
  cout << res << "\n";
  return 0;
}
