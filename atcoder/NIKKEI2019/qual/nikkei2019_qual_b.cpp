#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD=998244353;
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
  int n;
  cin >> n;
  vector<ll> d(n);
  rep(i,n) cin >> d[i];

  if(d[0]!=0){
    cout << 0 << "\n";
    return 0;
  }
  sort(d.begin(), d.end());
  if(d[1]==0){
    cout << 0 << "\n";
    return 0;    
  }
  mint res(1);
  ll cnt1 = 1,cnt2 = 1;
  rep(i,n-1){
    if(d[i]!=d[i+1]){
      if(d[i]+1!=d[i+1]){
	cout << 0 << "\n";
	return 0;
      }
      mint kk(cnt1);
      res *= kk.pow(cnt2);
      
      cnt1 = cnt2;
      cnt2 = 1;
    }
    else{
      cnt2++;
    }
  }

  mint kk(cnt1);

  res *= kk.pow(cnt2);
  cout << res.x << "\n";

  return 0;
}
