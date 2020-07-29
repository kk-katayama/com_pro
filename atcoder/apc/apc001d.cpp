#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
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
  int n,m; cin >> n >> m;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<int> x(m),y(m);
  rep(i,m) {
    cin >> x[i] >> y[i];
  }
  if(m + n/2 < n - 1) {
    cout << "Impossible" << "\n";
    return 0;
  }
  
  UFT uf(n);
  rep(i,m) uf.unite(x[i], y[i]);
  set<int> st;
  rep(i,n) st.insert(uf.find(i));
  int idx = 0;
  map<int,int> mp;
  for(auto s: st) mp[s] = idx++;
  vector<vector<ll>> vec(idx);
  rep(i,n) {
    vec[mp[uf.find(i)]].push_back(a[i]);
  }

  ll res = 0;
  multiset<ll> mst;
  if(idx == 1) {
    cout << 0 << "\n";
    return 0;
  }
  
  rep(i,idx) {
    sort(vec[i].begin(), vec[i].end());
    rep(j,vec[i].size()) {
      if(j == 0) {
	res += vec[i][j];
      }
      else {
	mst.insert(vec[i][j]);
      }
    }
  }

  int cnt = (idx - 1)*2 - idx;
  auto it = mst.begin();
  while(cnt-- > 0) {
    res += *it;
    it++;
  }
  cout << res << "\n";
  
  return 0;
}
