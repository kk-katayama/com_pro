#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
int main()
{
  cin >> n;

  rep(i,n-1){
    rep(j,n){
      if(i>=j) continue;
      int x = i^j;
      int k = 0;
      while(!((x>>k)&1)) k++;
      cout << k+1 << " ";
    }
    cout  << "\n";
  }
  
  return 0;
}
