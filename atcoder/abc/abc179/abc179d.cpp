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

mint inv2;

// 区間加算クエリ
template <typename F,typename T>
struct DST{
  T identity;
  F merge;
  int size;
  vector<T> dat,delay;
  
  DST(F f,T id):merge(f),identity(id){}

  void eval(int k,int l,int r){
    if(delay[k].x != 0){
      dat[k] += delay[k];
      if(k<size-1){
	delay[2*k+1] += delay[k]*inv2;
	delay[2*k+2] += delay[k]*inv2;	
      }
      delay[k].x=0;
    }
  }

  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1,identity);
    delay.resize(size*2-1,0);    
  }

  void build(vector<T> vec){
    rep(i,vec.size()) dat[size-1+i] = vec[i];
    dfs(0);
  }

  T dfs(int k){
    if(k>=size-1) return dat[k];
    else return dat[k] = merge(dfs(2*k+1),dfs(2*k+2));
  }

  void update(int a,int b,T x,int k,int l,int r){
    eval(k,l,r);

    if(r<=a||b<=l) return ;
    if(a<=l&&r<=b){
      delay[k] += (mint)(r-l)*x;
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      dat[k] = merge(dat[2*k+1],dat[2*k+2]);
    }
  }

  T query(int a,int b,int k,int l,int r){
    eval(k,l,r);
    if(r<=a||b<=l) return identity;

    if(a<=l&&r<=b) return dat[k];
    else return merge(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
  }

  void all_eval(){
    rep(i,2*size-1){
      eval(i,0,0);
    }
  }

  T get(int k){ return dat[size-1+k];}
  
  void show(){
    int index = 0;
    int num = 1;
    while(index<size){
      rep(i,num){
	if(dat[i+index].x==identity.x) cout << "e ";
	else cout << dat[i+index].x << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
    index = 0;
    num = 1;
    while(index<size){
      rep(i,num){
	cout << delay[i+index].x << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
  }
  

  
};
int main()
{
  mint tw(2);
  inv2 = tw.inv();
  auto f = [&](mint a,mint b){ return a+b;};
  mint id(0);
  DST<decltype(f),mint> dst(f,id);

  int n,k; cin >> n >> k;
  vi l(k),r(k);
  rep(i,k) cin >> l[i] >> r[i];

  dst.init(n);
  dst.update(0,1,(mint)1,0,0,dst.size);
  rep(i,n) {
    rep(j,k) {
      int s = min(i + l[j], n);
      int t = min(i + r[j] + 1, n);
      mint x = dst.query(i, i+1, 0, 0, dst.size);
      dst.update(s, t, x, 0, 0, dst.size);
      //      dst.show();
    }
  }

  cout << dst.query(n-1,n,0,0,dst.size).x << "\n";
  
  return 0;
}
