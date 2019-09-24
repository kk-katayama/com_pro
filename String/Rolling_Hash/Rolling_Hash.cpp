#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll B = 1e+9+7;
const ll mod1 = 999999937;
const ll mod2 = 1000000007;
struct RollingHash{
  template <ll MOD>
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
  mint<mod1> B1;
  mint<mod2> B2;
  string s;
  ll sl;
  
  RollingHash(string _s){
    s = _s;
    sl = s.size();
    B1.x = 17;
    B2.x = 19;
  }
  
  int RollingHash_count(string t){
    ll tl = t.size();
    if(tl > sl) return 0;
    int res = 0;
    
    mint<mod1> sh1,th1,t1;
    mint<mod2> sh2,th2,t2;

    t1 = B1.pow(tl);
    t2 = B2.pow(tl);

    rep(i,tl) th1 = th1*B1 + t[i];
    rep(i,tl) th2 = th2*B2 + t[i];    

    rep(i,tl) sh1 = sh1*B1 + s[i];
    rep(i,tl) sh2 = sh2*B2 + s[i];

    for(int i=tl;i<=sl;++i){
      if(sh1.x==th1.x&&sh2.x==th2.x) res++;
      sh1 = sh1*B1 + s[i] - t1*s[i-tl];
      sh2 = sh2*B2 + s[i] - t2*s[i-tl];      
    }
    return res;
  }
};
int main()
{
  
  string s;
  cin >> s;
  int m;
  cin >> m;
  vector<string> t(m);
  rep(i,m) cin >> t[i];  

  int res = 0;
  RollingHash rh(s);
  rep(i,m){
    res += rh.RollingHash_count(t[i]);
    //    cout << rh.RollingHash_count(t[i]) << "\n";
  }
  
  cout << res << "\n";

  return 0;
}
