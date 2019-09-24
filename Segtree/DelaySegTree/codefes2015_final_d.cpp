#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int inf = 1e+9;
template <typename X>
struct DST
{
  int n;
  vector<X> dat,delay;
  vector<bool> flag;
  
  DST(int _n)
  {
    n = 1;
    while(n < _n) n *= 2;
    dat.assign(2*n-1,0);
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
      flag[k] = false;
      delay[k] = 0;
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
      dat[k] = max(dat[2*k+1],dat[2*k+2]);
    }
  }

  X query(int a,int b,int k,int l,int r)
  {
    eval(k,l,r);
    
    if(r<=a||b<=l) return 0;

    if(a<=l&&r<=b) return dat[k];    
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return max(vl,vr);
    }
  }
};
int _n;
vector<int> s,t;
int main()
{
  cin >> _n;
  s.resize(_n);
  t.resize(_n);
  int tmax = 0;
  rep(i,_n){
    cin >> s[i] >> t[i];
    tmax = max(tmax,t[i]);
  }

  DST<int> dst(tmax);

  rep(i,_n){
    dst.update(s[i]-1,t[i]-1,1,0,0,dst.n);
  }
  
  int res = inf;
  
  rep(i,_n){
    dst.update(s[i]-1,t[i]-1,-1,0,0,dst.n);
    res = min(res,dst.query(0,dst.n,0,0,dst.n));
    dst.update(s[i]-1,t[i]-1,1,0,0,dst.n);
  }
  
  cout << res << "\n";
  
  return 0;
}
