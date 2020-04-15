#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int k;cin >> k;
  int res = 0;
  rep1(i,k) rep1(j,k) rep1(l,k) {
    res += gcd(i,gcd(j,l));
  }
  cout << res << "\n";
  return 0;
}
