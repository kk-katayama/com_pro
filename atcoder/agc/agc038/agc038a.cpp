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
  int a,b;
  cin >> a >> b;
  
  rep(i,h-b){
    rep(j,w-a) cout << 0;
    rep(j,a) cout << 1;
    cout  << "\n";
  }

  rep(i,b){
    rep(j,w-a) cout << 1;
    rep(j,a) cout << 0;
    cout  << "\n";
  }

  
  return 0;
}
