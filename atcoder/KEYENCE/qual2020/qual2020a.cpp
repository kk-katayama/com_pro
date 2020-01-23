#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int h,w,n;
  cin >> h >> w >> n;

  int x = max(h,w);
  if(n%x==0){
    cout << n/x << "\n";
  }
  else{
    cout << n/x + 1 << "\n";
  }
  return 0;
}
