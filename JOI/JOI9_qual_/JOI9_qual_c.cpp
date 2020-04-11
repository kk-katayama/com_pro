#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Graph{
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<int>> edge;
  vector<int> d;
  
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){ n = _n; edge.resize(n);  }
  // 辺コストありのグラフ作成、_n頂点、_m辺、a[i]->b[i]の辺がある。
  Graph(int _n,int _m,vector<int> a,vector<int> b){
    n = _n;m = _m;edge.resize(n);
    rep(i,m){
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);      
    }
  }  

  // 辺の追加 コストあり
  void add_edge(int from,int to){ edge[from].push_back(to);}

  void bfs(int s)
  {
    int res = 0;
    d.assign(n, -1);
    queue<int> q;
    d[s] = 0;
    q.push(s);
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(auto w:edge[v]){
	if(d[w]>=0) continue;
	d[w] = d[v] + 1;
	if(d[w] <= 2) res++;
	if(d[w] >= 2) continue;
	q.push(w);
      }
    }
    cout << res << "\n";    
  }

};

int main()
{
  int n, m;cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Graph gp(n, m, a, b);
  gp.bfs(0);
    
  return 0;
}
