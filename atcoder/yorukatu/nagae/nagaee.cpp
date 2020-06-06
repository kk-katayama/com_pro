#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
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
    size.assign(n,0);
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
  int n;cin >> n;
  vector<int> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];

  int M = 1e+5;
  rep(i,n) {
    y[i] += M;
  }

  UFT uf(2*M+1);
  rep(i,n) {
    uf.unite(x[i], y[i]);
  }

  vector<ll> sumx(2*M+1, 0), sumy(2*M+1, 0);
  rep(i,2*M+1) {
    if(i <= M) sumx[uf.find(i)]++;
    else sumy[uf.find(i)]++;
  }

  ll res = 0;
  rep(i,2*M+1) {
    res += sumx[i]*sumy[i];
  }

  res -= n;
  cout << res << "\n";
  
  return 0;
}
