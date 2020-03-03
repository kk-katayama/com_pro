#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct RMQ{
  int n;
  vector<X> dat;
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
      dat[k] = max(dat[2*k+1],dat[2*k+2]);
    }
  }

  X query(int a,int b,int k,int l,int r)
  {
    if(r<=a||b<=l) return init;

    if(a<=l&&r<=b) return dat[k];
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);

      return max(vl,vr);
    }
  }
};
int _n,q;
int a[100010];
int com[100010],x[100010],y[100010];
const int MIN = -(1e+9+1); 
int main()
{
  cin >> _n >> q;
  rep(i,_n) cin >> a[i];
  rep(i,q) cin >> com[i] >> x[i] >> y[i];

  RMQ<int> r(_n,MIN);

  rep(i,_n) r.update(i,a[i]);

  rep(i,q){
    if(com[i] == 2) r.update(x[i]-1,y[i]);
    else{
      int res = r.query(x[i]-1,y[i],0,0,r.n);
      cout << res << "\n";
    }
  }
  
  return 0;
}
