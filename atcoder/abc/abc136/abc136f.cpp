#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
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
template <class X>
class BIT{
  X bit[NMAX];
  int n;
public:
  BIT(int N);
  X sum(int i);
  void add(int i,X x);
};
template <class X>
BIT<X>::BIT(int N){
  n=N;
  for(int i=0;i<N;i++){
    bit[i]=0;
  }
}
template <class X>
X BIT<X>::sum(int i){//iまでの和=bit[0]+...+bit[i]
  X s=0;
  while(i>0){
    s+=bit[i];
    i-=i&(-i);//最後の1bitを引く(ex.0110なら0010を引く)
  }
  return s;
}
template <class X>
void BIT<X>::add(int i,X x){//bit[i]+=x
  while(i<=n){
    bit[i]+=x;
    i+=i&(-i);//最後の1bitを足す
  }
}
int nn;
pair<int,int> p[200010];
int a[200010],b[200010],c[200010],d[200010];
int main()
{
  cin >> nn;
  rep(i,nn) cin >> p[i].first >> p[i].second;
  {
    map<int,int> mp;
    rep(i,nn) mp[p[i].first] = 0;
    int j = 1;
    for(auto itr=mp.begin();itr!=mp.end();++itr){
      itr->second = j++;
    }
    rep(i,nn) p[i].first = mp[p[i].first];
  }
  {
    map<int,int> mp;
    rep(i,nn) mp[p[i].second] = 0;
    int j = 1;
    for(auto itr=mp.begin();itr!=mp.end();++itr){
      itr->second = j++;
    }
    rep(i,nn) p[i].second = mp[p[i].second];
  }
  sort(p,p+nn);
  {
    BIT<int> bit(nn+1); 
    rep(i,nn){
      int pf = p[i].first,ps = p[i].second;
      int bb = bit.sum(ps);
      int aa = i - bb;
      a[pf-1] = aa;
      b[pf-1] = bb;
      bit.add(ps,1);
    }
  }
  {
    BIT<int> bit(nn+1); 
    rep(i,nn){
      int pf = p[nn-1-i].first,ps = p[nn-1-i].second;
      int dd = bit.sum(ps);
      int cc = i - dd;
      c[pf-1] = cc;
      d[pf-1] = dd;
      bit.add(ps,1);
    }
  }
  
  mint res;
  rep(i,nn){
    ll aa = a[i],bb = b[i],cc = c[i],dd = d[i];
    mint two = 2;
    res += (two.pow(aa) - 1)*(two.pow(dd) - 1)*(two.pow(bb+cc));
    res += (two.pow(bb) - 1)*(two.pow(cc) - 1)*(two.pow(aa+dd));
    res -= (two.pow(aa) - 1)*(two.pow(bb) - 1)*(two.pow(cc) - 1)*(two.pow(dd) - 1);
    res += two.pow((ll)nn-1);
  }

  cout << res.x << "\n";
  
  return 0;
}
