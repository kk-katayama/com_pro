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
      size[x] += size[x];
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
  int n,m,W;
  cin >> n >> m >> W;
  vector<int> w(n),v(n);
  rep(i,n) cin >> w[i] >> v[i];
  vector<int> a(m),b(m);
  rep(i,m) cin >> a[i] >> b[i];
  rep(i,m){a[i]--;b[i]--;}
  UFT uf(n);
  rep(i,m){
    uf.unite(a[i],b[i]);
  }
  vector<int> ww(n,0),vv(n,0);
  rep(i,n){
    ww[uf.find(i)] += w[i];
    vv[uf.find(i)] += v[i];    
  }

  // rep(i,n) cout << ww[i] << ":" << vv[i] << "\n";
  
  vector<vector<int>> dp(n+1,vector<int>(W+1,0));
  rep(i,n){
    rep(j,W+1){
      if(j-ww[i]>=0) dp[i+1][j] = max(dp[i][j],dp[i][j-ww[i]]+vv[i]);
      else dp[i+1][j] = dp[i][j];
    }
  }

  // rep(i,n+1){
  //   rep(j,W+1){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout  << "\n";
  // }
  
  cout << dp[n][W] << "\n";
  
  return 0;
}
