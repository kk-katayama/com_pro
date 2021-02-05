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
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
//----------------------------
// 抽象化セグ木
// 二項演算と単位元を渡して使ってね
///****例****************************
//  auto f = [&](int a,int b){ return a+b;}; // 二項演算:和
//  int id = 0; //単位元:0
//  SegTree<decltype(f),int> seg(f,id);
//************************************
//----------------------------

template <typename F,typename T>
struct SegTree{
  // 二項演算merge,単位元identify
  T identity;
  F merge; 
  int size;
  vector<T> dat;
  
  // 二項演算fと単位元idを渡して宣言する
  SegTree(F f,T id):merge(f),identity(id){}

  // データの要素の数nを渡して初期化、sizeはnより大きい2の冪乗
  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1,identity);
  }

  // 配列を渡して0(n)で初期化
  void build(vector<T> vec){
    rep(i,vec.size()) dat[size-1+i] = vec[i];
    dfs(0);
  }
  
  T dfs(int k){
    if(k>=size-1) return dat[k];
    else return dat[k] = merge(dfs(2*k+1),dfs(2*k+2));
  }

  // index kの要素をaに変更
  void update(int k,T a){
    k += size - 1;
    dat[k] = a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = merge(dat[2*k+1],dat[2*k+2]);
    }
  }
  
  // index kの要素にaを加算
  void add(int k,T a){
    k += size - 1;
    dat[k] += a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = merge(dat[2*k+1],dat[2*k+2]);
    }
  }

  // 区間[a,b)に対するクエリに答える。(k,l,r)=(0,0,size)
  T query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return identity;
    
    if(a<=l&&r<=b) return dat[k]; 
    else return merge(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
  }

  T query(int a,int b){
    return query(a, b, 0, 0, size);
  }

  // デバッグ用
  void show(){
    int index = 0;
    int num = 1;
    while(index<size){
      rep(i,num){
	if(dat[i+index]==identity) cout << "e ";
	else cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
  }
  
  
};

int main()
{
  ll h,w; cin >> h >> w;
  ll m; cin >> m;
  vl x(m),y(m);
  vvl z(w);
  rep(i,m) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
    z[y[i]].push_back(x[i]);
  }

  rep(i,w) {
    z[i].push_back(h);
  }
  vl yoko(h, w);
  vl tate(w, h);
  rep(i,m) {
    chmin(yoko[x[i]], y[i]);
    chmin(tate[y[i]], x[i]);
  }

  ll res = 0;
  rep(i,tate[0]) {
    res += yoko[i];
  }
  rep(i,yoko[0]) {
    res += tate[i];
  }  

  //  cout << res << "\n";
  auto f = [&](ll a,ll b){ return a+b;}; // 二項演算:和
  ll id = 0; //単位元:0
  SegTree<decltype(f),ll> seg(f,id);
  seg.init(h);
  rep(i,w) sort(z[i].begin(), z[i].end());
  
  vi tab(tate[0], 1);
  res -= tate[0];
  rep1(i,w-1) {
    ll buf = 0;
    res -= min(z[i][0], tate[0]) - seg.query(0, min(tate[0], z[i][0]));
    rep(j,sz(z[i])) {
      ll tmp = z[i][j];
      if(0 <= tmp && tmp < tate[0] && tab[tmp] == 1) {
	tab[tmp] = 0;
	seg.add(tmp, 1);
      }
    }
  }
  cout << res << "\n";
  return 0;
}
