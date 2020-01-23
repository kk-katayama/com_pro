#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int x;
  cin >> x;

  bool f=false;
  rep1(i,1000){
    int y=100*i;
    int d=x-y;
    if(d<0) break;
    if(d<=5*i){
      f=true;
      break;
    } 
  }

  if(f) cout << 1 << "\n";
  else cout << 0 << "\n";
  return 0;
}
