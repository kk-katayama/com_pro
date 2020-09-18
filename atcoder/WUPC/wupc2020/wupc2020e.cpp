#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
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

const int NMAX=100010; // we can calculate nCk until n is equal to NMAX
mint fact[NMAX],infac[NMAX];
void Make_Fact(){
  fact[0]=fact[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    fact[i]=fact[i-1]*(mint)i;
  }
}
void Make_InvFact(){
  infac[0]=infac[1]=1;
  for(int i=2;i<=NMAX-1;++i){
    infac[i]=infac[i-1]/(mint)i;	
  }
}
mint Comb(int n,int k){
  if(n<0||k<0||n-k<0) return 0;
  return fact[n]*infac[k]*infac[n-k];
}

//return x's prime factor as map
map<ll,ll> primefactor(ll n){
  ll nn = n;
  map<ll,ll> res;
  for(ll i=2;i*i<=nn;++i){
    while(nn%i==0){
      res[i]++;
      nn /= i;
    }
  }
  if(nn!=1) res[nn] = 1;
  return res;
}


int main()
{
  ll n; cin >> n;
  map<ll,ll> pf = primefactor(n);
  ll cnt = 1;
  ll cntpf = 0;
  vector<ll> a;  
  for(auto val: pf) {
    cntpf++;
    //    cout << val.first << ":" << val.second << "\n";
    cnt *= (val.second + 1);
    a.push_back(val.second + 1);
  }


  
  Make_Fact();
  Make_InvFact();

  auto f = [&](ll x) {
	     mint ans;
	     rep1(i,x) {
	       ans += Comb(x, i) * fact[i];
	     }
	     return ans;
	   };
  mint yo;
  ll mask = (1 << cntpf) - 1;
  for(ll i=mask;i>0;i=(i-1)&mask){
    ll tmp = 1;
    ll c = 0;
    rep(j, cntpf) {
      if((i >> j) & 1) {
	tmp *= (a[j] - 1);
	c++;
      }
      else {
	tmp *= (a[j]);	
      }
    }
    if(c % 2 == 0) {
      yo += f(tmp);
    }
    else {
      yo -= f(tmp);
    }
  }



  yo += f(cnt);
  cout << yo.x << "\n";
  
  return 0;
}
