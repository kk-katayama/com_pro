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
  vector<int> t_sort() { 
    in.resize(n,0);
    depth.resize(n);    
    rep(v,n) for(int w : edge[v]) in[w]++; // 全ての頂点の入次数をカウント
    
    queue<int> q;
    rep(i,n) if(in[i] == 0) { // 入次数が0の頂点はスタート地点になる
      q.push(i);
      depth[i] = 0;
    }

    vector<int> res;
    while(!q.empty()) { 
      int v = q.front(); q.pop();
      res.push_back(v);
      for(int w : edge[v]) {
	in[w]--; // 入次数が0の頂点から伸びた先の頂点の入次数を1減らす
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