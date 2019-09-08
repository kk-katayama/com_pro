#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int inf = 1e+9;
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
int n,q;
vector<int> a;
vector<int> com,l,r;
map<int,int> mp;
int main()
{
  cin >> n >> q;
  a.resize(n);
  rep(i,n){
    cin >> a[i];
    mp[a[i]] = i+1;
  }
  com.resize(q);
  l.resize(q);
  r.resize(q);
  rep(i,q){
    cin >> com[i] >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }

  
  RMQ<int> rmq(n,inf);
  rep(i,n) rmq.update(i,a[i]);
  
  rep(i,q){
    if(com[i] == 1){
      int left = rmq.dat[l[i]+rmq.n-1],right = rmq.dat[r[i]+rmq.n-1];
      rmq.update(l[i],right);
      rmq.update(r[i],left);
      int temp = mp[left];
      mp[left] = mp[right];
      mp[right] = temp;
    }
    else{
      cout << mp[rmq.query(l[i],r[i]+1,0,0,rmq.n)] << "\n";
    }
  }
  
  return 0;
}
