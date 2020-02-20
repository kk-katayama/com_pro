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

const int NMAX = 110000;
int n;
vector<int> edge[NMAX];
mint dp[NMAX][2];
mint dfs(int v,int p,int c){
  if(dp[v][c].x>0) return dp[v][c];
  mint res(1);
  for(auto w:edge[v]){
    if(w==p) continue;
    if(c==0){
      res *= (dfs(w,v,0)+dfs(w,v,1));
    }
    else{
      res *= dfs(w,v,0);
    }
  }
  //  if(res.x==0) res.x=1;
  return dp[v][c] = res;
}
int main()
{
  cin >> n;
  rep(i,n-1){
    int a,b;
    cin >> a >> b;a--;b--;
    edge[a].push_back(b);
    edge[b].push_back(a);    
  }

  rep(i,NMAX) rep(j,2) dp[i][j].x = -1;
  
  
  mint res = dfs(0,-1,0)+dfs(0,-1,1);
  cout << res.x << "\n";

  // rep(i,n) {
  //   rep(j,2) cout << i << ":" << j << ":" << dp[i][j].x << " ";
  //   cout << "\n";
  // }
  return 0;
}
