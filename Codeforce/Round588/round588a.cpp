#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  vector<int> a(4);
  rep(i,4) cin >> a[i];

  for(int S=0;S<(1<<4);++S){
    int x = 0;
    int y = 0;
    for(int i=0;i<4;++i){
      if((S>>i)&1){
	x += a[i];
      }
      else{
	y += a[i];
      }
    }
    if(x==y){
      cout << "YES" << "\n";
      return 0;
    }
  }
  cout << "NO" << "\n";
  return 0;
}
