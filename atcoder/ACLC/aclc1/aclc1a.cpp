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
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
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
  int n; cin >> n;
  using pii = pair<pi,int>;
  vector<pii> p(n);
  rep(i,n) {
    int x,y; cin >> x >> y;
    x--; y--;
    p[i] = {{x, y}, i};
  }

  set<int> st;
  st.insert(n);
  UFT uf(n);
  sort(p.begin(), p.end());
  rep(i,n) {
    auto [ptmp, c] = p[i];
    auto [a, b] = ptmp;
    auto it = st.begin();
    while(*it < b) {
      uf.unite(b, *it);
      it++;
    }
    st.insert(b);
    vi tmp;
    bool f = false;
    it = st.begin();    
    while(*it <= b) {
      if(f) tmp.push_back(*it);
      f = true;
      it++;
    }
    for(auto val: tmp) {
      st.erase(val);
    }
  }

  vi res(n);
  rep(i,n) {
    auto [ptmp, c] = p[i];
    auto [a, b] = ptmp;
    res[c] = uf.usize(b);
  }

  for(auto val: res) cout << val << "\n";
  
  return 0;
}
