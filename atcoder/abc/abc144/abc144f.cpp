#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<vector<int>> edge(n);
  rep(i,m){
    int s,t;
    cin >> s >> t;
    s--;
    t--;
    edge[s].push_back(t);
  }

  vector<double> e(n,0);
  for(int v=n-2;v>=0;--v){
    double x = edge[v].size();
    for(auto w:edge[v]){
      e[v] += e[w]/x;
    }
    e[v] += 1.;
  }

  // rep(i,n){
  //   cout << i << ":" << e[i] << "\n";
  // }

  double res = 1e+15;
  rep(v,n){
    if(edge[v].size()<=1){
      res = min(res,e[0]);
      continue;
    }
    double mx=0,sum=0,x=edge[v].size();
    vector<double> ee=e;
    for(auto w:edge[v]){
      sum += e[w];
      mx = max(mx,e[w]);
    }
    sum -= mx;
    ee[v] = sum/(x-1.)+1.;
    if(v!=0){
      for(int vv=v-1;vv>=0;--vv){
	ee[vv] = 0.;
	double xx = edge[vv].size();
	for(auto ww:edge[vv]){
	  ee[vv] += ee[ww]/xx;
	}
	ee[vv] += 1.;
      }
    }
    res = min(res,ee[0]);
  }

  printf("%.7f\n", res);
  return 0;
}
