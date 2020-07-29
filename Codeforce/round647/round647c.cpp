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
  int t; cin >> t;
  vector<ll> res;
  while(t-- > 0) {
    ll n; cin >> n;
    ll ans = 0;
    ll i = 1;
    while(n / i > 0) {
      ans += n / i;
      i *= 2;
    }
    res.push_back(ans);
  }
  for(auto val: res) cout << val << "\n";
  return 0;
}
