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
  int m; cin >> m;
  vector<ll> d(m), c(m);
  rep(i,m) cin >> d[i] >> c[i];

  ll res = 0;
  ll sum = 0;
  rep(i,m) {
    res += c[i];
    sum += d[i] * c[i];
  }

  res--;
  while(sum / 10 > 0) {
    res += sum / 10;
    ll tmp = 0;
    while(sum > 0) {
      tmp += sum % 10;
      sum /= 10;
    }
    sum = tmp;
  }
  cout << res << "\n";
  
  
  return 0;
}
