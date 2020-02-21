#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
struct Graph
{
  vector<vector<pair<pair<int,ll>,bool>>> edge;
  int n;
  vector<ll> d;
  vector<int> flag;
  
  Graph(int _n)
  {
    n = _n;
    edge.resize(n);
    d.assign(n,-1);
    flag.assign(n,0);
  }

  void add(int from,int to,ll cost)
  {
    edge[from].push_back(make_pair(make_pair(to,cost),0));
  }
  
  bool dfs(int v)
  {
    bool f = true;
    flag[v] = true;
    rep(i,edge[v].size()){
      if(edge[v][i].second) continue;
      edge[v][i].second = true;
      int w = edge[v][i].first.first;
      ll co = edge[v][i].first.second;
      if(d[w]==-1) {
	d[w] = d[v] + co;
	f = f&&dfs(w);
      }
      else{
	if(d[w]-d[v]!=co) return false;
      }
    }
    return f;
  }
};
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> l(m),r(m);
  vector<ll> d(m);
  rep(i,m){
    cin >> l[i] >> r[i] >> d[i];
    l[i]--;
    r[i]--;
  }

  Graph gp(n);
  rep(i,m){
    gp.add(l[i],r[i],d[i]);
    gp.add(r[i],l[i],-d[i]);    
  }

  bool f = true;
  rep(i,n){
    if(gp.flag[i]) continue;
    gp.d[i] = 0;
    f = f&&gp.dfs(i);
  }

  cout << (f?"Yes":"No") << "\n";
  
  return 0;
}
