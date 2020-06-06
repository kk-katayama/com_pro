#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename T>
struct SegTree{
  using F = function<T(T, T)>;
  T identity;
  F merge; // 二項演算
  int size;
  vector<T> dat;
  
  SegTree(F f,T id):merge(f),identity(id){}

  // initialize (n is number of elements)
  void init(int n){
    size = 1;
    while(size<n) size *= 2;
    dat.resize(size*2-1,identity);
  }

  // initialize 
  void build(vector<T> vec){
    rep(i,vec.size()) dat[size-1+i] = vec[i];
    dfs(0);
  }

  T dfs(int k){
    if(k>=size-1) return dat[k];
    else return dat[k] = merge(dfs(2*k+1),dfs(2*k+2));
  }

  void update(int k,T a){
    k += size - 1;
    dat[k] = a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = merge(dat[2*k+1],dat[2*k+2]);
    }
  }

  // return query for [a,b). (k,l,r) = (0,0,seg.size)
  T query(int a,int b,int k,int l,int r){
    // out of range
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
  int n,q;cin >> n >> q;
  vector<int> c(q);
  vector<ll> x(q),y(q);
  rep(i,q) cin >> c[i] >> x[i] >> y[i];
  auto f = [&](int a,int b){ return min(a,b);};
  ll id = (1LL<<31)-1;
  SegTree<ll> seg(f,id);
  seg.init(n);
  rep(i,q){
    if(c[i]==0) seg.update(x[i],y[i]);
    else cout << seg.query(x[i],y[i]+1,0,0,seg.size) << "\n";
  }
  return 0;
}
