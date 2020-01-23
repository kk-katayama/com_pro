#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Graph
{
  int node;
  vector<vector<int>> edge;
  vector<bool> col;
  vector<bool> f;
  
  Graph(int _node)
  {
    node = _node;
    edge.resize(node);
    col.assign(node,0);
    f.assign(node,0);
  }
  
  void add(int from,int to)
  {
    edge[from].push_back(to);
  }

  bool bipa_check(int v,bool color)
  {
    f[v] = true;
    col[v] = color;
    for(auto& w:edge[v]){
      if(f[w]){
	if(col[w] == c) return false;
      }
      else if(!bipa_check(w,!color)) return false;
    }
    return true;
  }
};

int main()
{
  
  return 0;
}
