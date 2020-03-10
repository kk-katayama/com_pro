#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int R,G,B,n;cin >> R >> G >> B >> n;
  int res=0;
  rep(r,3001) rep(g,3001){
    if(n-r*R-g*G<0) break;
    if((n-r*R-g*G)%B==0) res++;
  }
  cout << res << "\n";
  return 0;
}
