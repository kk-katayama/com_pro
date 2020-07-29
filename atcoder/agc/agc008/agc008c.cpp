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
  vector<ll> a(7);
  rep(i,7) cin >> a[i];

  ll res = 0;
  res += a[1] * 2;
  if(a[0] == 0 || a[3] == 0 || a[4] == 0) {
    res += a[0] / 2 * 4;
    res += a[3] / 2 * 4;
    res += a[4] / 2 * 4;
  }
  else {
    ll cnt = (a[0] % 2) + (a[3] % 2) + (a[4] % 2);
    if(cnt == 0 || cnt == 1) {
      res += a[0] / 2 * 4;
      res += a[3] / 2 * 4;
      res += a[4] / 2 * 4;
    }
    else if(cnt == 2) {
      res += (a[0] - 1) / 2 * 4;
      res += (a[3] - 1) / 2 * 4;
      res += (a[4] - 1) / 2 * 4;
      res += 6;
    }
    else if(cnt == 3) {
      res += a[0] / 2 * 4;
      res += a[3] / 2 * 4;
      res += a[4] / 2 * 4;
      res += 6;
    }
  }
  cout << res/2 << "\n";
  
  return 0;
}
