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
  int n; cin >> n;
  vector<int> k(n);
  vector<vector<int>> t(n);
  rep(i,n) {
    cin >> k[i];
    t[i].resize(k[i]);
    rep(j,k[i]) cin >> t[i][j];
    t[i].push_back(0);
    t[i].push_back(0);    
  }
  int m; cin >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];

  using pi = pair<int,int>;
  auto f = [](pi a, pi b)->pi {
	     return (a.first > b.first ? a : b);
	   };
  
  pi id = {0, -1};
  SegTree<decltype(f), pi> seg1(f, id), seg2(f, id);
  seg1.init(n);
  seg2.init(n);
  vector<pi> v1(n), v2(n);
  rep(i,n) v1[i] = {t[i][0], i};
  rep(i,n) v2[i] = {t[i][1], i};
  seg1.build(v1);
  seg2.build(v2);
  
  vector<int> bac1(n, 1), bac2(n, 2);
  rep(i,m) {
    if(a[i] == 1) {
      pi p = seg1.query(0, n, 0, 0, seg1.size);
      int y = p.second;
      cout << p.first << "\n";
      seg1.update(y, {t[y][bac1[y]], y});
      bac1[y]++;
      seg2.update(y, {t[y][bac2[y]], y});
      bac2[y]++;      
    }
    else {
      pi p1 = seg1.query(0, n, 0, 0, seg1.size);
      pi p2 = seg2.query(0, n, 0, 0, seg2.size);      
      int x1 = p1.first, x2 = p2.first, y1 = p1.second, y2 = p2.second;
      if(x1 > x2) {
	cout << x1 << "\n";
	seg1.update(y1, {t[y1][bac1[y1]], y1});
	bac1[y1]++;
	seg2.update(y1, {t[y1][bac2[y1]], y1});
	bac2[y1]++;
      }
      else {
	cout << x2 << "\n";
	bac1[y2] = bac2[y2];
	seg2.update(y2, {t[y2][bac2[y2]], y2});
	bac2[y2]++;	
      }
    }
  }
  
  return 0;
}
