#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int m,d;
int main()
{
  cin >> m >> d;
  int cnt=0;
  for(int i=22;i<=d;++i){
    int a = i%10,b=i/10;
    if(a>=2&&b>=2&&a*b<=m) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}
