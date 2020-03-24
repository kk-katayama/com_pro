#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int a,b;cin >> a >> b;
  int c = abs( a - b );
  int res = min( 10 - c , c );
  cout << res << "\n";
  return 0;
}
