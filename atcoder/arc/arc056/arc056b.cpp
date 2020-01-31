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
  if(a.first==b.first) return a.second.first>b.second.first;
  else return a.first>b.first;
}
int main()
{
  int n,m,s;
  cin >> n >> m >> s;
  s--;
  vector<int> u(m),v(m);
  rep(i,m){
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
  }
  vector<pair<int,pair<int,int>>> p(m);
  rep(i,m){
    p[i] = {min(u[i],v[i]),{u[i],v[i]}};
  }
  rep(i,n){
    p.push_back({i,{-1,-1}});
  }
  sort(p.begin(), p.end(),comp);
  UFT uf(n);
  vector<int> res;
  rep(i,p.size()){
    if(p[i].second.first==-1){
      if(uf.same(s,p[i].first)){
	res.push_back(p[i].first);
      }
    }
    else{
      uf.unite(p[i].second.first,p[i].second.second);
    }
  }
  reverse(res.begin(), res.end());
  rep(i,res.size()){
    cout << res[i]+1 << "\n";
  }
  
  return 0;
}
