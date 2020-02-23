#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,r;
  cin >> n >> r;
  if(n>=10) cout << r << "\n";
  else cout << r + 100*(10-n) << "\n";
  return 0;
}
