#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Tree{
  int node;
  vector<vector<pair<int,int>>> edge;
  vector<int> col;
  int m;
  
  Tree(int n,vector<int> a,vector<int> b,vector<int> c){
    node = n;
    edge.resize(node);
    m = 0;
    col.resize(n-1,0);
    rep(i,node-1){
      edge[a[i]].push_back({b[i],c[i]});
      edge[b[i]].push_back({a[i],c[i]});        
    }
  }

  void dfs(int v,int p){
    int c = 1;
    for(auto w:edge[v]){
      if(p==c) c++;
      if(col[w.second]>0) continue;
      col[w.second] = c;
      dfs(w.first,c);
      m = max(m,c);
      c++;
    }
  }
  
};
int main()
{
  int n;cin >> n;
  vector<int> a(n-1),b(n-1),c(n-1);
  rep(i,n-1){
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
    c[i] = i;
  }
  Tree tr(n,a,b,c);
  tr.dfs(0,-1);
  cout << tr.m << "\n";
  rep(i,n-1){
    cout << tr.col[i] << "\n";
  }
  
  return 0;
}
