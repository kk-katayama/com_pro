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
bool comp(pair<int,pair<int,int>> &a,pair<int,pair<int,int>> &b){
  if(a.first==b.first){
    return a.second.second>b.second.second;
  }
  return a.first > b.first;
}

int main()
{
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m),y(m);
  rep(i,m){
    cin >> a[i] >> b[i] >> y[i];
    a[i]--;
    b[i]--;
  }
  int q;
  cin >> q;
  vector<int> v(q),w(q);
  rep(i,q){
    cin >> v[i] >> w[i];
    v[i]--;
  }

  const int inf=100000;
  vector<pair<int,pair<int,int>>> p(m+q);
  rep(i,m){
    p[i] = make_pair(y[i],make_pair(a[i],b[i]));
  }
  rep(i,q){
    p[i+m] = make_pair(w[i],make_pair(v[i],inf+i));
  }
  sort(p.begin(), p.end(),comp);

  UFT uf(n);
  vector<int> res(q);
  rep(i,m+q){
    int x = p[i].first;
    int y = p[i].second.first;
    int z = p[i].second.second;
    // cout << x << " ";
    // cout << y << " ";
    // cout << z << "\n";

    if(z>=inf){
      res[z-inf] = uf.usize(y);
    }
    else{
      uf.unite(y,z);
    }
    // rep(j,n){
    //   cout << j << ":";
    //   cout << uf.usize(j) << "\n";
    // }    
  }

  rep(i,q){
    cout << res[i] << "\n";
  }
  
  
  return 0;
}
