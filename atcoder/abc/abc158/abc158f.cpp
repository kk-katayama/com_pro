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
int n;
pair<int,int> p[110000];
int cntltk(int k){
  int lb=-1,ub=n;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(p[mid].first<k) lb=mid;
    else ub=mid;
  }
  return lb+1;
}
int cntltk2(int k){
  int lb=-1,ub=n;
  while(ub-lb>1){
    int mid=(lb+ub)/2;
    if(p[mid].first<=k) lb=mid;
    else ub=mid;
  }
  return lb+1;
}



int main()
{
  cin >> n;
  rep(i,n){
    int x,d;cin >> x >> d;
    p[i] = {x,d};
  }
  sort(p,p+n);
  mint two(2);
  mint res = two.pow(n);
  rep(i,n){
    int x = cntltk(p[i].first+p[i].second) - cntltk2(p[i].first);
    res -= two.pow(x)-(mint)1;
  }
  cout << res.x << "\n";
  
  return 0;
}
