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
  ll n,k; cin >> n >> k;
  if(n * 2 < k) {
    cout << 0 << "\n";
    return 0;
  }
  if(k % 2 == 0) {
    ll x = (n - k/2) / k + 1;
    ll y = n / k;
    cout << x*x*x + y*y*y << "\n";
  }
  else {
    ll y = n / k;
    cout << y*y*y << "\n";
  }
  return 0;
}
