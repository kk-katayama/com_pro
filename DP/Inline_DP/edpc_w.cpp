#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
// 区間加算、区間最大クエリ
template <typename F,typename T>
struct DST{
  T identity;
  F merge;
  int size;
  vector<T> dat,delay;
  
  DST(F f,T id):merge(f),identity(id){}

  void eval(int k,int l,int r){
    if(delay[k] != 0){
      dat[k] += delay[k];
      if(k<size-1){
	delay[2*k+1] += delay[k];
	delay[2*k+2] += delay[k];	
      }
      delay[k]=0;
    }
  }

  void init(int n){
    size = 1;
    while(size<=n) size *= 2;
    dat.resize(size*2-1,identity);
    delay.resize(size*2-1,0);    
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
      delay[k] += x;
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
  int n,m; cin >> n >> m;
  vector<int> l(m), r(m);
  vector<ll> a(m);
  rep(i,m) {
    cin >> l[i] >> r[i] >> a[i];
    //    l[i]--;
  }

  auto f = [&](ll a,ll b){ return max(a,b);};
  ll id = 0;
  DST<decltype(f),ll> dst(f,id);
  dst.init(n);
  
  vector<vector<pair<int,ll>>> p(n+1);
  rep(i,m) {
    p[r[i]].push_back({l[i], a[i]});
  }

  rep1(i,n) {
    ll x = dst.query(0, i, 0, 0, dst.size);
    ll sum = 0;
    for(auto j: p[i]) {
      int left = j.first;
      ll aa = j.second;
      sum += aa;
      dst.update(left, i, aa, 0, 0, dst.size);
    }
    dst.update(i, i+1, x+sum, 0, 0, dst.size);
  }

  ll res = 0;
  chmax(res, dst.query(0, dst.size, 0, 0, dst.size));
  cout << res << "\n";
  
  return 0;
}

