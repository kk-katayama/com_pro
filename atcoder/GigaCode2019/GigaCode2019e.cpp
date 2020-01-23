#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const double inf = 50000000;
int n,l;
double vs,ds;
vector<pair<pair<double,double>,double>> data;
vector<vector<pair<int,double>>> edge;
vector<double> d;
void dijkstra(int s){
  priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > q;
  d.assign(n+2,inf);
  d[s]=0;
  q.push(make_pair(0,s));
  while(!q.empty()){
    pair<double,int> p = q.top();q.pop();
    int w=p.second;
    if(d[w]<p.first) continue;
    for(int i=0;i<edge[w].size();i++){
      int t=edge[w][i].first;
      double c=edge[w][i].second;
      if(d[t]>d[w]+c){
	d[t]=d[w]+c;
	q.push(make_pair(d[t],t));
      }
    }
  }
}

int main()
{
  cin >> n >> l;
  cin >> vs >> ds;
  data.resize(n+2);
  data[0] = make_pair(make_pair(0,vs),ds);
  rep1(i,n){
    cin >> data[i].first.first >> data[i].first.second >> data[i].second;
  }
  data[n+1] = make_pair(make_pair(l,0),0);
  sort(data.begin(), data.end());
  
  edge.resize(n+2);

  rep(i,n+2){
    rep(j,n+2){
      if(i>=j) continue;
      if(data[j].first.first-data[i].first.first<=data[i].second){
	edge[i].push_back(make_pair(j,(data[j].first.first-data[i].first.first)/data[i].first.second));
      }
    }
  }

  dijkstra(0);

  if(d[n+1]==inf) cout << "impossible" << "\n";
  else printf("%.7f\n", d[n+1]);
  
  
  return 0;
}
