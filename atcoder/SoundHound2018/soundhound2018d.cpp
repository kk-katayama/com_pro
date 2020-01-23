#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef long long ll;
const ll inf = 1e+15;
const int NMAX = 200000;
int N,M,S,T;
ll d[NMAX];
vector<pair<int,ll>> edge[NMAX];
void dijkstra(int s){
  priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
  for(int i=0;i<N;++i) d[i] = inf;
  d[s]=0;
  q.push(make_pair(0,s));
  while(!q.empty()){
    pair<ll,int> p = q.top();q.pop();
    int w=p.second;
    if(d[w]<p.first) continue;
    for(int i=0;i<edge[w].size();i++){
      int t=edge[w][i].first;
      ll c=edge[w][i].second;
      if(d[t]>d[w]+c){
	d[t]=d[w]+c;
	q.push(make_pair(d[t],t));
      }
    }
  }
}

ll db[NMAX];
vector<pair<int,ll>> edgeb[NMAX];
void dijkstrab(int s){
  priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
  for(int i=0;i<N;++i) db[i] = inf;
  db[s]=0;
  q.push(make_pair(0,s));
  while(!q.empty()){
    pair<ll,int> p = q.top();q.pop();
    int w=p.second;
    if(db[w]<p.first) continue;
    for(int i=0;i<edgeb[w].size();i++){
      int t=edgeb[w][i].first;
      ll c=edgeb[w][i].second;
      if(db[t]>db[w]+c){
	db[t]=db[w]+c;
	q.push(make_pair(db[t],t));
      }
    }
  }
}


int main()
{
  cin >> N >> M >> S >> T;
  for(int i=0;i<M;++i){
    int u,v;
    ll a,b;
    cin >> u >> v;
    cin >> a >> b;
    u--;v--;
    edge[u].push_back(make_pair(v,a));
    edge[v].push_back(make_pair(u,a));
    edgeb[u].push_back(make_pair(v,b));
    edgeb[v].push_back(make_pair(u,b));		          
  }

  dijkstra(--S);
  dijkstrab(--T);
  vector<ll> res(N);
  for(int i=0;i<N;++i){
    res[i] = d[i]+db[i];
  }
  ll mini = inf;
  for(int i=N-1;i>=0;--i){
    mini = min(mini,res[i]);
    res[i] = inf - mini;
  }
  for(int i=0;i<N;++i){
    cout << res[i] << "\n";
  }
  
  return 0;
}
