#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
typedef long double ld;
int main()
{
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  rep(i,n) {
    if(a[i] == 0) {
      cout << 0 << "\n";
      return 0;
    }
  }
  
  ll sum = 1;
  ld inf = 1000000000000000000;
  rep(i,n) {
    if((ld)sum * (ld)a[i] > inf) {
      cout << -1 << "\n";
      return 0;
    }
    sum *= a[i];
  }
  cout << sum << "\n";
  
  return 0;
}
