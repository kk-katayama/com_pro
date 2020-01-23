#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Tree
{
  int node;
  vector<vector<int>> edge;
  vector<vector<int>> par;
  vector<int> depth;
  vector<bool> flag;
  
  Tree(int _node){
    node = _node;
    edge.resize(node);
    rep(i,node) edge[i].resize(0);
    par.resize(node);
    rep(i,node) par[i].resize(20);    
    depth.resize(node);
    flag.assign(node,0);
  }
  
  void add(int from,int to){
    edge[from].push_back(to);
  }

  void make_tree(int v,int p,int d){    
    par[v][0] = p;
    depth[v] = d;
    flag[v] = true;
    for(auto &w:edge[v]){
      if(flag[w]) continue;
      make_tree(w,v,d+1);
    }
  }
  
  void fill_par()
  {
    rep(i,19){
      rep(j,node){
	if(par[j][i] == -1) par[j][i+1] = -1;
	else par[j][i+1] = par[par[j][i]][i];
      }
    }
  }

  int LCA(int u,int v){
    if(depth[v]>depth[u]) swap(u,v);

    for(int i=19;i>=0;--i){
      if(((depth[u]-depth[v])>>i)&1) u = par[u][i];
    }
    if(u==v) return u;

    int lb = 0;
    int ub = depth[u] + 1;
    while(ub - lb > 1){
      int mid = (lb + ub)/2;
      int uu = u;
      int vv = v;
      for(int i = 19;i>=0;--i){
	if((mid>>i)&1) uu = par[uu][i];
	if((mid>>i)&1) vv = par[vv][i];	
      }
      if(uu == vv) ub = mid;
      else lb = mid;
    }
    int res = u;
    for(int i = 19;i>=0;--i){
      if((ub>>i)&1) res = par[res][i];
    }
    return res;
  }

  int distance(int u,int v){
    int w = LCA(u,v);
    return depth[u]+depth[v]-2*depth[w];
  }
  
  void show_par(){
    rep(i,node){
      cout << i << " " << par[i][0] << "\n";
    }
  }
  void show_depth(){
    rep(i,node){
      cout << i << " " << depth[i] << "\n";
    }
  }  
};
int main()
{
  int n;
  cin >> n;
  Tree tr(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    tr.add(a,b);
    tr.add(b,a);
  }
  tr.make_tree(0,-1,0);
  tr.fill_par();
  /*
  rep(i,tr.node){
    cout << i << " " << tr.par[i][0] << "\n";
  }
  rep(i,tr.node){
    cout << i << " " << tr.depth[i] << "\n";
    }*/

  tr.show_par();
  tr.show_depth();
  int m;
  cin >> m;
  vector<int> u(m),v(m);
  rep(i,m){
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }
  
  rep(i,m){
    cout << tr.distance(u[i],v[i]) << "\n";
  }
  
  return 0;
}
