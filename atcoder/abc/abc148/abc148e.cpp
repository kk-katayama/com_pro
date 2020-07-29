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
  ll n; cin >> n;
  if(n % 2 == 1) {
    cout << 0 << "\n";
    return 0;
  }
  ll res = 0;
  ll x = 10;
  while(1) {
    res += n / x;
    if(x > n/5) break;
    x *= 5;
  }
  cout << res << "\n";
  return 0;
}
