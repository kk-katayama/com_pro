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
  ll res = n;
  rep(i,n-1) {
    ll u,v; cin >> u >> v;
    if(u > v) swap(u, v);
    res += (i + 1) * (n - i);
    res -= u * (n - v + 1);
  }
  cout << res << "\n";
  return 0;
}
