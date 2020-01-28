#include <iostream>
#include <algorithm>
#include <vector>
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
bool comp(pair<pair<int,int>,pair<int,int>> &a,pair<pair<int,int>,pair<int,int>> &b){
  return a.second.first<b.second.first;
}

int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  int q;
  cin >> q;
  vector<int> x(q),y(q),z(q);
  rep(i,q){
    cin >> x[i] >> y[i] >> z[i];
    x[i]--;
    y[i]--;
  }
  vector<pair<pair<int,int>,pair<int,int>>> p(q);
  rep(i,q){
    p[i] = {{x[i],y[i]},{z[i],i}};
  }

  sort(p.begin(), p.end(),comp);
  vector<bool> f(q,false);
  
  UFT uf(n);
  vector<int> res(q,m+1);
  rep(i,m){
    uf.unite(a[i],b[i]);
    rep(j,q){
      int zz;
      if(f[j]) continue;
      if(p[j].second.first>i+3) break;
      if(uf.same(p[j].first.first,p[j].first.second)){
	zz = uf.usize(p[j].first.first);
      }
      else{
	zz = uf.usize(p[j].first.first)+uf.usize(p[j].first.second);
      }
      if(zz>=p[j].second.first){
	res[p[j].second.second] = min(res[p[j].second.second],i+1);
	f[j] = true;
      }
    }
  }

  rep(i,q){
    cout << res[i] << "\n";
  }
  

  
  return 0;
}
