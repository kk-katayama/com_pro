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
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
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
  int n,q; cin >> n >> q;
  vector<int> c(n+1);
  rep1(i,n) cin >> c[i];
  vector<int> l(q),r(q);
  rep(i,q) {
    cin >> l[i] >> r[i];
  }
  using pii = pair<pi, int>;
  vector<pii> vec(q);
  rep(i,q) {
    vec[i] = {{l[i], r[i]}, i};
  }
  sort(vec.begin(), vec.end(), [](pii a, pii b) {
				 return a.F.S < b.F.S;
			       });
  auto f = [&](int a,int b){ return a+b;}; // 二項演算:和
  int id = 0; //単位元:0
  SegTree<decltype(f),int> seg(f,id);
  seg.init(n+1);
  
  vector<int> lastappend(n+1, 0);
  int idx = 0;
  vector<int> res(q);
  rep1(i,n) {
    seg.update(lastappend[c[i]], -1);
    seg.update(i, 1);
    lastappend[c[i]] = i;
    while(idx < q && vec[idx].F.S == i) {
      res[ vec[idx].S ] = seg.query(vec[idx].F.F, vec[idx].F.S + 1, 0, 0, seg.size);
      idx++;
    }
  }
  for(auto val: res) cout << val << "\n";
  
  
  return 0;
}
