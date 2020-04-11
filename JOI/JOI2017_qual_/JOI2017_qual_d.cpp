#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
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
  int n,m;cin >> n >> m;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    a[i]--;
  }

  vector<int> num(m);
  rep(i,n) num[ a[i] ]++;

  auto f = [&](int a, int b){ return a+b;};
  int id = 0;
  vector<SegTree<decltype(f),int>> seg(m, SegTree<decltype(f),int>(f,id));
  rep(i,m) seg[i].init(n);
  rep(i,n) {
    seg[a[i]].update(i,1);
  }

  vector<int> dp( (1 << m), 1e+9);
  dp[0] = 0;
  rep(mask, (1 << m) - 1 ) {
    int left = 0;
    rep(i,m) if( (mask >> i) & 1 ) left += num[i];
    rep(i,m) {
      if( ! ( (mask >> i) & 1) ) {
	int right = left + num[i];
	int cnt = seg[i].query(left, right, 0, 0, seg[i].size);
	dp[mask | (1 << i)] = min(dp[mask | (1 << i)], dp[mask] + num[i] - cnt);
      }
    }
  }

  cout << dp[(1 << m) - 1] << "\n";
  
  return 0;
}







