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
  vector<ll> s(n);
  rep(i,n) cin >> s[i];

  vector<ll> a;
  rep(i,n) {
    int j = n - 1 - i;
    a.push_back(s[i] + s[j]);
  }    
  ll res = 0;
  rep1(i,n) {
    int idx = 0;
    ll sum = 0;
    int cr = n;
    if((n - 1) % i == 0) cr = n/2;
    while(idx < cr && i < n - idx - 1) {
      sum += a[idx];
      chmax(res, sum);
      idx += i;
    }
  }
  cout << res << "\n";
  return 0;
}
