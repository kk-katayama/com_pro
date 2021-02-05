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
using mint = modint<1000000007>;

int main()
{
  int h,w; cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  vector<vector<mint>> dp(h, vector<mint>(w));
  vector<vector<mint>> yoko(h, vector<mint>(w));
  vector<vector<mint>> tate(h, vector<mint>(w));  
  vector<vector<mint>> nana(h, vector<mint>(w));  
  dp[0][0].x = 1;
  yoko[0][0].x = 1;
  tate[0][0].x = 1;  
  nana[0][0].x = 1;
  rep(i,h) {
    rep(j,w) {
      if(s[i][j] == '.') {
	if(i-1 >= 0) {
	  dp[i][j] += tate[i-1][j];
	}	
	if(j-1 >= 0) {
	  dp[i][j] += yoko[i][j-1];
	}
	if(j-1 >= 0 && i-1 >= 0) {
	  dp[i][j] += nana[i-1][j-1];
	}
	if(i-1 >= 0) {
	  tate[i][j] = tate[i-1][j] + dp[i][j];
	}
	else {
	  tate[i][j] = dp[i][j];	  
	}	
	if(j-1 >= 0) {
	  yoko[i][j] = yoko[i][j-1] + dp[i][j];
	}
	else {
	  yoko[i][j] = dp[i][j];	  
	}
	if(j-1 >= 0 && i-1 >= 0) {
	  nana[i][j] = nana[i-1][j-1] + dp[i][j];
	}
	else {
	  nana[i][j] = dp[i][j];
	}
      }
    }
  }

  cout << dp[h-1][w-1].x << "\n";
  
  return 0;
}
