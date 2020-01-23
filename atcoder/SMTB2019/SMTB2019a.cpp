#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int m1,m2,d1,d2;
  cin >> m1;
  cin >> d1;
  cin >> m2;
  cin >> d2;
  if(m1!=m2) cout << 1 << "\n";
  else cout << 0 << "\n";
  return 0;
}
