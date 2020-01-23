#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct RMQ{
  vector<X> dat;
  int n;
  X init;
  
  RMQ(int _n,X _init)
  {
    n = 1;
    init = _init;
    while(n < _n) n *= 2;
    dat.resize(2*n-1);
    rep(i,2*n-1){
      dat[i] = init;
    }
  }
  
  void update(int k,X a)
  {
    k += n - 1;
    dat[k] = a;
    while(k > 0){
      k = (k - 1)/2;
      dat[k] = (dat[2*k+1]+dat[2*k+2])%3;
    }
  }
  
  X query(int a,int b,int k,int l,int r)
  {
    if(r<=a||b<=l) return init;

    if(a<=l&&r<=b) return dat[k];
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return (vl+vr)%3;
    }
  }
};


int main()
{
  string s,t;
  cin >> s >> t;
  int q;
  cin >> q;
  vector<int> a(q),b(q),c(q),d(q);
  rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
  rep(i,q){
    a[i]--;
    b[i]--;
    c[i]--;
    d[i]--;
  }
  
  RMQ<int> rmqs(s.size(),0);
  RMQ<int> rmqt(t.size(),0);  

  rep(i,s.size()){
    rmqs.update(i,(int)(s[i]-'A'+1));
  }

  rep(i,t.size()){
    rmqt.update(i,(int)(t[i]-'A'+1));
  }

  rep(i,q){
    int sn = rmqs.query(a[i],b[i]+1,0,0,rmqs.n);
    int tn = rmqt.query(c[i],d[i]+1,0,0,rmqt.n);    
    if(sn==tn) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }

  
  return 0;
}
