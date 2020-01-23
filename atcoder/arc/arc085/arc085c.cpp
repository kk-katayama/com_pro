#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  int x = 100*(n-m) + 1900*m;
  cout << ((1<<m))*x << "\n";
  return 0;
}
