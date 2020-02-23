#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Tree{
private:
  int n;
  vector<vector<int>> edge;
public:
  Tree(int _n,vector<int> a,vector<int> b){
    n = _n;
    edge.resize(n);
    rep(i,n-1){
      edge[a[i]].push_back(b[i]);
      edge[b[i]].push_back(a[i]);      
    }
  }

  // pは頂点vの親頂点
  void dfs(int v,int p){
    for(auto w:edge[v]){
      if(w==p) continue;
      dfs(w,v);
    }
  }

};


int main()
{
  
  return 0;
}
