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
const int M = 110000;
mint perm[M];
void make_perm() {
  perm[0].x = 1;
  rep1(i, M-1) {
    perm[i] = (mint)i * perm[i-1];
  }
}

int main()
{
  int n;cin >> n;
  string s;cin >> s;
  mint res(1);
  if(s[0] == 'W') {
    cout << 0 << "\n";
    return 0;
  }
  int cnt = 1;
  for(int i = 1;i < 2*n;++i) {
    if(s[i] == 'W') {
      if(cnt % 2 == 0) {
	res *= (mint)cnt;
	cnt--;
	if(cnt < 0) {
	  cout << 0 << "\n";
	  return 0;
	}
      }
      else cnt++;
    }
    else {
      if(cnt % 2 == 0) cnt++;
      else {
	res *= (mint)cnt;
	cnt--;
	if(cnt < 0) {
	  cout << 0 << "\n";
	  return 0;
	}
      }
    }    
  }
  if(cnt != 0) {
    cout << 0 << "\n";
    return 0;
  }
  make_perm();
  res *= perm[n];
  cout << res.x << "\n";
  return 0;
}
