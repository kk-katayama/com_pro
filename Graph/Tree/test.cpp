#include <iostream>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Tree{
private:
  int n;//number of node
  int m;//number of edge
  int root;
  const int max_log_n = 20;//if n = 10^5, max_log_n = 20.
  vector<vector<int>> edge;
  vector<vector<int>> par;//par[v][i] := vertex followed parent at 2^i times from vertex v.
  vector<int> depth;//depth of the node
  
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
    n = n_;
    m = m_;
    edge.resize(n);
    rep(i,m){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]);
    }
  }
  //***************************

  
  void init(){//initialize parent table and vector of depth
    root = 0;
    par.resize(n,vector<int>(max_log_n));
    depth.resize(n);
    dfs(root,-1,0);
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

  void show_pass(int u,int v){
    int w = lca(u,v);
    vector<int> res;
    rep(i,depth[u]-depth[w]){
      res.push_back(u);
      u = par[u][0];
    }
    res.push_back(w);
    vector<int> rev;
    rep(i,depth[v]-depth[w]){
      rev.push_back(v);
      v = par[v][0];
    }
    for(int i=rev.size()-1;i>=0;--i){
      res.push_back(rev[i]);
    }
    rep(i,res.size()){
      cout << res[i] << "\n";
    }
  }
  
  //***************************************  
};


int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  int u,v;
  cin >> u >> v;
  u--;
  v--;
  
  Tree tr(n,m,a,b);
  tr.init();
  //  tr.show_depth();
  
  cout << tr.lca(u,v) << "\n";

  
  return 0;
}
