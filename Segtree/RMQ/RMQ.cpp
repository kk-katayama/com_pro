#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
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
      dat[k] = min(dat[2*k+1],dat[2*k+2]);
    }
  }
  
  X query(int a,int b,int k,int l,int r)
  {
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
bool com[100010];
int x[100010],y[100010];
const ll AMAX = (ll)(1<<30)*2 - 1;
int main()
{
  cin >> _n >> q;
  rep(i,q) cin >> com[i] >> x[i] >> y[i];

  RMQ<ll> r(_n,AMAX);

  rep(i,q){
    if(com[i]){
      ll res = r.query(x[i],y[i]+1,0,0,r.n);
      cout << res << "\n";
    }
    else r.update(x[i],(ll)y[i]);
  }

  
  return 0;
}
