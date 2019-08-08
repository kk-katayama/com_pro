#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
typedef long long ll;
const int VMAX=100010;
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

int n;
int x[100010],y[100010];
vector<int> edge[VMAX];
mint dp[100010][2];
bool f[100010];
void add_edge(int from,int to){
  edge[from].push_back(to);
  edge[to].push_back(from);
}
void dfs(int s){
  f[s] = true;
  int ss = edge[s].size();
  dp[s][0] = dp[s][1] = 1;
  rep(i,ss){
    int w = edge[s][i];
    if(f[w]) continue;
    dfs(w);
    dp[s][0] *= dp[w][0] + dp[w][1];
    dp[s][1] *= dp[w][0];
  }
}
int main()
{
  cin >> n;
  rep(i,n-1) cin >> x[i] >> y[i];

  rep(i,n-1) add_edge(--x[i],--y[i]);
  rep(i,n) f[i] = false;

  dfs(0);
  mint res = dp[0][0] + dp[0][1];
  cout << res.x << "\n";
  
  return 0;
}
