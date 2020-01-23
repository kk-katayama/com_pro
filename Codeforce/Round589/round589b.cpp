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

int main()
{
  int h,w;
  cin >> h >> w;
  vector<int> r(h),c(w);
  rep(i,h) {
    cin >> r[i];
  }
  rep(i,w) {
    cin >> c[i];
  }
  bool f = true;
  vector<mint> pow2(h*w+1);
  pow2[0] = 1;
  rep1(i,h*w){
    pow2[i] = (mint)2*pow2[i-1];
  }
  int cnt = 0;
  rep(i,h){
    rep(j,w){
      if(j>r[i]&&i>c[j]) cnt++;
      else if((j<r[i]&&i==c[j])||(j==r[i]&&i<c[j])){
	f = false;
	break;
      }
    }
  }
  if(f) cout << pow2[cnt].x << "\n";
  else cout << 0 << "\n";
  return 0;
}
