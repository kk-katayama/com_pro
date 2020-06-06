#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
  int n,k; cin >> n >> k;

  vector<int> cost;
  
  for (int i = 1; i <= n; ++i) {
    int x = n/i - n/(i+1);
    if(x == 0) {
      rep(j,n/i) cost.push_back(1);
      break;
    }
    else {
      cost.push_back(x);
    }
  }

  reverse(cost.begin(), cost.end());
  int m = cost.size();
  
  vector<vector<mint>> dp(k+1, vector<mint>(m));
  vector<vector<mint>> sum(2, vector<mint>(m+1));
  dp[0][0].x = 1;
  rep(i,m) sum[0][i+1] = sum[0][i] + dp[0][i];

  rep(i,k) {
    rep(j,m) {
      dp[i+1][j] = sum[0][m-j]*(mint)cost[j];
      sum[1][j+1] = sum[1][j] + dp[i+1][j];
    }
    sum[0] = sum[1];
  }
  
  mint res;
  rep(i,m) res += dp[k][i];
  cout << res.x << "\n";
  
  return 0;
}
