#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct Graph{
  int node;
  vector<vector<pair<int,X>>> edge;
  vector<vector<int>> rev;  
  vector<X> d;//distance from start 
  const X inf = 1e+13;//initial value
  vector<bool> visit;//visited flag
  vector<bool> f;//Can node 's' visit 'g' ?
  
  Graph(int _n){
    node = _n;
    edge.resize(node);
    rev.resize(node);
  }
  
  void add_edge(int from,int to,X cost){
    edge[from].push_back(make_pair(to,cost));
  }
  
  void add_rev(int from,int to){
    rev[from].push_back(to);
  }

  void dfs(int v){
    visit[v] = true;
    f[v] = true;
    for(auto w:rev[v]){
      if(visit[w]){
	continue;
      }
      dfs(w);
    }
  }

  void run_dfs(int g){//check each node can reach goal
    visit.assign(node,false);
    f.assign(node,false);
    f[g] = true;
    dfs(g);
  }

  void check_f(){
    rep(i,node){
      cout << i << ":" << f[i] << "\n";
    }
  }
  
  bool bellmanford(int s){//if graph have negative-loop, return false
    d.assign(node,inf);
    d[s] = 0;
    bool flag = true;
    rep(i,node){
      rep(v,node){
	if(d[v]==inf) continue;
	for(auto w:edge[v]){
	  if(d[w.first]>d[v] + w.second){
	    d[w.first] = d[v] + w.second;
	    if(i==node-1){
	      //**********need in abc061d and abc137e**************	    
	      if(f[w.first]){
		flag = false;
	      }
	      //	      flag = false;
	    }
	  }
	}
      }
    }
    return flag;
  }

  X get_d(int v){
    return d[v];
  }
  
};


int main()
{
  int n,m,p;
  cin >> n >> m >> p;
  vector<int> a(m),b(m);
  vector<ll> c(m);
  rep(i,m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    c[i] -= p;
  }

  Graph<ll> bf(n);

  rep(i,m) bf.add_edge(a[i],b[i],-c[i]);

  rep(i,m){
    bf.add_rev(b[i],a[i]);
  }

  bf.run_dfs(n-1);
  //  bf.check_f();

  if(bf.bellmanford(0)){
    cout << max(0LL,-bf.get_d(n-1)) << "\n";
  }
  else{
    cout << -1 << "\n";
  }
  
  return 0;
}
