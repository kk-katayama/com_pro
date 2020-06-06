#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll a,b,n;cin >> a >> b >> n;
  // if(b == 1) {
  //   cout << 0 << "\n";
  //   return 0;
  // }
  if(b <= n) {
    ll x = b - 1;
    ll res = (a*x)/b - a*(x/b);
    cout << res << "\n";
  }
  else {
    ll x = n;
    ll res = (a*x)/b - a*(x/b);
    cout << res << "\n";
  }
  
  return 0;
}
