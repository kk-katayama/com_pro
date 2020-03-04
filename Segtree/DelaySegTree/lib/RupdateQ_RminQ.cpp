#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
// 区間更新、区間最小クエリ
template <typename F,typename T>
struct DST{
  T identity;
  F merge;
  int size;
  vector<T> dat,delay;
  
  DST(F f,T id):merge(f),identity(id){}

  void eval(int k,int l,int r){
    if(delay[k] != -1){
      dat[k] = delay[k];
      if(k<size-1){
	delay[2*k+1] = delay[2*k+2] = delay[k];
      }
      delay[k]=-1;
    }
  }

  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1,identity);
    delay.resize(size*2-1,-1);    
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
  int n,q;cin >> n >> q;
  vector<ll> c(q),s(q),t(q),x(q);
  rep(i,q){
    cin >> c[i];
    if(c[i]==0) cin >> s[i] >> t[i] >> x[i];
    else cin >> s[i] >> t[i];
  }

  auto f = [&](ll a,ll b){ return min(a,b);};
  ll id = (1LL<<31)-1;
  DST<decltype(f),ll> dst(f,id);
  dst.init(n);
  rep(i,q){
    if(c[i]==0) dst.update(s[i],t[i]+1,x[i],0,0,dst.size);
    else cout << dst.query(s[i],t[i]+1,0,0,dst.size) << "\n";
  }
  
  return 0;
}
