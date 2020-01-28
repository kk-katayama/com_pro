#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;
  string res = "";
  rep(i,tx-sx){
    res += 'R';
  }
  rep(i,ty-sy){
    res += 'U';
  }
  rep(i,tx-sx){
    res += 'L';
  }
  rep(i,ty-sy){
    res += 'D';
  }  
  res += 'D';
  rep(i,tx-sx+1){
    res += 'R';
  }
  rep(i,ty-sy+1){
    res += 'U';
  }
  res += 'L';
  res += 'U';
  rep(i,tx-sx+1){
    res += 'L';
  }
  rep(i,ty-sy+1){
    res += 'D';
  }  
  res += 'R';
  cout << res << "\n";
  return 0;
}
