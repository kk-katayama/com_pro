#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int s,k;
  cin >> k >> s;
  int cnt=0;
  rep(x,k+1){
    rep(y,k+1){
      int z = s-(x+y);
      if(0<=z&&z<=k){
	cnt++;
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
