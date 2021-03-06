#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n; cin >> n;
  vector<ll> f(n+1, 1);
  for (ll i = 2; i <= n; ++i) {
    ll x = i;
    while(x <= n) {
      f[x]++;
      x += i;
    }
  }
  ll res = 0;
  for (ll i = 1; i <= n; ++i) {
    res += i * f[i];
  }
  cout << res << "\n";
  
  return 0;
}
