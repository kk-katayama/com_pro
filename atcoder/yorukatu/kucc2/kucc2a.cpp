#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  ll a;cin >> a;
  ll M = 1e+4;
  for (ll i = 10; i <= M; ++i) {
    ll x = 0;
    ll y = i;
    ll z = 1;
    while(y > 0) {
      x += (y % 10) * z;
      z *= i;
      y /= 10;
    }
    if(x == a) {
      cout << i << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  
  return 0;
}
