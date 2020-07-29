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
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll res = 0;
  rep(i,n) rep(j,n) rep(k,n) {
    chmax(res, (a[i] | a[j] | a[k]));
  }
  cout << res << "\n";
  
  return 0;
}
