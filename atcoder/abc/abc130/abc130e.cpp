#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
const ll MOD=1e+9+7;
struct mint{
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator-=(const mint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator*=(const mint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  mint operator+(const mint a) const{
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const{
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const{
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const{
    if(!t) return 1;
    mint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  mint inv() const{
    return pow(MOD-2);
  }
  mint& operator/=(const mint a){
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const{
    mint res(*this);
    return res/=a;
  }
};


int main()
{
  int n,m; cin >> n >> m;
  vector<int> s(n),t(m);
  rep(i,n) cin >> s[i];
  rep(i,m) cin >> t[i];

  vector<vector<mint>> dp(n+1, vector<mint>(m+1));
  vector<vector<mint>> sum(n+1, vector<mint>(m+1));  
  rep(i,n) {
    rep(j,m) {
      if(s[i] == t[j]) {
	dp[i+1][j+1] = sum[i][j] + (mint)1;
      }
      sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + dp[i+1][j+1];
    }
  }
  mint res(1);
  rep(i,n+1) {
    rep(j,m+1) {
      res += dp[i][j];
    }
  }
  cout << res.x << "\n";
  
  return 0;
}
