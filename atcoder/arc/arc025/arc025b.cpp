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
  int bl[110][110],wh[110][110];
  rep(i,h) rep(j,w){
    int c;
    cin >> c;
    bl[i][j] = wh[i][j] = 0;
    if((i+j)%2==0) bl[i][j] = c;
    else wh[i][j] = c;
  }

  int blc[110][110],whc[110][110];
  rep(i,h+1){
    blc[i][0] = whc[i][0] = 0;
  }
  rep(j,w+1){
    blc[0][j] = whc[0][j] = 0;
  }  

  rep1(i,h) rep1(j,w){
    blc[i][j] = bl[i-1][j-1]+blc[i-1][j]+blc[i][j-1]-blc[i-1][j-1];
    whc[i][j] = wh[i-1][j-1]+whc[i-1][j]+whc[i][j-1]-whc[i-1][j-1];    
  }

  int res=0;
  rep(i1,h) rep(j1,w) rep(i2,h) rep(j2,w){
    if(i1>i2||j1>j2) continue;
    int b = blc[i2+1][j2+1] - blc[i1][j2+1] - blc[i2+1][j1] + blc[i1][j1];
    int s = whc[i2+1][j2+1] - whc[i1][j2+1] - whc[i2+1][j1] + whc[i1][j1];
    if(b==s) res = max(res,(i2-i1+1)*(j2-j1+1));
  }
  cout << res << "\n";
  
  return 0;
}
