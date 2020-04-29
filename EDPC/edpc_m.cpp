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
  int n,k;cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<vector<mint>> dp(n+1, vector<mint>(k+1));
  vector<vector<mint>> sum(2, vector<mint>(k+2));
  rep1(i,k+1) {
    sum[0][i].x = 1;
  }
  rep1(i,n) {
    rep(j,k+1) {
      dp[i][j] += sum[0][j+1] - sum[0][max(0, j - a[i-1])];
      sum[1][j+1] = sum[1][j] + dp[i][j];
    }
    sum[0] = sum[1];
    sum[1].assign(k+2, 0);
  }

  cout << dp[n][k].x << "\n";
  
  return 0;
}
