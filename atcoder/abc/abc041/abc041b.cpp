#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll mod = 1e+9+7;
  ll a,b,c;cin >> a >> b >> c;
  ll res = (((a*b)%mod)*c)%mod;
  cout << res << "\n";
  return 0;
}
