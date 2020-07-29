#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
const ll MOD = 998244353;
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
  int a,b,c,d; cin >> a >> b >> c >> d;

  int n = c - a, m = d - b;
  vector<vector<mint>> dp(n + 2, vector<mint>(m + 2));
  dp[0][0].x = 1;
  rep(i,n+1) {
    rep(j,m+1) {
      if(i > 0 && j > 0) {
	dp[i][j] -= dp[i-1][j-1] * (mint)((a + i - 1) * (b + j - 1));
      }
      dp[i+1][j] += dp[i][j] * (mint)(b + j);
      dp[i][j+1] += dp[i][j] * (mint)(a + i);
    }
  }
  cout << dp[n][m].x << "\n";
  
  return 0;
}
