#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
vector<vector<int> > a;
map<pair<int,int>,int> mp;
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
    }
    
    return res+1;
  }
};


pair<int,int> pair_make(int x,int y){
  if(x<y) return make_pair(x,y);
  else return make_pair(y,x);
}

int main()
{
  cin >> n;
  a.resize(n);
  rep(i,n) a[i].resize(n-1);
  rep(i,n){
    rep(j,n-1){
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  
  {
    int k = 0;
    rep(i,n){
      for(int j=i+1;j<n;++j){
	mp[make_pair(i,j)] = k++;
      }
    }
  }

  int nn = n*(n-1)/2;
  DAG dag(nn);

  rep(i,n){
    rep(j,n-2){
      dag.add_edge(mp[pair_make(i,a[i][j])],mp[pair_make(i,a[i][j+1])]);
    }
  }
  
  if(dag.find_loop()){
    cout << dag.longest_pass() << "\n";
  }
  else{
    cout << -1 << "\n";
  }
  
  return 0;
}
