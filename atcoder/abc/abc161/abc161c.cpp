#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,k;cin >> n >> k;
  ll x = n % k;
  ll y = - ( x - k);
  cout << min(x, y) << "\n";
  return 0;
}
