#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
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

int h,w;
int a[1100][1100];
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
mint dp[1100][1100];

mint dfs(int x,int y){
  if(dp[x][y].x>0) return dp[x][y];
  mint res(1);
  rep(i,4){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx>=0&&nx<h&&ny>=0&&ny<w){
      if(a[x][y]>a[nx][ny]) res += dfs(nx,ny);
    }
  }
  return dp[x][y] = res;
}

int main()
{
  cin >> h >> w;
  rep(i,h) rep(j,w) cin >> a[i][j];
  mint res;
  rep(i,h) rep(j,w){
    res += dfs(i,j);
  }
  cout << res.x << "\n";
  return 0;
}
