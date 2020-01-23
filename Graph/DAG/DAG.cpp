#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Graph{
  int node;
  int edge_num;
  vector<vector<int> > edge;
  vector<bool> visited,visiting;
  vector<int> dp;
  vector<int> top;
  vector<bool> used;
  
  Graph(int N)
  {
    node = N;
    edge.resize(N);
  }

  Graph(int n,int m,vector<int> a,vector<int> b){
    node = n;
    edge_num = m;
    edge.resize(node);
    rep(i,edge_num){
      edge[a[i]].push_back(b[i]);
    }
  }
  
  void add_edge(int from,int to)
  {
    edge[from].push_back(to);
  }

  void top_dfs(int v){
    if(used[v]) return;
    used[v] = true;
    for(auto w:edge[v]){
      top_dfs(w);
    }
    top.push_back(v);
  }

  void t_sort(){
    used.assign(node,false);
    rep(i,node){
      top_dfs(i);
    }
    reverse(top.begin(), top.end());
  }

  void show_top(){
    rep(i,node){
      cout << top[i] << "\n";
    }
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
    rep(i,node){
      if(visiting[i]){
	cout << i << "\n";
      }
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
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
  }

  Graph gp(n,m,a,b);
  gp.t_sort();
  gp.show_top();
  
  return 0;
}
