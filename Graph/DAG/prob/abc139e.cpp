#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
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
      //      add_edge(b[i], a[i]); //無向辺
    }
  }  

  // 辺の追加 コストなし
  void add_edge(int from,int to){ edge[from].push_back(to);}

  // トポロジカルソート
  int t_sort() { 
    in.resize(n,0);
    depth.resize(n);    
    rep(v,n) for(int w : edge[v]) in[w]++; // 全ての頂点の入次数をカウント
    
    queue<int> q;
    rep(i,n) if(in[i] == 0) { // 入次数が0の頂点はスタート地点になる
      q.push(i);
      depth[i] = 0;
    }

    int cnt = 0;
    int res = 0;
    while(!q.empty()) { 
      int v = q.front(); q.pop();
      cnt++;
      for(int w : edge[v]) {
	in[w]--; // 入次数が0の頂点から伸びた先の頂点の入次数を1減らす
	if(in[w] == 0) {
	  q.push(w);
	  depth[w] = depth[v] + 1;
	  chmax(res, depth[w]);
	}
      }
    }
    
    if(cnt == n) return res;
    else return -1;
  }

  int GetDepth(int v) { return depth[v]; }
  
};

int main()
{
  int n;cin >> n;
  vector<vector<int>> a(n, vector<int>(n-1));
  rep(i,n) {
    rep(j,n-1) {
      cin >> a[i][j]; a[i][j]--;
    }
  }

  int cnt = 0;
  map<pair<int,int>,int> mp;
  rep(i,n) {
    rep(j,n) {
      if(i >= j) continue;
      else mp[{i, j}] = cnt++;
    }
  }
  
  vector<int> b, c;
  rep(i,n) {
    rep(j,n-2) {
      if(i < a[i][j]) b.push_back(mp[{i, a[i][j]}]);
      else b.push_back(mp[{a[i][j], i}]);
      if(i < a[i][j+1]) c.push_back(mp[{i, a[i][j+1]}]);
      else c.push_back(mp[{a[i][j+1], i}]);      
    }
  }

  Graph gp(cnt, b.size(), b, c);
  int res = gp.t_sort();
  if(res >= 0) {
    cout << res+1 << "\n";
  }
  else {
    cout << -1 << "\n";
  }
  
  return 0;
}
