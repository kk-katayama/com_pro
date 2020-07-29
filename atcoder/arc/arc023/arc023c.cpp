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

mint Comb(int n,int k){
  mint res(1);
  rep1(i,k){
    res *= (mint)(n-i+1)/(mint)i;
  }
  return res;
}

int main()
{
  int n; cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int cnt = 0;
  int buf;
  mint res(1);
  rep(i,n) {
    if(a[i] == -1) cnt++;
    else {
      if(i == 0) buf = a[i];
      else {
	if(a[i-1] == -1) {
	  res *= Comb(a[i] - buf + cnt, cnt);
	  cnt = 0;
	  buf = a[i];
	}
	buf = a[i];
      }
    }
  }
  cout << res.x << "\n";
  return 0;
}
