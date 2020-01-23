#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> c(m),a(m),b(m);
  rep(i,m){
    cin >> c[i];
    cin >> a[i];
    cin >> b[i];
  }

  vector<vector<pair<int,int>>> edge(n);
  rep(i,m){
    edge[a[i]].push_back(make_pair(b[i],c[i]+1));
    edge[b[i]].push_back(make_pair(a[i],c[i]+1));    
  }

  auto comp = [](pair<int,pair<int,int>> x,pair<int,pair<int,int>> y){
		if(x.first==y.first) return x.second.first>=y.second.first;
		else return x.first>y.first;
		  };
  priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, decltype(comp)> q(comp);

  const int inf = 1e+9;
  vector<int> d(n,inf);
  q.push(make_pair(0,make_pair(0,0)));
  while(!q.empty()){
    pair<int,pair<int,int>> p=q.top();
    q.pop();
    int v=p.second.second;
    int b=p.second.first;
    int cost=p.first;
    if(d[v]<=cost) continue;
    d[v]=cost;
    cout << v << ":";
    cout << d[v] << "\n";
    for(auto& e:edge[v]){
      int w=e.first;
      int c=e.second;
      if(d[w]==inf){
	if(c==1){	  
	  q.push(make_pair(d[v]+1,make_pair(b,w)));
	}
	else{
	  q.push(make_pair(d[v]+b+1,make_pair(b+1,w)));
	}
      }
    }
  }

  rep(i,n){
    cout << d[i] << "\n";
  }
  
  return 0;
}
