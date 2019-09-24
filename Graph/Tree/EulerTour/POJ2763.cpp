#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<typename T>
struct Tree
{
  int node;
  vector<vector<pair<int,T>>> edge;
  vector<vector<int>> par;
  vector<int> depth;
  vector<bool> flag;
  vector<int> euler;
  vector<int> id;
  int k;
  vector<T> eul_cost;
  
  
  Tree(int _node){
    node = _node;
    edge.resize(node);
    rep(i,node) edge[i].resize(0);
    par.resize(node);
    rep(i,node) par[i].resize(20);    
    depth.resize(node);
    flag.assign(node,0);
    euler.resize(0);
    eul_cost.resize(0);    
    id.resize(node);
    k = 0;

  }
  
  void add(int from,int to,T cost){
    edge[from].push_back(make_pair(to,cost));
  }

  void make_tree(int v,int p,int d){
    par[v][0] = p;
    depth[v] = d;
    flag[v] = true;
    euler.push_back(v);
    id[v] = k++;
    for(auto &w:edge[v]){
      if(flag[w.first]) continue;
      eul_cost.push_back(w.second);
      make_tree(w.first,v,d+1);
      eul_cost.push_back(w.second);      
      euler.push_back(v);
      k++;
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

template <typename X>
struct BIT
{
  vector<X> dat;
  int n;

  BIT(int _n){
    n = _n+1;
    dat.assign(n,0);
  }
  
  X sum(int i)
  {
    X s = 0;
    while(i > 0){
      s += dat[i];
      i -= i&(-i);
    }
    return s;
  }

  void add(int i,X x)
  {
    while(i<=n){
      dat[i] += x;
      i += i&(-i);
    }
  }
};

int main()
{
  int n;
  cin >> n;
  vector<int> a(n-1),b(n-1),c(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i] >> c[i];
    --a[i];
    --b[i];
  }

  Tree<int> tr(n);
  rep(i,n-1){
    tr.add(a[i],b[i],c[i]);
    tr.add(b[i],a[i],c[i]);    
  }
  
  tr.make_tree(a[0],-1,0);

  for(auto &i:tr.eul_cost){
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}
