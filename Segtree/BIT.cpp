#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template <typename X>
struct BIT
{
  vector<X> dat;
  int n;

  BIT(int _n){
    n = _n+1;
    dat.assign(n,0);
  }
  
  X sum(int i)
  {
    X s = 0;
    while(i > 0){
      s += dat[i];
      i -= i&(-i);
    }
    return s;
  }

  void add(int i,X x)
  {
    while(i<=n){
      dat[i] += x;
      i += i&(-i);
    }
  }
};
int _n,q;
int a[100010];
int com[100010],x[100010],y[100010];
int main()
{
  cin >> _n >> q;
  rep(i,_n) cin >> a[i];
  rep(i,q) cin >> com[i] >> x[i] >> y[i];

  BIT<int> b(_n);

  rep(i,_n) b.add(i+1,a[i]);

  rep(i,q){
    if(com[i]==1){
      cout << b.sum(y[i]) - b.sum(x[i]-1)  << "\n";
    }
    else b.add(x[i],y[i]);
  }
  
  return 0;
}
