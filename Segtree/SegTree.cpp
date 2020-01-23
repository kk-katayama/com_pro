#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
template <typename X>
class SegTree{//segmentation tree
private:
  vector<X> dat;
  int n;
  const X init = (ll)(1<<30)*2-1;
  
public:  
  SegTree(int _n)
  {
    n = 1;
    while(n < _n) n *= 2;
    dat.assign(2*n-1,init);
  }
  
  void update(int k,X a)
  {
    k += n - 1;
    dat[k] = a;
    while(k > 0){
      k = (k - 1)/2;
      dat[k] = min(dat[2*k+1],dat[2*k+2]);         //Range Minimum Query
      //      dat[k] = max(dat[2*k+1],dat[2*k+2]);        //Range Maximum Query      
    }
  }
 
  X query(int a,int b,int k,int l,int r) // query of segment [a,b), (k,l,r)=(0,0,size())
  {
    if(r<=a||b<=l) return init;

    if(a<=l&&r<=b) return dat[k];
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return min(vl,vr);  // Range Minimum Query
      //      return max(vl,vr);  // Range Maximum Query      
    }
  }

  int size(){
    return n;
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

  SegTree<ll> r(_n);

  rep(i,q){
    if(com[i]){
      ll res = r.query(x[i],y[i]+1,0,0,r.size());      
      cout << res << "\n";
    }
    else r.update(x[i],(ll)y[i]);
  }

  
  return 0;
}
