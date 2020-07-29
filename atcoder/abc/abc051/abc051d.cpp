#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,m; cin >> n >> m;
  int inf = 1e+9+10;
  vector<vector<int>> edge(n, vector<int>(n, inf));
  vector<int> a(m),b(m),c(m);
  rep(i,m) {
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    edge[a[i]][b[i]] = c[i];
    edge[b[i]][a[i]] = c[i];    
  }

  rep(k,n){
    rep(i,n){
      rep(j,n){
	edge[i][j]=min(edge[i][j],edge[i][k]+edge[k][j]);
      }
    }
  }
  
  int res = 0;
  rep(i,m) {
    if(edge[a[i]][b[i]] != c[i]) res++;
  }
  cout << res << "\n";
  
  return 0;
}
