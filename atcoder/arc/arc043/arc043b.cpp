#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD=1e+9+7;
const int NMAX = 2e+5;
int n;
int d[NMAX];
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

bool C(int x,int comp){
  return d[x]<=comp;
}
int lower(int l,int r,int comp){//条件を満たす中で最大のものを返す
  int lb=l-1,ub=r+1;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(C(mid,comp)) lb=mid;
    else ub=mid;
  }
  return lb;
}



int main()
{
  cin >> n;
  rep(i,n){
    cin >> d[i];
  }
  sort(d,d+n);
  vector<vector<mint>> dp(n,vector<mint>(4));
  vector<vector<mint>> sum(n+1,vector<mint>(4));
  
  rep(i,n){
    dp[i][0].x = 1;
    int index = lower(0,n-1,d[i]/2);
    dp[i][1] = sum[index+1][0];
    dp[i][2] = sum[index+1][1];
    dp[i][3] = sum[index+1][2];
    rep(j,4){
      sum[i+1][j] = sum[i][j] + dp[i][j];
    }
  }

  // rep(i,n){
  //   rep(j,4){
  //     cout << i << ":" << j << ":" << dp[i][j].x << "\n";
  //   }
  // }
  mint res;
  rep(i,n){
    res += dp[i][3];
  }
  cout << res.x << "\n";
  return 0;
}
