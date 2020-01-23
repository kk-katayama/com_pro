#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
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
const int NMAX=200010;
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


struct RLE{
  string array;
  int n;

  RLE(string _array){
    array = _array;
    n = array.size();
  }

  vector<int> compress(){
    vector<int> res(0);
    int cnt = 1;
    rep(i,n-1){
      if(array[i]==array[i+1]){
	cnt++;
      }
      else{
	res.push_back(cnt);
	cnt = 1;
      }
    }
    res.push_back(cnt);
    return res;
  }
  
};

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;

  Make_Fact();
  Make_InvFact();
  vector<mint> cat(n+1);

  cat[0] = 1;
  rep1(i,n) cat[i] = Comb(2*i,i) - Comb(2*i,i-1);


  RLE rle(s);
  vector<int> v = rle.compress();
  mint res(1);
  rep(i,v.size()) res *= cat[v[i]];

  cout << res.x << "\n";
  
  return 0;
}
