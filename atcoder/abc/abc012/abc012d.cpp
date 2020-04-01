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

  void show(){
    rep(i,n){
      rep(j,n) cout << edge[i][j] << " ";
      cout  << "\n";
    }
  }
  
  void solve(){
    wf();
    int res = 1e+9;
    rep(i,n){
      int tmp = 0;
      rep(j,n){
	if(i == j) continue;
	tmp = max( tmp , edge[i][j] );
      }
      res = min( res , tmp );
    }
    cout << res << "\n";
  }
  
};

int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(m),b(m),t(m);
  rep(i,m){
    cin >> a[i] >> b[i] >> t[i];
    a[i]--;b[i]--;
  }
  Graph gp(n);
  rep(i,m){
    gp.add( a[i] , b[i] , t[i] );
    gp.add( b[i] , a[i] , t[i] );    
  }
  gp.solve();
  
  return 0;
}
