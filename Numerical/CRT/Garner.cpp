#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// 拡張ユークリッドの互除法
// ap + bq = gcd(a, b) となる (p, q) を求める.
// 返り値はgcd(a, b)
ll ExtGcd(ll a, ll b, ll &p, ll &q) {
  if (b == 0) {
    p = 1; q = 0;
    return a;
  }
  ll d = ExtGcd(b, a%b, q, p);
  q -= a/b * p;
  return d;
}

// modが合成数の場合のmodの逆元
// modが合成数のときはFermatの小定理を用いた逆元計算ができない
// aの法modにおける逆元は、aとmodが互いに素であれば
// 拡張ユークリッドの互除法を用いることで行うことができる
ll ModInv(ll a, ll mod) {
  ll x,y;
  ll d = ExtGcd(a, mod, x, y);
  if(d != 1) {
    return -1;
  }
  x = ( (x%mod) + mod ) % mod;
  return x;
}

ll Gernar(vector<ll> r, vector<ll> m, ll mod) {
  int n = r.size();
  ll mprod = 1; // mprodにはm[i]の積を入れていく
  ll x = r[0]%m[0];
  rep1(i,n-1) {
    mprod *= m[i-1];
    ll t = ((r[i] - x) * ModInv(mprod, m[i])) % m[i];
    if(t < 0) t += m[i];
    x += t * mprod;
  }
  return x;
}

int main()
{
  vi a(31);
  vl r,m;
  set<int> use = {7,11,13,16,17,19,23,25,27,29};
  for(int i = 2; i <= 30; ++i) {
    cin >> a[i];
    if(use.find(i-1) != use.end()) {
      r.push_back(a[i]);
      m.push_back(i-1);
    }
  }

  ll res = Gernar(r,m,0);

  auto digitsum = [](ll a, ll b) ->ll{
		    ll ans = 0;
		    while(a > 0) {
		      ans += a%b;
		      a /= b;
		    }
		    return ans;
		  };

  if(1000000000000 < res) {
    cout << "invalid" << "\n";
    return 0;
  }
  
  for(int i = 2; i <= 30; ++i) {
    if(a[i] != digitsum(res, i)) {
      cout << "invalid" << "\n";
      return 0;
    }
  }

  cout << res << "\n";
  
  return 0;
}
