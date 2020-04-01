#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,w,k;cin >> h >> w >> k;
  vector<vector<char>> s(h,vector<char>(w));
  rep(i,h) rep(j,w) cin >> s[i][j];

  vector<vector<int>> sum(h+1,vector<int>(w+1,0));
  rep1(i,h) rep1(j,w){
    int x = s[i-1][j-1] - '0';
    sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + x;
  }

  // rep(i,h+1){
  //   rep(j,w+1) cout << sum[i][j] << " ";
  //   cout << "\n";
  // }
  
  int res = 1e+9;
  rep(mask,(1<<h)){
    //    if(mask == 1) break;
    vector<int> v;
    v.push_back(0);
    rep(i,h) if((mask >> i) & 1) v.push_back(i+1);
    v.push_back(h);
    int left = 0,cnt = 0;
    bool f = true;
    rep1(j,w){
      rep(i,v.size()-1){
  	int x = sum[ v[i+1] ][j] - sum[ v[i] ][j] - sum[ v[i+1] ][left] + sum[ v[i] ][left];
  	if(x > k){
  	  if(j - left == 1){
  	    f = false;
  	    break;
  	  }
  	  cnt++;
  	  left = --j;
  	}
      }
      if(!f) break;
    }
    int y =__builtin_popcount(mask);
    //    if(f && cnt + y < res) cout << mask << ":" << cnt + y << "\n";
    if(f) res = min(res , cnt + y);
  }

  cout << res << "\n";
  
  return 0;
}
