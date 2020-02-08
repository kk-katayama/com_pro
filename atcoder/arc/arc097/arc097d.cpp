#include <iostream>
#include <algorithm>
#include <vector>
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
  int n,m;
  cin >> n >> m;
  vector<int> p(n);
  rep(i,n){
    cin >> p[i];
    p[i]--;
  }
  vector<int> x(m),y(m);
  rep(i,m){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }

  UFT uf(2*n);
  rep(i,n){
    uf.unite(p[i]+n,i);
  }

  rep(i,m){
    uf.unite(x[i],y[i]);
  }

  
  int cnt=0;
  rep(i,n){
    if(uf.same(i,i+n)) cnt++;
  }
  cout << cnt << "\n";
  
  return 0;
}
