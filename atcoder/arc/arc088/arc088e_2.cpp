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
#define rep(i,n) for(ll i = 0; i < n; ++i)
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
  string s; cin >> s;
  ll n = sz(s);
  vi fre(26, 0);
  rep(i,n) {
    int c = int(s[i] - 'a');
    fre[c]++;
  }

  int odd = 0;
  rep(i,26) {
    if(fre[i] % 2 == 1) odd++;
  }
  if(odd >= 2 || (odd == 1 && n % 2 == 0)) {
    cout << -1 << "\n";
    return 0;
  }

  vi cnt(26, 0);
  vl A,B,C;
  rep(i,n) {
    int c = int(s[i] - 'a');
    cnt[c]++;
    if(fre[c] % 2 == 0) {
      if(cnt[c] <= fre[c] / 2) A.push_back(i);
      else C.push_back(i);
    }
    else {
      if((fre[c]+1)/2 == cnt[c]) B.push_back(i);
      else if(cnt[c] <= fre[c] / 2) A.push_back(i);
      else C.push_back(i);      
    }
  }

  ll res = 0;
  rep(i,sz(A)) {
    res += (ll)abs(A[i] - i);
  }
  ll bot = (n+1)/2;
  rep(i,sz(C)) {
    res += (ll)abs(C[i] - (bot+i));
  }
  if(sz(B) == 1) {
    res += (ll)abs(n/2 - B[0]);
  }

  res /= 2;
  
  map<char,queue<int>> mp;
  rep(i,sz(A)) {
    mp[s[A[i]]].push(i);
  }
  vi vec;
  reverse(C.begin(), C.end());
  rep(i,sz(C)) {
    int tmp = mp[s[C[i]]].front();
    mp[s[C[i]]].pop();
    vec.push_back(tmp);
  }

  auto f = [&](ll a,ll b){ return a+b;}; // 二項演算:和
  ll id = 0; //単位元:0
  SegTree<decltype(f),ll> seg(f,id);  
  seg.init(sz(vec)+1);
  rep(i,sz(vec)) {
    ll tmp = i - seg.query(0, vec[i]);
    res += tmp;
    seg.add(vec[i], 1);
  }
  cout << res << "\n";
  
  return 0;
}
