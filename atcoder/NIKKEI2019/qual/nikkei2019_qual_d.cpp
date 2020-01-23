#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll inf = 1e+16;
struct Graph
{
  vector<int> dat;
  int n;
  int m;
  vector<vector<pair<int,ll>>> edge;
  vector<ll> d;
  
  Graph(int _n,int _m){
    n = 1;
    m = _m;
    while(n<_n) n*=2;
    dat.resize(2*(2*n-1)+m);
    edge.resize(2*(2*n-1)+m);
  }

  void add(int from,int to,ll cost){
    edge[from].push_back(make_pair(to,cost));
  }

  void init(){
    int index = 2*n-1;
    rep(i,n-1){
      add(2*i+1,i,0);
      add(2*i+2,i,0);
      add(index+i,index+2*i+1,0);
      add(index+i,index+2*i+2,0);
    }
    rep(i,n){
      add(n-1+index+i,n-1+i,0);
    }
  }

  void update(int a,int b,int k,int l,int r,ll c,int to){
    if(r<=a||b<=l) return ;

    if(a<=l&&r<=b){
      add(k,to+2*(2*n-1),c);
      add(to+2*(2*n-1),k+2*n-1,0);      
    }
    else{
      update(a,b,2*k+1,l,(l+r)/2,c,to);
      update(a,b,2*k+2,(l+r)/2,r,c,to);      
    }
  }


  void dijkstra(int s){
    d.assign(2*(2*n-1)+m,inf);
    d[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push(make_pair(0,s));
    while(!q.empty()){
      pair<ll,int> p=q.top();q.pop();
      int w = p.second;
      if(d[w]<p.first) continue;
      for(auto& v:edge[w]){
	ll c = v.second;
	int t = v.first;
	if(d[t]>d[w]+c){
	  d[t]=d[w]+c;
	  q.push(make_pair(d[t],t));
	}
      }
    }
  }

  void show(){
    rep(i,2*(2*n-1)+m){
      cout << i << ":" << d[i] << "\n";
    }
    rep(i,2*(2*n-1)+m){
      for(auto& v:edge[i]){
	cout << i << ":" << v.first << ":" << v.second << "\n";
      }
    }

  }
  
};
int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> l(m),r(m);
  vector<ll> c(m);
  rep(i,m){
    cin >> l[i] >> r[i] >> c[i];
    l[i]--;
    r[i]--;
  }

  Graph gp(n,m);
  gp.init();
  rep(i,m){
    gp.update(l[i],r[i]+1,0,0,gp.n,c[i],i);
  }

  gp.dijkstra(gp.n-1);

  if(gp.d[gp.n-1+n-1+2*gp.n-1]==inf) cout << -1 << "\n";
  else cout << gp.d[gp.n-1+n-1+2*gp.n-1] << "\n";


  
  return 0;
}
