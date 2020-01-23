#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Graph
{
  int node;
  vector<vector<pair<int,int>>> edge;
  vector<int> d;

  Graph(int _node)
  {
    node = _node;
    edge.resize(node);
  }

  void add(int from,int to,int cost)
  {
    edge[from].push_back(make_pair(to,cost));
  }

  void bfs(int s)
  {
    queue<int> q;
    d.assign(node,-1);
    d[s] = 0;
    q.push(s);
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(auto& w:edge[v]){
	if(d[w.first]>=0) continue;
	d[w.first] = d[v] + w.second;
	q.push(w.first);
      }
    }
  }
};
int main()
{
  int r,c;
  cin >> r >> c;
  int sx,sy;
  cin >> sx >> sy;
  sx--;sy--;
  int gx,gy;
  cin >> gx >> gy;
  gx--;gy--;

  vector<string> s(r);
  rep(i,r) cin >> s[i];

  Graph gp(r*c);

  rep(i,r) rep(j,c){
    if(i-1>=0){
      if(s[i-1][j]=='.'){
	gp.add(i*c+j,(i-1)*c+j,1);
      }
    }
    if(i+1<r){
      if(s[i+1][j]=='.'){
	gp.add(i*c+j,(i+1)*c+j,1);
      }
    }
    if(j-1>=0){
      if(s[i][j-1]=='.'){
	gp.add(i*c+j,i*c+j-1,1);
      }
    }
    if(j+1<c){
      if(s[i][j+1]=='.'){
	gp.add(i*c+j,i*c+j+1,1);
      }
    }
  }
  
  gp.bfs(sx*c+sy);
  
  cout << gp.d[gx*c+gy] << "\n";
  return 0;
}
