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
  int n, x; cin >> n >> x;
  vector<int> s(n);
  rep(i,n) cin >> s[i];

  sort(s.begin(), s.end(), [](int a, int b)-> bool{
			     return a > b;
			   });

  vector<mint> modinv(n+1);
  rep1(i,n) modinv[i] = (mint)1 / (mint)i;
  
  vector<vector<mint>> dp(n+1, vector<mint>(x+1));
  dp[0][x].x = 1;
  rep(i,n) {
    rep(j,x+1) {
      dp[i+1][j % s[i]] += dp[i][j];
      dp[i+1][j]        += dp[i][j] * (mint)(n - 1 - i);
    }
  }

  mint res;
  rep(j,x+1) res += dp[n][j]*(mint)j;
  //  rep1(i,n) res *= (mint)i;
  cout << res.x << "\n";
  
  
  return 0;
}
