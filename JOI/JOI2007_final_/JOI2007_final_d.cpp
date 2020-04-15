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
  vector<vector<int>> edge;// 辺

  vector<int> in; //入次数
  vector<int> depth; // トポロジカルソートしたときの深さ
  
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){ n = _n; edge.resize(n);  }
  // 辺コストありのグラフ作成、_n頂点、_m辺、a[i]->b[i]の辺がある。
  Graph(int _n,int _m,vector<int> a,vector<int> b){
    n = _n;m = _m;edge.resize(n);
    rep(i,m){
      add_edge(a[i], b[i]);
      //      add_edge(b[i], a[i]); //無向辺
    }
  }  

  // 辺の追加 コストなし
  void add_edge(int from,int to){ edge[from].push_back(to);}

  vector<int> t_sort() {
    in.resize(n,0);
    depth.resize(n);    
    rep(v,n) for(int w : edge[v]) in[w]++;
    
    queue<int> q;
    rep(i,n) if(in[i] == 0) {
      q.push(i);
      depth[i] = 0;
    }

    vector<int> res;
    while(!q.empty()) {
      int v = q.front(); q.pop();
      res.push_back(v);
      for(int w : edge[v]) {
	in[w]--;
	if(in[w] == 0) {
	  q.push(w);
	  depth[w] = depth[v] + 1;
	}
      }
    }
    
    return res;
  }

  int GetDepth(int v) { return depth[v]; }
  
};

int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  Graph gp(n, m, a, b);
  vector<int> tp = gp.t_sort();
  bool f = true;
  rep(i,n) {
    cout << tp[i]+1 << "\n";
    if(i != n-1) {
      if(gp.GetDepth(tp[i]) == gp.GetDepth(tp[i+1]) ) f = false;
    }
  }
  if(f) cout << 0 << "\n";
  else cout << 1 << "\n";
  
  return 0;
}



