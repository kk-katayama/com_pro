#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <fstream>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
struct Graph{
  int n;
  vector<vector<int>> edge;
  const int inf = 1e+9+10;
  map<int,string> mp;

  Graph(int _n){
    n = _n;
    edge.resize(n,vector<int>(n,inf));
  }

  void Add(int from,int to,int cost){
    edge[from][to]=cost;
  }

  void Make_Japan() {
    n = 47;
    edge.resize(n,vector<int>(n,inf));
    ifstream name("name.dat");
    string s; int idx;
    while(name >> idx >> s) {
      idx--;
      mp[idx] = s;
    }    
    ifstream list("list2.dat");
    int a,b;
    while(list >> a >> b) {
      a--; b--;
      edge[a][b] = 1;
      edge[b][a] = 1;
    }

  }


  void Show() {
    rep(i,n) {
      rep(j,n) cout << (edge[i][j] == inf ? 0 : edge[i][j]) << " ";
      cout << "\n";
    }
    rep(i,n) cout << mp[i] << "\n";
  }

  void Solve() {
    int X = 5;
    Make_Japan();
    wf();
    vector<bool> f(47, false);
    rep(i,n) {
      rep(j,n) {
      	rep(k,n) {
	  if(i >= j || j >= k) continue;
	  if(edge[i][j] >= X && edge[j][k] >= X && edge[k][i] >= X) {
	    cout << mp[i] << ":" << mp[j] << ":" << mp[k] << "\n";
	  }
	}
      }
    }
    rep(i,n) {
      if(i == 1 || i == 30) continue;
      if(edge[i][1] >= X && edge[i][30] >= X) {
	if(edge[i][1] == X || edge[i][30] == X) {	
	  cout << mp[i] << "\n";
	}
      }
    }
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
  Graph gp(1);
  gp.Solve();
  return 0;
}
