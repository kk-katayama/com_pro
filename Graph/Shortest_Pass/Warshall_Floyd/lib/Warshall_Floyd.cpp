#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int inf = 1e+9+10;
struct Graph{
  int node;
  vector<vector<int>> edge;
  int liq;
  vector<vector<int>> edge2;

  
  Graph(int n,int l){
    node = n;
    liq = l;
    edge.resize(node,vector<int>(node,inf));
    edge2.resize(node,vector<int>(node,inf));    
  }

  void add(int from,int to,int cost){
    edge[from][to]=cost;
  }

  void wf(){
    rep(k,node){
      rep(i,node){
  	rep(j,node){
	  edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
	}
      }
    }
  }

  void add2(){
    rep(i,node){
      rep(j,node){
	if(i==j) continue;
	if(edge[i][j]<=liq) edge2[i][j]=1;
      }
    }
  }
  
  void wf2(){
    rep(k,node){
      rep(i,node){
  	rep(j,node){
	  edge2[i][j]=min(edge2[i][j],edge2[i][k]+edge2[k][j]);
	}
      }
    }
  }

  
  

};



int main()
{
  int n,m,l;
  cin >> n >> m >> l;
  vector<int> a(m),b(m),c(m);
  rep(i,m) cin >> a[i] >> b[i] >> c[i];
  int q;
  cin >> q;
  vector<int> s(q),t(q);
  rep(i,q) cin >> s[i] >> t[i];

  Graph gp(n,l);

  rep(i,m){
    a[i]--;
    b[i]--;
    gp.add(a[i],b[i],c[i]);
    gp.add(b[i],a[i],c[i]);    
  }
  gp.wf();

  gp.add2();
  gp.wf2();

  rep(i,q){
    s[i]--;
    t[i]--;
    if(gp.edge2[s[i]][t[i]]==inf) cout << -1 << "\n";
    else cout << gp.edge2[s[i]][t[i]]-1 << "\n";
  }
  

  
  return 0;
}
