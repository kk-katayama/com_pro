#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(int &a,int &b){
  return a>b;
}
struct Tree
{
  int node;
  vector<vector<int>> edge;
  vector<int> d;
  
  Tree(int _node){
    node = _node;
    edge.resize(node);
    rep(i,node) edge[i].resize(0);
    d.assign(node,-1);
  }
  
  void add(int from,int to){
    edge[from].push_back(to);
  }

  
  int dfs(int v){
    if(edge[v].size()==0) return 0;
    vector<int> vec(0);
    for(auto &w:edge[v]){
      if(d[w]==-1) vec.push_back(dfs(w));
      else vec.push_back(d[w]);
    }
    sort(vec.begin(), vec.end(),comp);
    int res = 0,j = 1;
    for(auto &w:vec){
      res = max(res,w+j);
      j++;
    }
    return d[v] = res;
  }
};
int main()
{
  int n;
  cin >> n;
  vector<int> a(n-1);
  rep(i,n-1){
    cin >> a[i];
    a[i]--;
  }

  Tree tr(n);

  rep(i,n-1){
    tr.add(a[i],i+1);
  }

  cout << tr.dfs(0) << "\n";
  
  return 0;
}
