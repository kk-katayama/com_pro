#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
// ユークリッドの互除法で最大公約数を求める
ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

int main()
{
  int n; cin >> n;
  ll z; cin >> z;
  vector<ll> a(n);

  rep(i,n) cin >> a[i];

  ll res = 1;
  rep(i,n) {
    ll tmp = gcd(a[i], z);
    res = lcm(res, tmp);
  }
  cout << res << "\n";
  return 0;
}
