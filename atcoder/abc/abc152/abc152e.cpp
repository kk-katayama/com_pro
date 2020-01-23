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

ll gcd(ll a,ll b){
  if(b==0) return a;
  return gcd(b,a%b);
}

ll lcm(ll a,ll b){
  return a*b/gcd(a,b);
}

template <typename X>
struct Number{
  X n;
  vector<bool> prime;
  
  Number(X _n)
  {
    n = _n;
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
    prime.assign(n+1,true);
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
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }

  map<ll,int> mp;
  rep(i,n){
    Number<ll> nb(a[i]);
    map<ll,int> pf = nb.prime_factor();
    for(auto it=pf.begin();it!=pf.end();++it){
      if(mp[it->first]<=it->second){
	mp[it->first] = it->second;
      }
    }
  }

  mint g(1);
  for(auto it=mp.begin();it!=mp.end();++it){
    rep(i,it->second){
      g *= (mint)it->first;
    }	
  }
  
  mint res;
  rep(i,n){
    mint tmp = g;
    tmp /= (mint)a[i];
    res += tmp;
  }

  cout << res.x << "\n";
  
  return 0;
}
