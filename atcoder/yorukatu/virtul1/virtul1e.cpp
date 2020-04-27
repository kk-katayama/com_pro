#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
class Graph{
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<int>> edge;// 辺
  vector<int> d;
  int start;
  vector<int> rev;
  vector<int> loop;
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){ n = _n; edge.resize(n);  }
  // 辺コストありのグラフ作成、_n頂点、_m辺、a[i]->b[i]の辺がある。
  Graph(int _n,int _m,vector<int> a,vector<int> b){
    n = _n;m = _m;edge.resize(n);
    rep(i,m){
      add_edge(a[i], b[i]);
      add_edge(b[i], a[i]); //無向辺
    }
  }  

  // 辺の追加 コストなし
  void add_edge(int from,int to){ edge[from].push_back(to);}

  void dfs(int v) {
    int w = edge[v][0];
    if(d[w] >= 0) {
      start = w;
      return ;
    }
    else {
      d[w] = d[v] + 1;
      rev[d[w]] = w;
      dfs(w);
    }
  }

  void dfs_loop(int v) {
    loop.push_back(v);
    int w = edge[v][0];
    if(w == start) return;
    dfs_loop(w);
  }

  
  void solve(int s,string kk){
    rev.resize(n+1);
    d.resize(n, -1);
    d[s] = 0;
    dfs(s);
    if(kk.size() <= 6) {
      int k = atoi(kk.c_str());
      if(d[start] >= k) {
	cout << rev[k]+1 << "\n";
	return ;
      }
      dfs_loop(start);
      int num = loop.size();
      cout << loop[ (k - d[start]) % num] + 1 << "\n";
      return ;
    }
    else {
      dfs_loop(start);      
      int mod = 0;
      int num = loop.size();      
      rep(i,kk.size()) {
	int x = kk[i] - '0';
	mod = (mod*10 + x) % num;
      }
      int z = d[start] % num;
      int y = (mod - z + num) % num;
      cout << loop[y] + 1 << "\n";      
      
    }

    
  }

  
};
int main()
{
  int n;cin >> n;
  int a;cin >> a;
  string k;cin >> k;
    //    ll k; cin >> k;
  vector<int> b(n);
  rep(i,n) {
    cin >> b[i];
    b[i]--;
  }

  
  Graph gp(n);
  rep(i,n) gp.add_edge(i, b[i]);
  gp.solve(a-1, k);
  
  return 0;
}
