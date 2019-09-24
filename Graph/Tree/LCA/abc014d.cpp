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
};

int main()
{
  int n;
  cin >> n;
  vector<int> x(n-1),y(n-1);
  rep(i,n-1){
    cin >> x[i] >> y[i];
    --x[i];
    --y[i];
  }
  int q;
  cin >> q;
  vector<int> a(q),b(q);
  rep(i,q){
    cin >> a[i] >> b[i];
    --a[i];
    --b[i];
  }

  Tree tr(n);
  rep(i,n-1){
    tr.add(x[i],y[i]);
    tr.add(y[i],x[i]);
  }

  tr.make_tree(x[0],-1,0);
  tr.fill_par();
  
  rep(i,q){
    int index = tr.LCA(a[i],b[i]);
    int res = tr.depth[a[i]] - tr.depth[index] + tr.depth[b[i]] - tr.depth[index] + 1;
   cout << res << "\n"; 
  }
  
  return 0;
}




