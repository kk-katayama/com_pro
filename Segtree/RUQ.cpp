#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll INF = (ll)(1<<30)*2 - 1;
template <typename X>
struct RUQ
{
  int n;
  vector<X> dat,delay;
  X init;

  RUQ(int _n)
  {
    n = 1;
    while(n < _n) n *= 2;
    dat.assign(2*n-1,INF);
    delay.assign(2*n-1,INF);
  }

  void eval(int k,int l,int r)
  {
    if(delay[k] != INF){
      dat[k] = delay[k];
      if(k < n-1){
	delay[2*k+1] = delay[k];
	delay[2*k+2] = delay[k];
      }
      delay[k] = INF;
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
    }
  }

  X query(int k)
  {
    k += n - 1;
    return dat[k];
  }
};
int _n,q;
vector<ll> x;
vector<int> com,k,s,t;
int main()
{
  cin >> _n >> q;
  x.resize(q);
  com.resize(q);    
  k.resize(q);  
  s.resize(q);
  t.resize(q);

  rep(i,q){
    cin >> com[i];
    if(com[i] == 0) cin >> s[i] >> t[i] >> x[i];
    else cin >> k[i];
  }

  RUQ<ll> ruq(_n);

  rep(i,q){
    if(com[i] == 0){
      ruq.update(s[i],t[i]+1,x[i],0,0,ruq.n);
    }
    else{
      cout << ruq.query(k[i]) << "\n"; 
    }
  }    
  return 0;
}
