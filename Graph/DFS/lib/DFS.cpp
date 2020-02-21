#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Graph{
private:
  int node;
  int edge_num;
  vector<vector<int>> edge;  
  vector<int> f;
  vector<int> d;
  int time;
public:
  //***************Constractor****************************
  Graph(int n,vector<int> a,vector<int> b){
    node = n;
    edge_num = a.size();
    time = 1;
    edge.resize(node);
    f.resize(node,0);
    d.resize(node);    
    rep(i,edge_num){
      edge[a[i]].push_back(b[i]);
    }
  }

  //***********************************************
  
  void simple_dfs(int v){
    f[v] = time++;
    for(auto w:edge[v]){
      if(f[w]>0) continue;
      simple_dfs(w);
    }
    d[v] = time++;
  }

  void run_dfs(int s){//check each node can reach goal
    rep(i,node){
      if(f[i]<=0) simple_dfs(i);
    }
  }

  void show(){
    rep(i,node){
      cout << i+1 << " " << f[i] << " " << d[i] << "\n";
    }
  }
};


int main()
{
  int n;
  cin >> n;
  vector<int> a,b;
  rep(i,n){
    int aa;cin >> aa;aa--;
    int m;cin >> m;
    rep(i,m){
      int bb;cin >> bb;bb--;
      a.push_back(aa);
      b.push_back(bb);      
    }
  }

  Graph gp(n,a,b);
  gp.run_dfs(0);
  gp.show();
  
  return 0;
}
