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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
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
  int n,m,W; cin >> n >> m >> W;
  vi w(n), v(n);
  rep(i,n) cin >> w[i] >> v[i];
  UFT uf(n);
  rep(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    uf.unite(a, b);
  }
  map<int,int> wmp, vmp;
  rep(i,n) {
    wmp[uf.find(i)] += w[i];
    vmp[uf.find(i)] += v[i];
  }
  
  vi nw, nv;
  for(auto val: wmp) {
    nw.push_back(val.S);
  }
  for(auto val: vmp) {
    nv.push_back(val.S);
  }  
  int N = nw.size();
  vii dp(N+1, vi(W+1, 0));
  rep1(i,N) {
    rep(j,W+1) {
      if(j - nw[i-1] >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-nw[i-1]] + nv[i-1]);
      else dp[i][j] = dp[i-1][j];
    }
  }
  cout << dp[N][W] << "\n";
  
  
  return 0;
}
