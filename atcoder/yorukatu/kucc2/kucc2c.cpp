#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;

int main()
{
  ll n;cin >> n;
  ll c;cin >> c;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i]--;
  }

  vector<ll> place(c, 0);
  vector<ll> res(c, n*(n+1)/2);
  rep(i,n) {
    ll d = i - place[a[i]];
    res[a[i]] -= d * (d + 1) / 2;
    place[a[i]] = i+1;
  }
  rep(i,c) {
    ll d = n - place[i];
    res[i] -= d * (d + 1) / 2;
  }
  rep(i,c) cout << res[i] << "\n";
  
  return 0;
}
