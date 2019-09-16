#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll infl = 1LL<<60;
template <typename X>
struct BellmanFord{
  int node;
  vector<vector<pair<int,X>>> edge;
  vector<X> d;

  BellmanFord(int _n){
    node = _n;
    d.assign(node,-infl);
    edge.resize(node);
  }
  
  //辺の追加
  void add_edge(int from,int to,X cost){
    edge[from].push_back(make_pair(to,cost));
  }
 
  void bellmanford(int s){
    d[s] = 0;
    rep(i,node-1){
      rep(j,node){
	if(d[j]==-infl) continue;
	for(auto& k:edge[j]){
	  d[k.first] = max(d[k.first],d[j]+k.second);
	}
      }
    }
    
    vector<bool> pos(node,0);
    rep(i,node){
      rep(j,node){
	if(d[j]==-infl) continue;
	for(auto& k:edge[j]){
	  if(d[k.first]<d[j]+k.second){
	    pos[k.first] = true;
	    d[k.first] = d[j] + k.second;
	  }
	  if(pos[j]) pos[k.first] = true; 
	}
      }
    }

    rep(i,node) if(pos[i]) d[i] = infl;
    
  }

};

int main()
{
  int n,m,p;
  cin >> n >> m >> p;
  vector<int> a(m),b(m);
  vector<ll> c(m);
  rep(i,m){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    c[i] -= p;
  }

  BellmanFord<ll> bf(n);

  rep(i,m) bf.add_edge(a[i],b[i],c[i]);

  bf.bellmanford(0);

  cout << (bf.d[n-1]!=infl?(max(bf.d[n-1],(ll)0)):-1) << "\n";

  
  return 0;
}

