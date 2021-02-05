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
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// Modint
// modint<MOD> で宣言
template<ll MOD>
struct modint{
  ll x;
  ll mod = MOD;
  modint(ll x=0):x(x%MOD){}
  modint& operator+=(const modint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  modint& operator-=(const modint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  modint& operator*=(const modint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  modint operator+(const modint a) const{
    modint res(*this);
    return res+=a;
  }
  modint operator-(const modint a) const{
    modint res(*this);
    return res-=a;
  }
  modint operator*(const modint a) const{
    modint res(*this);
    return res*=a;
  }
  modint pow(ll t) const{
    if(!t) return 1;
    modint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  modint inv() const{
    return pow(MOD-2);
  }
  modint& operator/=(const modint a){
    return (*this) *= a.inv();
  }
  modint operator/(const modint a) const{
    modint res(*this);
    return res/=a;
  }
};
using mint = modint<998244353>;

// n を素因数分解する.返り値はmap.計算量はO(sqrt(n))
map<ll,int> primefactor(ll n){
  ll nn = n;
  map<ll,int> res;
  for(ll i=2;i*i<=nn;++i){
    while(nn%i==0){
      res[i]++;
      nn /= i;
    }
  }
  if(nn!=1) res[nn] = 1;
  return res;
}

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
  ll d; cin >> d;
  map<ll,map<ll,int>> pri;
  pri[d] = primefactor(d);
  map<ll,int> cnt;
  cnt[d] = pri[d].size();

  map<ll,mint> dp;
  int n; cin >> n;

  auto rec = [&](auto self, ll m)->mint{
    if(dp[m].x != 0) return dp[m];
    if(cnt[m] == 1) {
      return dp[m] = (mint)1;
    }
    mint res;
    for(auto tmp: pri[m]) {
      auto [key, val] = tmp;
      if(val == 0) continue;
      ll y = m / key;
      pri[y] = pri[m];
      pri[y][key]--;
      cnt[y] = cnt[m];
      if(val == 1) cnt[y]--;
      res += self(self, y);
      
    }
    return dp[m] = res;
  };

  dp[1].x = 1;
  rec(rec, d);
  
  while(n-- > 0) {
    ll a,b; scanf("%lld%lld", &a, &b);
    if(a < b) swap(a, b);
    ll g = gcd(a, b);
    mint res = dp[a/g] * dp[b/g];
    cout << res.x << "\n";
  }

  return 0;
}
