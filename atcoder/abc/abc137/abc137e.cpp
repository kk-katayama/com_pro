#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int VMAX=2600,EMAX=5010;
const ll INF = 1e+9;
const ll INFLL = 1e+17;
int V,E;
ll p;
int a[5010],b[5010];
ll c[5010];
struct edge{
  int from,to;
  ll cost;
};
edge e[EMAX];
ll d[VMAX];
bool update;
bool bellmanford(int s){
  for(int i=0;i<V;i++) d[i]=INFLL;
  d[s]=0;
  for(int j=0;j<2*V;j++){
    update=false;
    for(int i=0;i<E;i++){
      int f=e[i].from,t=e[i].to;
      ll c=e[i].cost;
      if(d[f]!=INFLL&&d[t]>d[f]+c){
	d[t]=d[f]+c;
	if(j==V-1) d[t]=-INF;
	update=true;
	if(j>=V-1&&t==V-1) return false;
      }
    }
    if(!update) break;
  }
  return true;
}

int main()
{
  cin >> V >> E >> p;
  rep(i,E){
    cin >> a[i] >> b[i] >> c[i];
    e[i].from = --a[i];
    e[i].to = --b[i];
    e[i].cost = -c[i]+p;
  }
  

  
  if(!bellmanford(0)) cout << -1 << "\n";
  else{
    cout << max((ll)0,-d[V-1]) << "\n";
  }
  
  return 0;
}

