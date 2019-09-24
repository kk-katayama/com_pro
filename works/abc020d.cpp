#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
template <typename X>
struct Number{
  X n;
  vector<bool> prime;
  
  Number(X _n)
  {
    n = _n;
    prime.assign(n+1,true);
  }
  
  //nの約数を全列挙
  vector<X> divisor()
  {
    vector<X> res(0);
    for(X i=1;i*i<=n;++i){
      if(n%i==0){
	res.push_back(i);
	if(i != n/i) res.push_back(n/i);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
  
  //nを素因数分解
  map<X,int> prime_factor()
  {
    int nn = n;
    map<X,int> res;
    for(X i=2;i*i<=nn;++i){
      while(nn%i==0){
	res[i]++;
	nn /= i;
      }
    }
    if(nn!=1) res[nn] = 1;
    return res;
  }

  //n以下の素数を全列挙
  vector<X> sieve()
  {
    vector<X> res(0);
    if(n<=1) return res;
    prime[0] = prime[1] = false;
    for(X i = 2;i<=n;++i){
      if(prime[i]){
	res.push_back(i);
	X b = i*2;
	while(b<=n){
	  prime[b] = false;
	  b += i;
	}
      }
    }
    return res;
  }
  
};


int main()
{
  ll n,k;
  cin >> n >> k;
  
  Number<ll> nb(k);
  vector<ll> div = nb.divisor();
  int dl = div.size();
  
  //  map<ll,int> mp;
  //  rep(i,dl) mp[div[i]] = i;
  
  vector<mint> ikarr(dl);
  rep(i,dl) ikarr[i] = (mint)1/div[i];
  rep(i,dl) rep(j,dl){
    if(i>=j) continue;
    if(div[j]%div[i]==0) ikarr[j] -= ikarr[i];
  }

  mint res;
  rep(i,dl){
    mint ii(div[i]),nn(n/div[i]);
    res += ii*nn*(nn+1)*ikarr[i]/2;
  }
  res *= (mint)k;
  
  cout << res.x << "\n";
  
  return 0;
}
