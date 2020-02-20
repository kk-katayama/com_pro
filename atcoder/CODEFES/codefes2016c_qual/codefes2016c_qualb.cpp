#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int k,t;
  cin >> k >> t;
  int ax = 0;
  rep(i,t){
    int a;
    cin >> a;
    ax = max(ax,a);
  }

  cout << (int)max(0,2*ax-k-1) << "\n";
  
  return 0;
}
