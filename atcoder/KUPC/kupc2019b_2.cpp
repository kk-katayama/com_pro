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
  int w;
  int v;
  vector<bool> f;

  Graph(int _node)
  {
    node = _node;
    edge.resize(node);
    f.assign(node,0);
  }

  void add(int from,int to)
  {
    edge[from].push_back(to);
  }

  bool bfs(int s,vector<int> ww,vector<int> vv)
  {
    if(f[s]) return false;
    queue<int> q;
    f[s] = true;
    q.push(s);
    while(!q.empty()){
      int x = q.front();
      q.pop();
      w += ww[x];
      v += vv[x];
      for(auto& y:edge[x]){
	if(f[y]) continue;
	f[y] = true;
	q.push(y);
      }
    }
    return true;
  }

  void reset()
  {
    w = 0;
    v = 0;
  }
};

int main()
{
  int n,m,W;
  cin >> n >> m >> W;
  vector<int> w(n),v(n);
  rep(i,n) cin >> w[i] >> v[i];
  vector<int> a(m),b(m);
  rep(i,m) cin >> a[i] >> b[i];
  rep(i,m){a[i]--;b[i]--;}
  Graph gp(n);
  rep(i,m){
    gp.add(a[i],b[i]);
    gp.add(b[i],a[i]);    
  }
  vector<int> ww(0),vv(0);
  rep(i,n){
    gp.reset();
    if(gp.bfs(i,w,v)){
      ww.push_back(gp.w);
      vv.push_back(gp.v);      
    }
  }
  
  // rep(i,ww.size()) cout << ww[i] << ":" << vv[i] << "\n";
  
  vector<vector<int>> dp(n+1,vector<int>(W+1,0));
  rep(i,ww.size()){
    rep(j,W+1){
      if(j-ww[i]>=0) dp[i+1][j] = max(dp[i][j],dp[i][j-ww[i]]+vv[i]);
      else dp[i+1][j] = dp[i][j];
    }
  }

  // rep(i,n+1){
  //   rep(j,W+1){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout  << "\n";
  // }
  
  cout << dp[ww.size()][W] << "\n";
  
  return 0;
}
