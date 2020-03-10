#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
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
  return 0;
}
