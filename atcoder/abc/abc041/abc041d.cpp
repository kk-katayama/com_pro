#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
struct Graph{
  int node;
  vector<vector<int>> edge;
  vector<vector<ll>> dp;
  vector<vector<int>> pre;
  
  Graph(int node_){
    node = node_;
    edge.resize(node,vector<int>(node,0));
    dp.resize(node,vector<ll>((1<<node),0));
    pre.resize(node);
    // rep(i,node){
    //   edge[i][i] = 1;
    // }
  }

  void add_edge(int from,int to){
    edge[from][to] = 1;
  }

  void add_pre(int from,int to){
    pre[from].push_back(to);
  }

  void dfs(int v,int S){
    rep(i,node){
      if((S>>i)&1){
	add_edge(i,v);
      }
    }
    for(auto &w:pre[v]){
      dfs(w,S+(1<<v));
    }
  }

  
  void show(){
    rep(i,node){
      rep(j,node){
	cout << edge[i][j] << " ";
      }
      cout << "\n";
    }
  }

  void solve(){
    rep(i,node){
      dp[i][(1<<i)] = 1;
    }
    rep(S,(1<<node)){
      rep(w,node){
	if(!((S>>w)&1)) continue;
	rep(v,node){
	  if(!((S>>v)&1)) continue;	  
	  bool f = true;
	  rep(u,node){
	    if((S>>u)&1){
	      if(edge[u][w]==1){
		f = false;
		break;
	      }
	    }
	  }
	  if(f) dp[w][S] += dp[v][S-(1<<w)];
	}
      }
    }

    // rep(i,node){
    //   rep(S,(1<<node)){
    // 	cout << i << ":" << S << ":" << dp[i][S] << "\n";
    //   }
    // }
    

    ll res = 0;
    rep(i,node){
      res += dp[i][(1<<node)-1];
    }
    cout << res << "\n";
  }
  
};
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> x(m),y(m);
  rep(i,m){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }

  Graph gp(n);
  rep(i,m){
    gp.add_pre(x[i],y[i]);
  }
  rep(i,n){
    gp.dfs(i,0);
  }
  //  gp.show();

  gp.solve();
  
  return 0;
}
