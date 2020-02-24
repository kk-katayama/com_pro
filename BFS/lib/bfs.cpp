#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Graph
{
  int node;
  vector<vector<int>> edge;
  vector<int> d;
  
  Graph(int _node)
  {
    node = _node;
    edge.resize(node);
  }

  void add(int from,int to)
  {
    edge[from].push_back(to);
  }

  void bfs(int s)
  {
    d.assign(node,-1);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(auto &w:edge[v]){
	if(f[w]>=0) continue;
	d[w] = d[v] + 1;
	q.push(w);
      }
    }
  }
};

int main()
{
  
  return 0;
}
