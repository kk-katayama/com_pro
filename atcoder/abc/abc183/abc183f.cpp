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

    if(size[x] < size[y]){
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
  int n,q; cin >> n >> q;
  vi c(n);
  rep(i,n) cin >> c[i];
  UFT uf(n);
  vector<map<int,int>> mp(n);
  rep(i,n) {
    mp[i][c[i]]++;
  }
  rep(i,q) {
    int t,x,y; cin >> t >> x >> y;
    if(t == 1) {
      x--; y--;
      int a = uf.find(x), b = uf.find(y);
      uf.unite(x, y);
      if(b != uf.find(b)) {
	for(auto val: mp[b]) {
	  auto [id, num] = val;
	  mp[a][id] += num;
	}
      }
      if(a != uf.find(a)) {      
	for(auto val: mp[a]) {
	  auto [id, num] = val;
	  mp[b][id] += num;
	}
      }
    }
    else {
      x--;
      cout << mp[uf.find(x)][y] << "\n";
    }
  }
  
  return 0;
}
