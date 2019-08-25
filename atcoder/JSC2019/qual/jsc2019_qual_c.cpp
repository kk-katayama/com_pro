#include <iostream>
#include <algorithm>
#include <string>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll n;
string s;
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
mint p[100010];
void make_p(){
  p[0].x=p[1].x=1;
  for(ll i=2;i<=n;++i){
    p[i] = p[i-1]*i;
  }
}
int main()
{
  
  cin >> n;
  cin >> s;

  make_p();
  ll ss = s.size();
  mint res;
  res.x=1;
  ll h=0;
  rep(i,ss){
    if(s[i]=='B'){
      if(h%2==1){
	res *= h;
	h -= 1;
      }
      else h++;
    }
    else{
      if(h%2==0){
	res *= h;
	h -= 1;
      }
      else h++;
    }
  }
  if(h!=0) cout << 0 << "\n";
  else{
    res *= p[n];
    cout << res.x << "\n";
  }
  return 0;
}
