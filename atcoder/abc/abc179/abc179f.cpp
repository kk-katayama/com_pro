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
// 区間更新、区間最小クエリ
template <typename F,typename T>
struct DST{
  T identity;
  F merge;
  int size;
  vector<T> dat,delay;
  
  DST(F f,T id):merge(f),identity(id){}

  void eval(int k,int l,int r){
    if(delay[k] != infll){
      chmin(dat[k], delay[k]);
      if(k<size-1){
	chmin(delay[2*k+1], delay[k]);
	chmin(delay[2*k+2], delay[k]);
      }
      delay[k]=infll;
    }
  }

  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1,identity);
    delay.resize(size*2-1,infll);    
  }

  void build(vector<T> vec){
    rep(i,vec.size()) dat[size-1+i] = vec[i];
    dfs(0);
  }

  T dfs(int k){
    if(k>=size-1) return dat[k];
    else return dat[k] = merge(dfs(2*k+1),dfs(2*k+2));
  }

  void update(int a,int b,T x,int k,int l,int r){
    eval(k,l,r);

    if(r<=a||b<=l) return ;
    if(a<=l&&r<=b){
      delay[k] = x;
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      dat[k] = merge(dat[2*k+1],dat[2*k+2]);
    }
  }

  T query(int a,int b,int k,int l,int r){
    eval(k,l,r);
    if(r<=a||b<=l) return identity;

    if(a<=l&&r<=b) return dat[k];
    else return merge(query(a,b,2*k+1,l,(l+r)/2),query(a,b,2*k+2,(l+r)/2,r));
  }

  void all_eval(){
    rep(i,2*size-1){
      eval(i,0,0);
    }
  }

  T get(int k){ return dat[size-1+k];}
  
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
    index = 0;
    num = 1;
    while(index<size){
      rep(i,num){
	cout << delay[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
  }
  

  
};

int main()
{
  ll n,q; cin >> n >> q;
  ll res = (n-2)*(n-2);
  auto f = [&](ll a,ll b){ return min(a,b);};
  ll id = infll;
  DST<decltype(f),ll> dst(f,id), dst2(f,id);
  dst.init(n);
  dst2.init(n);  
  vl tmp(n, n-1);
  dst.build(tmp);
  dst2.build(tmp);
  
  while(q-- > 0) {
    ll t,x; cin >> t >> x;
    if(t == 1) {
      ll m = dst.query(x-1, x, 0, 0, dst.size);
      res -= (m - 1);
      dst2.update(0, m, x-1, 0, 0, dst2.size);
    }
    if(t == 2) {
      ll m = dst2.query(x-1, x, 0, 0, dst2.size);
      res -= (m - 1);
      dst.update(0, m, x-1, 0, 0, dst.size);
    }
  }
  cout << res << "\n";
  
  return 0;
}
