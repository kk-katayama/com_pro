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
vector<mint> Ikano_Array(int n){
  vector<mint> res(n+1);
  rep1(i,n) res[i] = (mint)1/i;
  
  rep1(i,n){
    for(int j=i*2;j<=n;j+=i){
      res[j] -= res[i];
    }
  }
  return res;
}
int main()
{
  int n;
  cin >> n;
  vector<mint> a(n);
  int mx = 0;
  rep(i,n){
    cin >> a[i].x;
    mx = max(mx,(int)a[i].x);
  }
  vector<mint> num(mx+1);
  rep(i,n) num[a[i].x].x++;
  
  vector<mint> c = Ikano_Array(mx);
  
  vector<mint> sum(mx+1),sumeq(mx+1);

  rep1(i,mx){
    for(int j=i;j<=mx;j+=i){
      mint jj(j);
      sum[i] += num[j]*jj;
      sumeq[i] += jj*jj*num[j];
    }
  }

  mint res(0);
  rep1(i,mx){
    sum[i] = (sum[i]*sum[i]-sumeq[i])/2;
    res += c[i] * sum[i];
  }

  cout << res.x << "\n";
  
  return 0;
}
