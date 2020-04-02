#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
struct mint{
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a){
    if((x+=a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator-=(const mint a){
    if((x += MOD-a.x)>=MOD) x-=MOD;
    return *this;
  }
  mint& operator*=(const mint a){
    (x*=a.x)%=MOD;
    return *this;
  }
  mint operator+(const mint a) const{
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const{
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const{
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const{
    if(!t) return 1;
    mint a = pow(t>>1);
    a*=a;
    if(t&1) a*=*this;
    return a;
  }
  
  //for prime mod
  mint inv() const{
    return pow(MOD-2);
  }
  mint& operator/=(const mint a){
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const{
    mint res(*this);
    return res/=a;
  }
};
const int M = 210000;
mint pow2[M];
void Make_pow2() {
  pow2[0].x = 1;
  rep1(i, M-1) {
    pow2[i] = pow2[i-1] * (mint)2;
  }
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
int n;
int a[M];

//k以上である要素のうち最小のもののインデックスを求める
int upper_bound(int k){
  int left=-1,right=n;
  while(right-left>1){
    int mid=(right+left)/2;
    if(a[mid]>=k) right=mid;
    else left=mid;
  }
  return right;
}


int main()
{
  cin >> n;
  vector<int> x(n),d(n);
  rep(i, n) cin >> x[i] >> d[i];
  Make_pow2();
  vector<pair<int,int>> p(n);
  rep(i, n) {
    p[i] = {x[i], d[i]};
  }
  sort(p.begin(), p.end());
  rep(i,n) a[i] = p[i].first;
  
  auto f = [&](int a, int b) { return max(a, b); };
  int id = -1e+9-10;
  SegTree<decltype(f), int> seg(f, id);
  seg.init(n + 2);
  vector<mint> dp(n+1);
  dp[n].x = 1;
  
  for(int i = n - 1;i >= 0;--i) {
    int kk = p[i].first + p[i].second;
    int index1 = upper_bound(kk);
    int kkk = seg.query(i, index1, 0, 0, seg.size);
    kkk = max(kkk, kk);
    seg.update(i, kkk);
    dp[i] = dp[i+1] + dp[upper_bound(kkk)];
  }
  cout << dp[0].x << "\n";
  
  return 0;
}
