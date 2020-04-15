#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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
    }
  }  

  // 辺の追加 コストなし
  void add_edge(int from,int to){ edge[from].push_back(to);}

  // トポロジカルソート
  vector<int> t_sort() { 
    in.resize(n, 0);
    depth.resize(n);
    vector<int> res;

    rep(i,n) for(auto w : edge[i]) in[w]++;

    priority_queue<int, vector<int>, greater<int>> q;

    rep(i,n) if(in[i] == 0) q.push(i);
    
    while(!q.empty()) {
      int v = q.top(); q.pop();
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
  int n;cin >> n;
  vector<string> a(n), b(n);
  rep(i,n) cin >> a[i] >> b[i];

  Graph gp(26);
  rep(i,n) {
    if(a[i].size() <= b[i].size()) {
      rep(j,a[i].size()) {
	if(a[i][j] != b[i][j]) {
	  int from = a[i][j] - 'a';
	  int to = b[i][j] - 'a';
	  gp.add_edge(from, to);
	  break;
	}
      }
    }
    else {
      rep(j,b[i].size()) {
	if(a[i][j] != b[i][j]) {
	  int from = a[i][j] - 'a';
	  int to = b[i][j] - 'a';
	  gp.add_edge(from, to);
	  break;	  
	}
	if(j == b[i].size() - 1) {
	  cout << -1 << "\n";
	  return 0;
	}
      }
    }
  }

  vector<int> res = gp.t_sort();
  if(res.size() == 26) {
    rep(i,26) {
      char c = res[i] + 'a';
      cout << c;
    }
    cout  << "\n";
  }
  else {
    cout << -1 << "\n";
  }

  
  return 0;
}
