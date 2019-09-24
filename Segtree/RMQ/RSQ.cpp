#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct RSQ{
  int n;
  vector<X> dat;
  
  RSQ(int _n)
  {
    n = 1;
    while(n < _n) n*=2;
    dat.assign(n,0);
  }
  
  void update(int k,X a)
  {
    k += n - 1;
    dat[k] += a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] += a;
    }
  }
  
  X query(int a,int b,int k,int l,int r)
  {
    if(r<=a||b<=l) return 0;
    
    if(a<=l&&r<=b) return dat[k];
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);

      return vl + vr;
    }
  }
};
int _n,q;
int com[100010],x[100010],y[100010];
int main()
{
  cin >> _n >> q;
  rep(i,q) cin >> com[i] >> x[i] >> y[i];

  RSQ<int> st(_n);

  rep(i,q){
    if(com[i]==1){
      cout << st.query(x[i]-1,y[i],0,0,st.n) << "\n";
    }
    else st.update(x[i]-1,y[i]);
  }
  
  return 0;
}
