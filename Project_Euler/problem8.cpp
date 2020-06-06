#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  vector<ll> v(1000);
  rep(i,1000) {
    char c; cin >> c;
    v[i] = c - '0';
  }
  ll i = 0;
  ll res = 0;
  while(i + 12 < 1000) {
    ll tmp = 1;
    rep(j,13) {
      tmp *= v[i+j];
    }
    chmax(res, tmp);
    i++;
  }
  cout << res << "\n";
  return 0;
}
