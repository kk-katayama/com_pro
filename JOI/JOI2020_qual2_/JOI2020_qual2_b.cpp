#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(n), t(n);
  rep(i,n) cin >> a[i] >> t[i];

  int maxi = 0;
  rep(i,n) maxi = max(maxi, a[i]);

  int piv = 2 * maxi;

  rep(i,n) {
    int x = a[i] + t[i];
    piv = max(piv, x);
  }

  cout << piv << "\n";
  
  return 0;
}
