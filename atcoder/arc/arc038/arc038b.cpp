#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,w;
  cin >> h >> w;
  vector<vector<char>> c(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> c[i][j];
    }
  }

  vector<vector<bool>> dp(h,vector<bool>(w,false));
  for(int i=h-1;i>=0;--i){
    for(int j=w-1;j>=0;--j){
      bool f = false;
      if(c[i][j]=='#') continue;      
      rep(x,2){
	rep(y,2){
	  if(x==0&&y==0) continue;
	  if(i+x>=h) continue;
	  if(j+y>=w) continue;
	  if(c[i+x][j+y]=='#') continue;
	  if(!dp[i+x][j+y]){
	    f = true;
	  }
	}
      }
      dp[i][j] = f;
    }
  }

  // rep(i,h){
  //   rep(j,w){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout  << "\n";
  // }
  
  if(dp[0][0]) cout << "First" << "\n";
  else cout << "Second" << "\n";
  
  return 0;
}
