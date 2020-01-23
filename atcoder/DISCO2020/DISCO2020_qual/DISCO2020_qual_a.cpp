#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int x,y;
  cin >> x >> y;
  
  int res=0;
  if(x==1){
    res+=300000;
  }
  else if(x==2){
    res+=200000;
  }
  else if(x==3){
    res+=100000;
  }

  if(y==1){
    res+=300000;
  }
  else if(y==2){
    res+=200000;
  }
  else if(y==3){
    res+=100000;
  }

  if(x==1&&y==1) res+=400000;

  cout << res << "\n";
  return 0;
}
