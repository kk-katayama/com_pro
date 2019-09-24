#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct DAG{
  int node;
  vector<vector<int> > edge;
  vector<bool> visited,visiting;
  vector<int> dp;
  
  DAG(int N)
  {
    node = N;
    edge.resize(N);
  }
  
  void add_edge(int from,int to)
  {
    edge[from].push_back(to);
  }
  
  bool dfs_find_loop(int v)
  {
    bool f = true;
    visiting[v] = true;
    rep(i,edge[v].size()){
      int w = edge[v][i];
      if(visited[w]) continue;
      if(visiting[w]) return false;
      f = f&&dfs_find_loop(w);
    }
    visited[v] = true;
    return f;
  }  
  bool find_loop()
  {
    bool f = true;
    visited.assign(node,0);
    visiting.assign(node,0);
    rep(i,node){
      if(!visited[i]) f = f&&dfs_find_loop(i);
    }
    return f;
  }

  int dfs_longest_pass(int v)
  {
    if(dp[v]>=0) return dp[v];
    int res = 0;
    rep(i,edge[v].size()){
      int w = edge[v][i];
      res = max(res,dfs_longest_pass(w)+1);
    }
    return dp[v] = res;
  }
  
  int longest_pass()
  {
    int res = 0;
    dp.assign(node,-1);
    rep(i,node){
      dfs_longest_pass(i);
    }
    rep(i,node){
      res = max(res,dp[i]);
      cout << dp[i] << " ";
    }
    cout  << "\n";
    
    return res;
  }
  
  
};

int main()
{
  
  return 0;
}
