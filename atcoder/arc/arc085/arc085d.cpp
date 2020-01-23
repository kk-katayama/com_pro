#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,z,w;
  cin >> n >> z >> w;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  if(n == 1) cout << abs(a[0]-w) << "\n";
  else cout << max(abs(a[n-1]-w),abs(a[n-2]-a[n-1])) << "\n";
  return 0;
}
