#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct DST
{
  int n;
  vector<X> dat,delay;
  X init;

  DST(int _n,X _init)
  {
    n = 1;
    init = _init;
    while(n < _n) n *= 2;
    dat.assign(2*n-1,init);
    delay.assign(2*n-1,init);
  }

  void eval(int k,int l,int r)
  {
    if(delay[k] != init){
      dat[k] = delay[k];
      if(k < n-1){
	delay[2*k+1] = delay[k];
	delay[2*k+2] = delay[k];
      }
      delay[k] = init;
    }
  }
  
  void update(int a,int b,X x,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return ;
    
    if(a<=l&&r<=b){
      delay[k] = x;
      eval(k,l,r);
    }
    else{
      update(a,b,x,2*k+1,l,(l+r)/2);
      update(a,b,x,2*k+2,(l+r)/2,r);
      dat[k] = min(dat[2*k+1],dat[2*k+2]);
    }
  }

  X query(int a,int b,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return init;

    if(a<=l&&r<=b) return dat[k];    
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }
};
int _n,q;
vector<ll> x;
vector<int> com,s,t;
const ll INF = (ll)(1<<30)*2-1;
int main()
{
  cin >> _n >> q;
  x.resize(q);
  com.resize(q);
  s.resize(q);
  t.resize(q);
  rep(i,q){
    cin >> com[i] >> s[i] >> t[i];
    if(com[i] == 0) cin >> x[i];
  }
  
  DST<ll> dst(_n,INF);

  rep(i,q){
    if(com[i] == 0){
      dst.update(s[i],t[i]+1,x[i],0,0,dst.n);
    }
    else{
      cout << dst.query(s[i],t[i]+1,0,0,dst.n) << "\n";
    }    
  }
  return 0;
}
