#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
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

vector<ll> compress(vector<ll> a) {
  ll n = a.size();
  vector<ll> vals;
  rep(i,n) vals.push_back(a[i]);

  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  vector<ll> res;
  rep(i,n) {
    ll id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    res.push_back(id);
  }

  return res;
}

int main()
{
  int n;cin >> n;
  ll k;cin >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i] + a[i];

  vector<ll> vec(n+1);
  rep(i,n+1) vec[i] = sum[i] - k*i;
  vec = compress(vec);
  
  auto f = [](ll a, ll b) { return a+b; };
  ll id = 0;
  SegTree<decltype(f),ll> seg(f,id);
  seg.init(n+1);
  ll res = 0;
  rep(i,n+1) {
    res += seg.query(0, vec[i]+1, 0, 0, seg.size);
    seg.update(vec[i], 1);
  }

  cout << res << "\n";
  
  return 0;
}
