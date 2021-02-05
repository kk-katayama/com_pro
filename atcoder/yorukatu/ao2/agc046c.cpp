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

int main()
{
  string s; cin >> s;
  int w; cin >> w;
  
  int n = sz(s);
  vi a;
  int cnt = 0;
  rep(i,n) {
    if(s[i] == '0') {
      a.push_back(cnt);
      cnt = 0;
    }
    else cnt++;
  }
  a.push_back(cnt);

  int m = sz(a);
  vi sum(m+1, 0);
  rep(i,m) sum[i+1] = sum[i] + a[i];

  int kmax = min(sum[m], w);
  
  vector<vector<mint>> dp1(sum[m]+1, vector<mint>(kmax+1));
  dp1[0][0].x = 1;
  rep(i,m) {
    vector<vector<mint>> dp2(sum[m]+1, vector<mint>(kmax+1));
    rep(j, sum[m]+1) {
      rep(k,kmax+1) {
	for(int x = max(0, sum[i+1] - j); x <= sum[m] - j; ++x) {
	  if(k+max(0, a[i] - x) > w) continue;
	  dp2[j+x][k+max(0, a[i]-x)] += dp1[j][k];
	}
      }
    }
    swap(dp2, dp1);
  }
  
  mint res;
  rep(i,kmax+1) {
    res += dp1[sum[m]][i];
  }
  cout << res.x << "\n";
  
  return 0;
}
