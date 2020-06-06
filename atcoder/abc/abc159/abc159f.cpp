#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
const ll MOD=998244353;
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
  int n,s; cin >> n >> s;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  
  vector<vector<vector<mint>>> dp(n+1, vector<vector<mint>>(s+1, vector<mint>(3)));
  dp[0][0][0].x = 1;
  rep(i,n) {
    rep(j,s+1) {
      rep(k,3) {
	for (int l = 2; l >= k; --l) {
	  dp[i+1][j][l] += dp[i][j][k]; // not add
	  if(k == 0 && l == 0) continue;
	  if(k == 2 && l == 2) continue;
	  if(j + a[i] <= s) dp[i+1][j + a[i]][l] += dp[i][j][k];
	}
      }
    }
  }

  cout << dp[n][s][2].x << "\n";
  
  return 0;
}
