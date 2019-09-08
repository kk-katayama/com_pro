#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
struct RCQ{
  vector<X> dif;
  vector<X> dat;
  int n;

  RCQ(int _n)
  {
    n = 1;
    while(n<_n) n*=2;
    dif.assign(2*n-1,0);
    dat.assign(2*n-1,0);
  }

  void update(int k,X y)
  {
    k += n-1;
    dif[k] += y;
    if(dif[k] == 0) dat[k] = 0;
    else dat[k] = 1;
    while(k>0){
      k = (k-1)/2;
      dat[k] = dat[2*k+1] + dat[2*k+2];
    }
  }

  X query(int a,int b,int k,int l,int r){
    if(r<=a||b<=l) return 0;

    if(a<=l&&r<=b) return dat[k];
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return vl+vr;
    }
  }
  
};
int _n,q;
vector<ll> a,x;
vector<int> com,l,r; 
int main()
{
  cin >> _n >> q;
  a.resize(_n);
  rep(i,_n) cin >> a[i];
  com.resize(q);
  l.resize(q);
  r.resize(q);
  x.resize(q);    
  rep(i,q){
    cin >> com[i] >> l[i] >> r[i];
    l[i]--;r[i]--;
    if(com[i] == 1) cin >> x[i];
  }
  
  RCQ<ll> rcq(_n-1);
  rep(i,_n-1){
    ll y = a[i+1]-a[i];
    rcq.update(i,y);
  }
  
  rep(i,q){
    if(com[i]==1){
      if(l[i]!=0){
	rcq.update(l[i]-1,x[i]);
      }
      if(r[i]!=_n-1){
	rcq.update(r[i],-x[i]);
      }
    }
    else{
      cout << rcq.query(l[i],r[i],0,0,rcq.n)+1 << "\n";
    }
  }  
  return 0;
}
