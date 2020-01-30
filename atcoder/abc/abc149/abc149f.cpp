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
  int m;//number of edge
  int root;
  const int max_log_n = 20;//if n = 10^5, max_log_n = 20.
  bool flag;// if edge has cost, flag is true.
  vector<vector<int>> edge;// edge does not have cost.
  vector<vector<int>> par;//par[v][i] := vertex followed parent at 2^i times from vertex v.
  vector<int> depth;//depth of the node
  vector<int> size;
  
  vector<vector<pair<int,int>>> edge2;// edge has cost.
  
  void dfs(int v,int p,int d){//v...current vertex, p...parent of v, d...depth of v
    par[v][0] = p;
    depth[v] = d;
    for(auto w:edge[v]){
      if(w==p){
	continue;
      }
      dfs(w,v,d+1);
    }
  }

  int dfs_size(int v,int p){
    int res=1;
    for(auto w:edge[v]){
      if(w==p){
	continue;
      }
      res += dfs_size(w,v);
    }
    return size[v] = res;
  }

  
  void fill_table(){// fill parent table
    rep(i,max_log_n-1){
      rep(j,n){
	if(par[j][i] == -1){
	  par[j][i+1] = -1;
	}
	else{
	  par[j][i+1] = par[par[j][i]][i];
	}
      }
    }
  }
  
public:
  //*****Constructor************
  Tree(int n_){
    n = n_;
    edge.resize(n);
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b){
    flag = false;
    n = n_;
    m = m_;
    edge.resize(n);
    rep(i,m){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]);
    }
  }

  Tree(int n_,int m_,vector<int> a,vector<int> b,vector<int> c){
    flag = true;
    n = n_;
    m = m_;
    edge2.resize(n);
    rep(i,m){
      edge2[a[i]].push_back(make_pair(b[i],c[i]));
      edge2[b[i]].push_back(make_pair(a[i],c[i]));
    }
  }  
  //***************************

  
  void init(){//initialize parent table and vector of depth
    root = 0;
    par.resize(n,vector<int>(max_log_n));
    depth.resize(n);
    dfs(root,-1,0);
    size.resize(n);
    dfs_size(root,-1);
    fill_table();
  }

  int lca(int u,int v){//Lowest Common Ancestor of u and v
    if(depth[u]>depth[v]) swap(u,v);
    for(int i=max_log_n-1;i>=0;--i){
      if( ((depth[v]-depth[u])>>i)&1 ){
	v = par[v][i];
      }
    }
    if(u==v){
      return u;
    }

    for(int i=max_log_n-1;i>=0;--i){
      if(par[u][i]!=par[v][i]){
	u = par[u][i];
	v = par[v][i];
      }
    }
    return par[u][0];
  }

  int distance(int u,int v){//shortest distance of u and v
    int w = lca(u,v);
    return depth[u]+depth[v]-depth[w]*2;
  }

  vector<int> get_pass(int u,int v){
    int w = lca(u,v);
    vector<int> res;
    int x = depth[u]-depth[w];
    int y = depth[v]-depth[w];
    rep(i,x){
      res.push_back(u);
      u = par[u][0];
    }
    res.push_back(w);
    vector<int> rev;
    rep(i,y){
      rev.push_back(v);
      v = par[v][0];
    }
    for(int i=rev.size()-1;i>=0;--i){
      res.push_back(rev[i]);
    }
    return res;
  }

  void solve(){
    vector<mint> pow2(n+1);
    pow2[0].x = 1;
    rep(i,n){
      pow2[i+1] = pow2[i]*(mint)2;
    }
    mint res(0);
    rep(i,n){
      res += pow2[n];
      res -= pow2[n-1];
      res -= (mint)1;
      int ss=0;
      for(auto w:edge[i]){
	if(w==par[i][0]) continue;
	ss += size[w];
	res -= pow2[size[w]]-(mint)1;
      }
      res -= pow2[n-ss-1]-(mint)1;
    }
    res /= pow2[n];
    cout << res.x << "\n";
  }

  
  //*********debag_function**************
  void show_depth(){
    rep(i,n){
      cout << i << ":" << depth[i] << "\n";
    }
  }

  void show_parent(){
    rep(i,n){
      cout << i << ":" << par[i][0] << "\n";
    }
  }

  void show_size(){
    rep(i,n){
      cout << i << ":" << size[i] << "\n";
    }
  }
  
  void show_pass(int u,int v){
    vector<int> pass = get_pass(u,v);
    rep(i,pass.size()){
      cout << pass[i] << "\n";
    }
  }
  
  //***************************************  
};


int main()
{
  int n;
  cin >> n;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  Tree tr(n,n-1,a,b);
  tr.init();
  //  tr.show_size();
  tr.solve();
  return 0;
}
