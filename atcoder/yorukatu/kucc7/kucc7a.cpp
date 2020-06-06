#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n, k; cin >> n >> k;

  ll res = 0;
  if(k == 0) res = n*n;
  else {
    for(ll b = k+1; b <= n; ++b) {
      res += (n+1)/b * (b - k);
      res += max(0LL, (n+1)%b - k);
    }
  }
  cout << res << "\n";
  return 0;
}
