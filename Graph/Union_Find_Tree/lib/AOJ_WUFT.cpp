#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<typename X>
struct WUFT{
  vector<int> par;//親
  vector<int> rank;//木の深さ
  vector<int> size;//木の大きさ
  vector<X> diff_weight;//差分重み
  int n;

  WUFT(int _n){
    n = _n;
    par.resize(n);
    rank.resize(n,0);
    size.resize(n,1);
    diff_weight.resize(n,0);
    rep(i,n) par[i] = i;
  }

  //xの根を返す,差分重みを更新
  int find(int x){
    if(par[x] == x) return x;
    else{
      int r = find(par[x]);
      diff_weight[x] += diff_weight[par[x]]; //累積和
      return par[x] = r;
    }
  }

  X weight(int x){
    find(x);
    return diff_weight[x];
  }

  // xとyの距離を返す
  X diff(int x,int y){
    return weight(y) - weight(x);
  }
  
  //x,yを距離wで併合
  bool unite(int x,int y,X w){
    w += weight(x); w -= weight(y);
    x = find(x); y = find(y);
    if(x == y) return false;

    if(rank[x] < rank[y]){ // x(の根)をy(の根)の下にくっつける
      par[x] = y;
      size[y] += size[x];
      diff_weight[x] = -w;
    }
    else{ // y(の根)をx(の根)の下にくっつける
      par[y] = x;
      size[x] += size[y];
      diff_weight[y] = w;
      if(rank[x] == rank[y]) rank[x]++;
    }
    return true;
  }

  bool same(int x,int y){
    return find(x) == find(y);
  }

  int usize(int x){
    return size[find(x)];
  }
};
int main()
{
  int n,q;cin >> n >> q;
  vector<int> c(q),x(q),y(q),z(q);
  rep(i,q){
    cin >> c[i];
    if(c[i]==0) cin >> x[i] >> y[i] >> z[i];
    else cin >> x[i] >> y[i];
  }

  WUFT<int> wuf(n);
  rep(i,q){
    if(c[i]==0) wuf.unite(x[i],y[i],z[i]);
    else{
      if(wuf.same(x[i],y[i])) cout << wuf.diff(x[i],y[i]) << "\n";
      else cout << "?" << "\n";
    }

  }
  return 0;
}
