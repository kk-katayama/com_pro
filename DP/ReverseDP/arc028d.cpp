#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
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
  int n,m,q; cin >> n >> m >> q;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> k(q),x(q);
  rep(i,q) {
    cin >> k[i] >> x[i]; k[i]--;
  }

  vector<vector<mint>> dp(n+1, vector<mint>(m+1));
  dp[0][0].x = 1;
  rep(i,n) {
    rep(j,m+1) {
      dp[i+1][j] = dp[i][j]
	+ (j - 1 >= 0 ? dp[i+1][j-1] : 0)
	- (j - 1 - a[i] >= 0 ? dp[i][j-1-a[i]] : 0);
    }
  }

  vector<vector<mint>> dp2(n, vector<mint>(m+1));
  rep(i,n) {
    rep(j,m+1) {
      dp2[i][j] = dp[n][j]
	- (j - 1 >= 0 ? dp[n][j-1] : 0)
	+ (j - 1 - a[i] >= 0 ? dp2[i][j-1-a[i]] : 0);
    }
  }

  rep(i,q) {
    cout << dp2[k[i]][m - x[i]].x << "\n";
  }
  
  return 0;
}
