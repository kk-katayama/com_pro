#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD=1e+9+7;
struct mint{
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator-=(const mint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator*=(const mint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  mint operator+(const mint a) const{
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const{
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const{
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const{
    if(!t) return 1;
    mint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  mint inv() const{
    return pow(MOD-2);
  }
  mint& operator/=(const mint a){
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const{
    mint res(*this);
    return res/=a;
  }
};
const int M = 210000;
mint per[M];

class Tree {
private:
  int n; // 頂点数
  vector<vector<int>> edge; // 重み無し有向辺
  map<pair<int,int>,int> index; // 辺と全体辺番号（辺全体の通し番号）の対応
  map<pair<int,int>,int> index_root;  // 辺と局所辺番号（ある頂点から伸びる辺全体の通し番号）の対応
  vector<int> size; // size[i] := 頂点iを根とする部分木のサイズ
  vector<vector<int>> par; // par[i][0] := 頂点iの親
  vector<mint> dp; 
  vector<vector<mint>> sumdp;
  vector<vector<mint>> sumrev;
  vector<vector<int>> sumsize;
  vector<bool> f;
  
public:
  Tree(int _n, vector<int> a, vector<int> b) {
    n = _n;
    edge.resize(n);
    rep(i,n-1){
      add_edge(a[i], b[i], i);
      add_edge(b[i], a[i], i + n - 1);
    }
  }

  void add_edge(int from, int to, int num) {
    edge[from].push_back(to);
    index[{from, to}] = num; // 辺と辺番号の対応を作成
  }

  int dfs_init(int v,int p){
    par[v][0] = p;
    int res = 1;
    for(auto w:edge[v]) {
      if(w == p) continue;
      res += dfs_init(w, v);
    }
    return size[v] = res;
  }

  // sを根とする木の情報を取得（親、サイズ、局所辺番号）
  void init(int s) {
    par.resize(n, vector<int>(1));
    size.resize(n);
    dfs_init(s, -1);
    rep(root,n) {
      rep(i,edge[root].size()){
	index_root[ { root, edge[root][i] } ] = i;
      }
    }
  }

  mint dfs(int p,int root) {
    int in;
    if(p != -1) {
      in = index[{p, root}];
      if(dp[in].x > 0) return dp[in];
    }
    mint res(1);
    int cnt = 0;
    if(f[root]) {
      int inro = index_root[{root, p}];
      res *= sumdp[root][inro] * ( sumdp[root][ edge[root].size() ] / sumdp[root][ inro + 1 ] );
      res /= sumrev[root][inro] * ( sumrev[root][ edge[root].size() ] / sumrev[root][ inro + 1 ] );
      res *= per[ sumsize[root][inro] + sumsize[root][ edge[root].size() ] - sumsize[root][ inro + 1 ] ];
      return res;
    }
    rep(i,edge[root].size()) {
      int v = edge[root][i];
      if(v == p) continue;
      mint tmp = dfs(root, v);
      res *= tmp;
      if(p == -1) sumdp[root][i+1] = sumdp[root][i] * tmp;
      if(par[root][0] == v) {
	res /= (mint)per[ n - size[root]];
	cnt += n - size[root];
	if(p == -1){
	  sumrev[root][i+1] = sumrev[root][i] * per[n - size[root]];
	  sumsize[root][i+1] = sumsize[root][i] + n - size[root];
	}
      }
      else {
	res /= (mint)per[ size[v] ];
	cnt += size[v];
	if(p == -1) {
	  sumrev[root][i+1] = sumrev[root][i] * per[size[v]];
	  sumsize[root][i+1] = sumsize[root][i] + size[v];
	}
      }
    }
    res *= per[cnt];
    if(p == -1) {
      f[root] = true;
      return res;
    }
    return dp[in] = res;
  }

  void sum_init(){
    sumdp.resize(n);
    rep(i,n) {
      sumdp[i].resize( (int)edge[i].size() + 1);
      sumdp[i][0].x = 1;
    }
    sumrev.resize(n);
    rep(i,n) {
      sumrev[i].resize( (int)edge[i].size() + 1);
      sumrev[i][0].x = 1;
    }
    sumsize.resize(n);
    rep(i,n) {
      sumsize[i].resize( (int)edge[i].size() + 1);
      sumsize[i][0] = 0;
    }
  }
  
  void solve() {
    dp.resize( 2 * ( n - 1 ) );
    sum_init();
    f.resize(n, false);
    vector<ll> res(n);
    vector<int> perm(n);
    rep(i,n) perm[i] = i;
    sort(perm.begin(), perm.end(),
	 [&](int a,int b){
	   return edge[a].size() > edge[b].size();
	 });
    rep(i,n) {
      res[perm[i]] = dfs(-1, perm[i]).x;
    }
    rep(i,n) cout << res[i] << "\n";
  }
  
  void show(){
    rep(i,n) cout << i << ":" << size[i] << "\n";
  }
  
  
  
};



int main()
{
  per[0].x = 1;
  rep(i,M) per[i+1] = per[i] * (mint)(i+1);
  int n;cin >> n;
  vector<int> a(n-1),b(n-1);
  rep(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--;b[i]--;
  }
  Tree tr(n,a,b);
  tr.init(0);
  //  tr.show();
  tr.solve();
  return 0;
}
