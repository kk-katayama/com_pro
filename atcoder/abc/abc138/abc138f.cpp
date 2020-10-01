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
#define sz(v) (int)v.size()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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
using mint = modint<1000000007>;

int main()
{
  ll l,r; cin >> l >> r;
  vi rv, lv;
  while(r > 0) {
    rv.push_back(r % 2);
    r /= 2;
  }
  while(l > 0) {
    lv.push_back(l % 2);
    l /= 2;
  }

  int n = max(sz(rv), sz(lv));
  rv.resize(n, 0);
  lv.resize(n, 0);  

  reverse(rv.begin(), rv.end());
  reverse(lv.begin(), lv.end());

  mint res;
  bool f = false;
  rep(i,n) {
    vector<vector<mint>> dp(2, vector<mint>(2));
    int rf = 0, lf = 0;
    if(f) break;
    if(lv[i] == 1) f = true;
    else lf = 1;
    if(i != 0) rf = 1;
    dp[rf][lf].x = 1;
    rep1(j,n-i-1) {
      vector<vector<mint>> dp2(2, vector<mint>(2));      
      int k = i + j;
      // 11
      dp2[1][1] += dp[1][1] * mint(3);
      // 10
      if(lv[k] == 0) {
	dp2[1][1] += dp[1][0];
	dp2[1][0] += dp[1][0] * mint(2);
      }
      else {
	dp2[1][0] += dp[1][0];
      }
      // 01
      if(rv[k] == 1) {
	dp2[1][1] += dp[0][1];
	dp2[0][1] += dp[0][1] * mint(2);
      }
      else {
	dp2[0][1] += dp[0][1];
      }
      // 00
      if(rv[k] == 0 && lv[k] == 1) {
	//
      }
      else {
	dp2[0][0] += dp[0][0];
	if(rv[k] == 1 && lv[k] == 0) {
	  dp2[0][1] += dp[0][0];
	  dp2[1][0] += dp[0][0];
	}
      }
      swap(dp, dp2);
    }
    res += dp[0][0] + dp[0][1] + dp[1][0] + dp[1][1];
  }
  cout << res.x << "\n";
  return 0;
}
