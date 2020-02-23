#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <utility>
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

  void zw_bfs(int s)
  {
    deque<int> dq;
    d.assign(node,-1);
    d[s] = 0;
    dq.push_back(s);
    while(!dq.empty()){
      int v = dq.front();
      dq.pop_front();
      for(auto& w:edge[v]){
	if(d[w.first]>=0) continue;
	d[w.first] = d[v] + w.second;
	if(w.second==0) dq.push_front(w.first);
	else dq.push_back(w.first);
      }
    }
  }
};

int main()
{
  int h,w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  Graph gp(h*w);
  int st,go;
  rep(i,h) rep(j,w){
    if(s[i][j]=='s') st = i*w+j;
    if(s[i][j]=='g') go = i*w+j;    
    if(i-1>=0){
      if(s[i-1][j]=='#'){
	gp.add((i*w+j),((i-1)*w+j),1);
      }
      else{
	gp.add((i*w+j),((i-1)*w+j),0);
      }
    }
    if(i+1<h){
      if(s[i+1][j]=='#'){
	gp.add((i*w+j),((i+1)*w+j),1);
      }
      else{
	gp.add((i*w+j),((i+1)*w+j),0);
      }
    }
    if(j-1>=0){
      if(s[i][j-1]=='#'){
	gp.add((i*w+j),(i*w+j-1),1);
      }
      else{
	gp.add((i*w+j),(i*w+j-1),0);
      }
    }
    if(j+1<w){
      if(s[i][j+1]=='#'){
	gp.add((i*w+j),(i*w+j+1),1);
      }
      else{
	gp.add((i*w+j),(i*w+j+1),0);
      }
    }
  }

  gp.zw_bfs(st);
  
  if(gp.d[go]<=2) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
