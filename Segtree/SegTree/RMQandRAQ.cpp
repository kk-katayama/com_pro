#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll INF = (ll)(1<<30)*2 - 1;
template <typename X>
struct DST
{
  int n;
  vector<X> dat,delay;
  X init;
  vector<bool> flag;

  DST(int _n)
  {
    n = 1;
    while(n < _n) n *= 2;
    dat.assign(2*n-1,INF);
    delay.assign(2*n-1,0);
    flag.assign(2*n-1,0);
  }

  void eval(int k,int l,int r)
  {
    if(flag[k]){
      dat[k] += delay[k];
      if(k < n-1){
	delay[2*k+1] += delay[k];
	delay[2*k+2] += delay[k];
	flag[2*k+1] = true;
	flag[2*k+2] = true;
      }
      delay[k] = 0;
      flag[k] = false;
    }
  }
  
  void update(int a,int b,X x,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return ;
    
    if(a<=l&&r<=b){
      delay[k] += x;
      flag[k] = true;
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
    
    if(r<=a||b<=l) return INF;

    if(a<=l&&r<=b) return dat[k];    
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return min(vl,vr);
    }
  }
};
int _n,q;
vector<int> com,s,t;
vector<ll> x;
int main()
{
  cin >> _n >> q;
  com.resize(q);
  s.resize(q);
  t.resize(q);
  x.resize(q);

  rep(i,q){
    cin >> com[i] >> s[i] >> t[i];
    if(com[i] == 0) cin >> x[i];
  }
  
  DST<ll> dst(_n);

  dst.update(0,_n,-INF,0,0,dst.n);
  /*
  rep(j,dst.n*2-1){
    cout << dst.dat[j] << " ";
  }
  cout << "\n";
  rep(j,dst.n*2-1){
    cout << dst.delay[j] << " ";
  }
  cout << "\n";
  rep(j,dst.n*2-1){
    cout << dst.flag[j] << " ";
  }
  cout << "\n";
  */
  
  rep(i,q){
    if(com[i] == 0){
      dst.update(s[i],t[i]+1,x[i],0,0,dst.n);
    }
    else{
      cout << dst.query(s[i],t[i]+1,0,0,dst.n) << "\n";
    }
    /*
    rep(j,dst.n*2-1){
      cout << dst.dat[j] << " ";
    }
    cout << "\n";
    rep(j,dst.n*2-1){
      cout << dst.delay[j] << " ";
    }
    cout << "\n";
    */
  }
  return 0;
}
