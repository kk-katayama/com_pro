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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
// 区間加算、区間最小クエリ
template <typename F,typename T>
struct DST{
  T identity;
  F merge;
  int size;
  vector<T> dat,delay,delay2,delay3;
  
  DST(F f,T id):merge(f),identity(id){}

  void eval(int k,int l,int r){
    if(delay[k] != 0){
      dat[k] = delay2[k];
      dat[k] += delay3[k];
      dat[k] += delay[k];
      if(k<size-1){
	delay2[2*k+1] = delay2[k];
	delay2[2*k+2] = delay2[k];	
	delay[2*k+1] += delay[k];
	delay[2*k+2] += delay[k];
	delay3[2*k+1] += delay3[k];
	delay3[2*k+2] += delay3[k];		
      }
      delay[k]=0;
      delay2[k]=0;
      delay3[k]=0;      
    }
  }

  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1,identity);
    delay.resize(size*2-1,0);
    delay2.resize(size*2-1,0);
    delay3.resize(size*2-1,0);        
  }

  void build(vector<T> vec){
    rep(i,vec.size()) dat[size-1+i] = vec[i];
    dfs(0);
  }

  T dfs(int k){
    if(k>=size-1) return dat[k];
    else return dat[k] = merge(dfs(2*k+1),dfs(2*k+2));
  }

  void update(int a,int b,T x,int k,int l,int r,int f){
    eval(k,l,r);

    if(r<=a||b<=l) return ;
    if(a<=l&&r<=b){
      if(f == 1) delay[k] += x;
      else if(f == 2) delay2[k] = x;
      else if(f == 3) delay3[k] += x;
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2,f);
      update(a,b,x,2*k+2,(l+r)/2,r,f);
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
    cout << "************************\n";
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
    cout << "************************\n";      
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
  ll id = (1LL<<60);
  DST<decltype(f),ll> dst(f,id);
  dst.init(n);
  vector<ll> vec(n,0);
  dst.build(vec);
  rep(i,q){
    if(c[i]==0) dst.update(s[i],t[i]+1,x[i],0,0,dst.size);
    else cout << dst.query(s[i],t[i]+1,0,0,dst.size) << "\n";
    //    dst.show();
  }
  
  return 0;
}

int main()
{
  int h,w; cin >> h >> w;
  vector<int> a(n), b(n);
  rep(i,h) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  auto f = [&](int a,int b){ return min(a,b);};
  int id = 1e+9;
  DST<decltype(f),int> dst(f,id);
  dst.init(n);

  rep(i,h) {
    dst.update(0, a[i], 1, 0, 0, dst.size, 1);
  }
  
  return 0;
}
