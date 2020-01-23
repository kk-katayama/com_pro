#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Graph{
  int node;
  vector<vector<int>> edge;

  Graph(int _node){
    node = _node;
    edge.resize(node);
    
  }
  void add(int from,int to){
    edge[from].push_back(to);
  }
  vector<vector<int>> TSP(){
    vector<vector<int>> res(node);
    rep(i,node) res[i].assign(node,0);
    vector<int> sum(1<<node,0);
    vector<vector<int>> dp(1<<node);
    rep(i,(1<<node)) dp[i].assign(node,0);

    rep(s,node){
      rep(i,(1<<node)) dp[i].assign(node,0);
      sum.assign((1<<node),0);
      dp[1<<s][s] = 1;
      sum[1<<s] = 1;
      for(int S=(1<<s)+1;S<(1<<node);++S){
	rep(v,node){
	  if((S>>v)&1){
	    dp[S][v] = sum[S-(1<<v)];
	    sum[S] += dp[S][v];
	  }
	}
      }
      rep(i,node){
	rep(S,(1<<node)){
	  res[s][i] += dp[S][i];
	}
      }
    }
    
    return res;
  }

  
};
int main()
{
  int n;
  cin >> n;
  vector<vector<int>> edge(n);
  rep(i,n) edge[i].resize(n);
  rep(i,n) rep(j,n) cin >> edge[i][j];
  Graph gp(n);
  rep(i,n) rep(j,n){
    if(edge[i][j]){
      gp.add(i,j);
      gp.add(j,i);
    }
  }
  vector<vector<int>> res = gp.TSP();

  rep(i,n){
    rep(j,n){
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
