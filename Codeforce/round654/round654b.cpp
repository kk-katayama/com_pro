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
    ll n,r; cin >> n >> r;
    if(n > r) {
      res.push_back(r * (r + 1) / 2);
    }
    else {
      res.push_back(n * (n - 1) / 2 + 1);
    }
  }
  for(auto val: res) cout << val << "\n";
  return 0;
}
