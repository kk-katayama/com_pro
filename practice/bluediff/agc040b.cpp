#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(pair<int,int> &a, pair<int,int> &b) {
  return a.second < b.second;
}

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
  int n;cin >> n;
  vector<int> l(n), r(n);
  rep(i,n) cin >> l[i] >> r[i];
  vector<pair<int,int>> p(n);
  rep(i,n) p[i] = {l[i], r[i]};
  
  vector<pair<int,int>> lsort(n), rsort(n);
  sort(p.begin(), p.end());

  auto fmax = [&](int a, int b) { return max(a, b); };
  auto fmin = [&](int a, int b) { return min(a, b); };
  int idmax = 0, idmin = 1e+9+10;
  SegTree<decltype(fmax), int> rmaxq(fmax, idmax);
  SegTree<decltype(fmin), int> rminq(fmin, idmin);  
  rmaxq.init(n);
  rminq.init(n);
  
  rep(i,n) {
    lsort[i] = p[i];
    rminq.update(i, p[i].second);
  }

  sort(p.begin(), p.end(), comp);
  rep(i,n) {
    rsort[i] = p[i];
    if( rsort[i] == lsort[n-1] ) continue;
    rmaxq.update(i, p[i].first);
  }

  rep(i,n) {
    if( rsort[0] == lsort[i] ) rminq.update(i, idmin);
  }
  int wid = 0;
  int index = 0;
  rep(i,n) {
    if(wid < p[i].second - p[i].first + 1) {
      wid = p[i].second - p[i].first + 1;
      index = i;
    }
  }

  int res = 0;

  if( p[index] == lsort[n-1] ) {
    int tmp = max(0, rsort[0].second - lsort[n-2].first + 1);
    res = max(res, tmp + wid);
  }
  else if( p[index] == rsort[0] ) {
    int tmp = max(0, rsort[1].second - lsort[n-1].first + 1);
    res = max(res, tmp + wid);    
  }
  else {
    int tmp = max(0, rsort[0].second - lsort[n-1].first + 1);
    res = max(res, tmp + wid);        
  }

  int rmi = lsort[n-1].second;
  for(int i = n - 1;i > 0;--i) {
    if( rsort[i] == lsort[n-1] ) continue;
    rmi = min(rmi, rsort[i].second);
    int rmq = rmaxq.query(0, i, 0, 0, rmaxq.size);
    int tmp = max(0, rmi - lsort[n-1].first + 1) + max(0, rsort[0].second - rmq + 1);
    res = max(res, tmp);

  }

  cout << res << "\n";
  
  return 0;
}
