#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template<typename X>
class Graph{
private:
  int n;// 頂点数
  int m;// 辺の数
  vector<vector<X>> edge; // 隣接リスト
  X inf = 1e+9+10;
  
public:
  // 頂点数_nのグラフを作成
  Graph(int _n){
    n = _n;
    edge.resize(n, vector<X>(n, inf));
    rep(i,n) edge[i][i] = 0;
  }

  // 辺の追加 コストあり
  void add_edge(int from,int to,X cost){ edge[from][to] = cost;}

  void wf(){
    rep(k,n){
      rep(i,n){
	rep(j,n){
	  edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
	}
      }
    }
    rep(i,n) rep(j,n) edge[i][j] += (ll)1;
  }

  ll solve(ll x) {
    ll res = 0;
    vector<int> v;
    while(x > 0) {
      v.push_back(x % 10);
      x /= 10;
    }
    v.push_back(0);
    reverse(v.begin(), v.end());
    rep(i, v.size()-1) res += edge[v[i]][v[i+1]];
    return res;
  }

  
  void show() {
    rep(i,n) {
      rep(j,n) {
	cout << edge[i][j] << " ";
      }
      cout  << "\n";
    }
  }
  
};


int main()
{
  ll m,r;cin >> m >> r;

  Graph<ll> gp(10);
  gp.add_edge(0, 1, 1);
  gp.add_edge(1, 0, 1);  
  rep1(i,8) {
    int x = i + 1;
    int y = i + 3;
    if(x % 3 != 1) {
      gp.add_edge(i, x, 1);
      gp.add_edge(x, i, 1);      
    }
    if(y <= 9) {
      gp.add_edge(i, y, 1);
      gp.add_edge(y, i, 1);      
    }
  }

  gp.wf();

  ll u = r;
  int cnt = 0;
  while(u > 0) {
    u /= 10;
    cnt++;
  }

  ll res = gp.solve(r);;
  rep(i,pow(10, cnt)) {
    r += m;
    res = min(res, gp.solve(r));
  }
  cout << res << "\n";
  return 0;
}
