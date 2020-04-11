#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n;cin >> n;
  ll x;cin >> x;

  vector<ll> b(n+1);
  vector<ll> p(n+1);
  b[0] = 1;
  p[0] = 1;
  rep(i,n) {
    b[i+1] = b[i]*2 + (ll)3;
    p[i+1] = p[i]*2 + (ll)1;    
  }

  int index = n;
  ll res = 0;
  while(index > 0) {
    ll th = b[index-1] + (ll)2;
    if(x < th) {
      x--;
      index--;
    }
    else if(x > th) {
      res += p[index-1] + (ll)1;
      x -= th;
      index--;
    }
    else {
      res += p[index-1] + (ll)1;
      break;
    }
    if(x <= 0) break;
    if(index == 0) res += (ll)1;

  }

  cout << res << "\n";
  
  return 0;
}
