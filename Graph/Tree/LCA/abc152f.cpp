#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#include <bitset>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
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
  map<pair<int,int>,int> mp;
  rep(i,n-1){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    mp[make_pair(a[i],b[i])] = i;
    mp[make_pair(b[i],a[i])] = i;    
  }
  int m;
  cin >> m;
  vector<int> u(m),v(m);
  rep(i,m){
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }
  
  vector<ll> set(m,0);
  Tree tr(n,n-1,a,b);
  tr.init();
  rep(i,m){
    // cout << "******************" << "\n";
    // tr.show_pass(u[i],v[i]);
    vector<int> pass = tr.get_pass(u[i],v[i]);
    rep(j,pass.size()-1){
      int s = mp[make_pair(pass[j],pass[j+1])];
      set[i] |= 1ll<<s;
    }
    //    cout << bitset<50>(set[i]) << "\n";
  }

  ll res=0;
  rep1(S,(1<<m)-1){
    ll sub = 0;
    rep(i,m){
      if((S>>i)&1){
	sub |= set[i];
      }
    }
    int st = __builtin_popcount(S);
    int cnt = __builtin_popcountll(sub);
    //    cout << bitset<20>(S) << ":" << bitset<50>(sub) << "\n";
    if(st%2==1){
      res += 1ll<<(n-1-cnt);
    }
    else{
      res -= 1ll<<(n-1-cnt);
    }    
  }

  // cout << pow2[n-1] << ":" << res << "\n";
  res = (1ll<<(n-1))-res;
  cout << res << "\n";

  //  cout << pow2[n-1] << "\n";
  return 0;
}
