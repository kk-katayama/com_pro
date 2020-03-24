#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
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
  int n,m,d;cin >> n >> m >> d;
  vector<int> a(m);
  rep(i,m) { cin >> a[i];a[i]--; }
  vector<int> g(n);
  rep(i,n) g[i] = i;
  rep(i,m) swap( g[a[i]] , g[a[i] + 1] );
  vector<int> edge(n);
  rep(i,n) edge[g[i]] = i;
  UFT uf(n);
  rep(i,n) uf.unite( i , edge[i] );
  map<int,int> mp;
  int cnt = 1;
  rep(i,n) {
    if(mp[ uf.find(i) ] > 0) continue;
    mp[ uf.find(i) ] = cnt++;
  }
  
  vector<vector<int>> v(cnt - 1);
  vector<pair<int,int>> p(n);
  rep(i,n){
    if( v[ mp[ uf.find(i) ] - 1 ].size() != 0 ) continue;
    int w = i;
    rep(j,uf.usize(i)){
      v[ mp[ uf.find(i) ] - 1 ].push_back(w);
      p[w] = { mp[ uf.find(i) ] - 1 , j };
      w = edge[w];
    }
  }

  // rep(i,cnt - 1) {
  //   rep(j,v[i].size()) cout << v[i][j] << " ";
  //   cout  << "\n";
  // }

  rep(i,n) {
    int s = v[ p[i].first ].size();
    int res = v[ p[i].first ][ ( p[i].second + d ) % s ];
    cout << res + 1 << "\n";
  }

  
  return 0;
}
