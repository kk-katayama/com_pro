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

const int NMAX=100010; // we can calculate nCk until n is equal to NMAX
mint fact[NMAX],infac[NMAX];
void Make_Fact(){
  fact[0]=fact[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    fact[i]=fact[i-1]*(mint)i;
  }
}
void Make_InvFact(){
  infac[0]=infac[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    infac[i]=infac[i-1]/(mint)i;	
  }
}
mint Comb(int n,int k){
  if(n<0||k<0||n-k<0) return 0;
  return fact[n]*infac[k]*infac[n-k];
}



int main()
{
  Make_Fact();
  Make_InvFact();
  int n,m,l; cin >> n >> m >> l;
  mint inv2 = mint(2).inv();

  using vm = vector<mint>;
  using vvm = vector<vm>;
  vvm dp(n+1, vm(m+1));
  dp[n][m].x = 1;
  for (int i = n; i >= 0; --i) {
    for (int j = m; j >= 0; --j) {
      rep1(k,l) {
	if(k == 1) {
	  if(i - k >= 0) dp[i-k][j] += dp[i][j];
	  continue;
	}
	if(i - k >= 0 && j - k >= 0) {
	  if(k != 2) dp[i-k][j-k] += dp[i][j] * Comb(i - 1, k - 1) * fact[k-1] * inv2;
	  else dp[i-k][j-k] += dp[i][j] * Comb(i - 1, k - 1);
	}
	if(i - k >= 0 && j - k + 1>= 0) {
	  dp[i-k][j-k+1] += dp[i][j] * Comb(i - 1, k - 1) * fact[k] * inv2;
	}
      }
    }
  }

  vvm dp2(n+1, vm(m+1));
  dp2[n][m].x = 1;
  for (int i = n; i >= 0; --i) {
    for (int j = m; j >= 0; --j) {
      rep1(k,l-1) {
	if(k == 1) {
	  if(i - k >= 0) dp2[i-k][j] += dp2[i][j];
	  continue;
	}
	if(i - k >= 0 && j - k >= 0) {
	  if(k != 2) dp2[i-k][j-k] += dp2[i][j] * Comb(i - 1, k - 1) * fact[k-1] * inv2;
	  else dp2[i-k][j-k] += dp2[i][j] * Comb(i - 1, k - 1);
	}
	if(i - k >= 0 && j - k + 1>= 0) {
	  dp2[i-k][j-k+1] += dp2[i][j] * Comb(i - 1, k - 1) * fact[k] * inv2;
	}
      }
    }
  }  
  
  cout << (dp[0][0] - dp2[0][0]).x << "\n";
  
  return 0;
}
