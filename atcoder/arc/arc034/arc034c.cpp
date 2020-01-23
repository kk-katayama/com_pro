#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
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

map<int,int> prime_factor(int n){
  map<int,int> res;
  for(int i=2;i*i<=n;++i){
    while(n%i==0){
      res[i]++;
      n /= i;
    }
  }
  if(n!=1){
    res[n] = 1;
  }
  return res;
}


int main()
{
  int a,b;
  cin >> a >> b;

  map<int,int> mp;
  for(int i=b+1;i<=a;++i){
    map<int,int> pf = prime_factor(i);
    for(auto it = pf.begin();it!=pf.end();++it){
      mp[it->first] += it->second;
    }
  }

  mint res(1);
  for(auto it=mp.begin();it!=mp.end();++it){
    //    cout << it->first << ":" << it->second << "\n";
    res *= (mint)(it->second + 1);
  }

  cout << res.x << "\n";
  
  return 0;
}
