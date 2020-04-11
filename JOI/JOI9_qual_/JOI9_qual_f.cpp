#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
class Graph{
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<int>> edge; //コストなし有向辺
  vector<vector<int>> dp;
  
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){ n = _n; edge.resize(n);  }
  // 辺コストありのグラフ作成、_n頂点、_m辺、a[i]->b[i]の辺がある。
  Graph(int _n,int _m,vector<int> a,vector<int> b) {
    n = _n;m = _m;edge.resize(n);
    rep(i,m){
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]);      
    }
  }  

  // 辺の追加 コストなし
  void add_edge(int from,int to){ edge[from].push_back(to);}

  void bitDP() {
    dp.resize( (1 << n), vector<int>(n, 0) );
    dp[0][0] = 1;
    rep(mask, (1 << n) ) {
      rep(i, n) {
	if( mask == 0 && i == 0) {
	  for(auto v : edge[i]) {
	    if( (mask >> v) & 1) continue;
	    dp[ mask | (1 << v) ][v] += dp[mask][i];
	  }	  
	}
	if( (mask >> i) & 1) {
	  for(auto v : edge[i]) {
	    if( (mask >> v) & 1) continue;
	    dp[ mask | (1 << v) ][v] += dp[mask][i];
	  }
	}
      }
    }
    cout << dp[ (1 << n) - 1][0] << "\n";
  }
  
};

int main()
{
  int n,m; cin >> n >> m;
  vector<vector<int>> s(m, vector<int>(n));
  rep(i,m) rep(j,n) cin >> s[i][j];

  int index = 1;
  vector<pair<int,int>> p(n*m);
  map<pair<int,int>,int> mp;
  rep(i,m) {
    rep(j,n) {
      if(s[i][j] == 1) {
	p[index] = {i, j};
	mp[{i, j}] = index;
	index++;
      }
      if(s[i][j] == 2) {
	mp[{i, j}] = 0;
	p[0] = {i, j};
      }
    }
  }

  Graph gp(index);
  
  rep(i,m) {
    int x = -1;
    rep(j,n) {
      if(s[i][j] == 1 || s[i][j] == 2) {
	if(x == -1) x = mp[{i, j}];
	else {
	  int y = mp[{i, j}];
	  gp.add_edge(x, y);
	  gp.add_edge(y, x);
	  x = y;
	}
      }
    }
  }

  rep(j,n) {
    int x = -1;
    rep(i,m) {
      if(s[i][j] == 1 || s[i][j] == 2) {
	if(x == -1) x = mp[{i, j}];
	else {
	  int y = mp[{i, j}];
	  gp.add_edge(x, y);
	  gp.add_edge(y, x);
	  x = y;
	}
      }
    }
  }  

  gp.bitDP();
  
  return 0;
}
