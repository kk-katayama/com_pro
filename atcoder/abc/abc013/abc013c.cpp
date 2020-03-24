#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,h;cin >> n >> h;
  ll a,b,c,d,e;cin >> a >> b >> c >> d >> e;
  ll res = 1e+15;
  for ( ll i = 0; i <= n; ++i ) {
    ll x = i * e;
    if ( x < h ) res = min ( res , c * ( n - i ) );
    else {
      ll y = x - h;
      ll z = y - d * ( n - i );
      if ( z < 0 ) res = min ( res , c * ( n - i ) );
      else {
	ll w = z / ( b - d ) + 1;
	if ( w > n - i ) continue;
	else res = min ( res , a * w + c * ( n - i - w ) );
      }
    }
  }
  
  cout << res << "\n";

  return 0;
}
