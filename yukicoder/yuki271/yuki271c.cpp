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
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
struct UFT{
  vector<int> par;//親
  vector<int> rank;//木の深さ
  vector<int> size;//木の大きさ
  int n;
  
  UFT(int _n)
  {
    n = _n;
    par.resize(n);
    rank.assign(n,0);
    size.assign(n,1);
    rep(i,n){
      par[i] = i;
    }
  }
  
  //xの根を返す
  int find(int x)
  {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  //x,yを併合
  void unite(int x,int y)
  {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank[x] < rank[y]){
      par[x] = y;
      size[y] += size[x];
    }
    else{
      par[y] = x;
      size[x] += size[y];
      if(rank[x] == rank[y]) rank[x]++;
    }
  }

  //x,yが同じグループにいるかどうかを返す
  bool same(int x,int y)
  {
    return find(x) == find(y);
  }

  //xの属する木のサイズを探す
  int usize(int x)
  {
    return size[find(x)];
  }
};


int main()
{
  int n,m,q; cin >> n >> m >> q;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  vi u(m),v(m);
  vvi e(n);
  rep(i,m) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
    e[u[i]].push_back(v[i]);
    e[v[i]].push_back(u[i]);    
  }

  UFT uf(n*7);
  rep(i,n) {
    rep(j,7) {
      int k = (j+1) % 7;
      if(s[i][j] == '1' && s[i][k] == '1') {
	uf.unite(i*7 + j, i*7 + k);
      }
    }
  }

  rep(i,n) {
    for(auto w: e[i]) {
      rep(j,7) {
	if(s[i][j] == '1' && s[w][j] == '1') {
	  uf.unite(i*7 + j, w*7 + j);
	}
      }
    }
  }

  while(q-- > 0) {
    int t,x,y; cin >> t >> x >> y;
    if(t == 1) {
      s[x-1][y-1] = '1';
      int ny = (y - 2 + 7) % 7;
      int nyy = y % 7;
      if(s[x-1][ny] == '1') uf.unite((x-1)*7 + y - 1, (x-1)*7 + ny);
      if(s[x-1][nyy] == '1') uf.unite((x-1)*7 + y - 1, (x-1)*7 + nyy);
      for(auto w: e[x-1]) {
	if(s[w][y-1] == '1') {
	  uf.unite((x-1)*7 + y - 1, w*7 + y - 1);
	}
      }
    }
    if(t == 2) {
      cout << uf.usize((x - 1) * 7) << "\n";
    }
  }
  
  return 0;
}
