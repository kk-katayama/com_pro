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
  int n; cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  auto f = [&](int a,int b){ return max(a, b);}; // 二項演算:和
  int id = -inf; //単位元:0
  SegTree<decltype(f),int> seg(f,id), seg2(f,id);
  seg.init(n+2);
  seg2.init(n+2);  
  vi sum(n+2, 0), sum2(n+2, 0);
  rep(i,n) {
    sum[i+1] = sum[i] + a[i];
  }
  for (int i = n+1; i - 2 >= 0; --i) {
    sum2[i-1] = sum2[i] + a[i-2];
  }

  // rep(i,n+2) cout << sum[i] << " ";
  // cout  << "\n";
  // rep(i,n+2) cout << sum2[i] << " ";
  // cout  << "\n";  

  sum[0] = sum[n+1] = sum2[0] = sum2[n+1] = -inf;
  
  seg.build(sum);
  seg2.build(sum2);

  vector<pi> p(n);
  rep(i,n) {
    p[i] = {a[i], i+1};
  }

  sort(p.begin(), p.end(), [](pi a, pi b){
    return a.first > b.first;
  });

  set<int> st;
  st.insert(0);
  st.insert(n+1);
  int res = 0;
  rep(i,n) {
    int piv = p[i].second;
    st.insert(piv);
    auto it = st.find(piv);
    it++;
    int r = *it;
    it--; it--;
    int l = *it;
    int tmp = max(0, seg.query(piv, r) - sum[piv]) + max(0 ,seg2.query(l+1, piv+1) - sum2[piv]);
    //    cout << p[i].first << ":" << tmp << "\n";
    chmax(res, tmp);
  }
  cout << res << "\n";
  
  return 0;
}
