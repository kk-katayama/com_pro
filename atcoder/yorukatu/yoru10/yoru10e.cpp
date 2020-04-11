#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
// ユークリッドの互除法で最大公約数を求める
ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}
// 最小公倍数
ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}

int main()
{
  ll n,m;cin >> n >> m;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll a0 = a[0];
  int cnts = 0;
  while(a0 % 2 == 0) {
    cnts++;
    a0 /= 2;
  }
  rep1(i,n-1) {
    ll ai = a[i];
    int cnt = 0;
    while(ai % 2 == 0) {
      cnt++;
      ai /= 2;
    }
    if(cnt != cnts) {
      cout << 0 << "\n";
      return 0;
    }
  }

  ll g = a[0] / 2;;

  rep1(i,n-1) {
    g = lcm(g, a[i]/2);
    if(g > m) {
      cout << 0 << "\n";
      return 0;
    }
  }
  
  ll res = ( m/g + 1 ) / 2;
  cout << res << "\n";
  
  
  return 0;
}
