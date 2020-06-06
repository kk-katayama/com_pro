#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
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
  int t;cin >> t;
  vector<int> n(t), k(t);
  vector<vector<int>> a(t);
  rep(i,t) {
    cin >> n[i] >> k[i];
    a[i].resize(n[i]);
    rep(j,n[i]) {
      cin >> a[i][j];
    }
  }

  auto f = [](int x,int y){ return min(x,y); }; // RMinQ
  int id = 1e+9;
  

  rep(i,t) {
    if(n[i] == 1 && a[i][0] == k[i]) {
      cout << "yes" << "\n";
      continue;
    }

    vector<int> sum(n[i]+1); // cumulative sum
    sum[0] = 0;
    rep(j,n[i]) {
      if(a[i][j] >= k[i]) sum[j+1] = sum[j] + 1;
      else sum[j+1] = sum[j] - 1;
    }
    SegTree<decltype(f),int> seg(f, id);
    seg.init(n[i]+2);
    seg.build(sum);
    int lim = 0;
    bool flag = false;
    bool ink = false; // is there k ? 
    rep(j,n[i]) {
      if(a[i][j] >= k[i]) lim = j+1;
      if(a[i][j] == k[i]) ink = true;
      if(lim > 0) {
	int mini = (a[i][j] >= k[i] ? seg.query(0, lim-1, 0, 0, seg.size) : seg.query(0, lim, 0, 0, seg.size));
	if(sum[j+1] > mini) flag = true;
      }
    }
    if(flag && ink) cout << "yes" << "\n";
    else cout << "no" << "\n";
  }


  
  return 0;
}
