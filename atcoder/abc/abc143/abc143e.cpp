#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
struct Graph{
  int n;
  vector<vector<int>> edge;
  const int inf = 1e+9+10;

  Graph(int _n){
    n = _n;
    edge.resize(n,vector<int>(n,inf));
  }

  void add(int from,int to,int cost){
    edge[from][to]=cost;
  }

  void wf(){
    rep(k,n){
      rep(i,n){
	rep(j,n){
	  edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
	}
      }
    }
  }
};

int main()
{
  int n,m,l;cin >> n >> m >> l;
  vector<int> a(m),b(m),c(m);
  rep(i,m) cin >> a[i] >> b[i] >> c[i];
  int q;cin >> q;
  vector<int> s(q),t(q);
  rep(i,q) cin >> s[i] >> t[i];

  Graph gp1(n);
  rep(i,m){
    gp1.add(a[i] - 1, b[i] - 1, c[i]);
    gp1.add(b[i] - 1, a[i] - 1, c[i]);    
  }
  gp1.wf();

  Graph gp2(n);
  rep(i,n){
    rep(j,n){
      if(i == j) continue;
      if(gp1.edge[i][j] <= l){
	gp2.add(i, j, 1);
	gp2.add(j, i, 1);
      }
    }
  }
  gp2.wf();
  rep(i,q){
    if(gp2.edge[s[i] - 1][t[i] - 1] == gp2.inf) cout << -1 << "\n";
    else cout << gp2.edge[s[i] - 1][t[i] - 1] - 1 << "\n";
  }
  
  return 0;
}
