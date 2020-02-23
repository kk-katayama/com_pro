#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD=10000;
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
  int n,k;
  cin >> n >> k;
  vector<int> c(n,0);
  rep(i,k){
    int a,b;
    cin >> a >> b;a--;
    c[a] = b;
  }

  mint dp[110][4][4];
  dp[0][0][0].x = 1;
  rep(i,n){
    rep(a,4){
      rep(b,4){
	if(c[i]==0){
	  rep1(j,3){
	    if(a==b&&a==j) continue;
	    dp[i+1][b][j] += dp[i][a][b];
	  }
	}
	else{
	  if(a==b&&a==c[i]) continue;
	  dp[i+1][b][c[i]] += dp[i][a][b];
	}
      }
    }
  }

  mint res;
  rep1(i,3) rep1(j,3) res += dp[n][i][j];
  cout << res.x << "\n";
  return 0;
}
