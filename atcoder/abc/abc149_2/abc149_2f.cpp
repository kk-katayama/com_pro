#include <iostream>
#include <algorithm>
#include <vector>
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


class Tree{
private:
  int n;//number of node
  int m;
  vector<vector<int>> edge;// edge does not have cost.
  vector<vector<pair<int,int>>> edge2;// edge has cost.

public:  
  //*****Constructor************
  Tree(int n_){
    n = n_;
    edge.resize(n);
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b){
    n = n_;
    m = m_;
    edge.resize(n);
    rep(i,m){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]);
    }
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b,vector<int> c){
    n = n_;
    m = m_;
    edge2.resize(n);
    rep(i,m){
      edge2[a[i]].push_back(make_pair(b[i],c[i]));
      edge2[b[i]].push_back(make_pair(a[i],c[i]));
    }
  }  
  //*******************************************

  vector<int> d;
  vector<int> par;
  int dfs(int v,int p){
    int res = 1;
    par[v] = p;
    for(auto w:edge[v]){
      if(w==p) continue;
      res += dfs(w,v);
    }
    return d[v] = res;
  }

  void init(){
    d.resize(n);
    par.resize(n);
    dfs(0,-1);
  }

  void solve(){
    rep(i,v){
      for(auto w:edge[v]){
	if(w==par[v]) continue;
	
      }
    }
  }
  
};

int main()
{
  int n;cin >> n;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
  }

  Tree tr(n,n-1,a,b);
  tr.init();

  pow2[0].x = 1;
  rep(i,n) pow2[i+1] = (mint)2*pow[i];
  
  
  
  
  return 0;
}
