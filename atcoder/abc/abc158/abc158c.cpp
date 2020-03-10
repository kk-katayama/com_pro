#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b;cin >> a >> b;
  rep1(i,10000){
    if(8*i/100==a&&i/10==b){
      cout << i << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}
