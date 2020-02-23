#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
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

  void show(){
    int index = 0;
    int num = 1;
    while(index<n){
      rep(i,num){
	cout << dat[i+index] << " ";
      }
      cout << "\n";
      num *= 2;
      index = index*2+1;
    }
  }
  
};
int main()
{
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  int maxl=0,minr=2e+9;
  int ml,mr;
  rep(i,n){
    int l,r;
    cin >> l >> r;
    p[i] = {l,r};
  }
  sort(p.begin(), p.end());
  rep(i,n){
    if(maxl<=p[i].first){
      maxl=p[i].first;ml=i;
    }
    if(p[i].second<=minr){
      minr=p[i].second;mr=i;
    }    
  }
  
  
  int ax = 0;
  rep(i,n){
    if(i==ml||i==mr) continue;
    ax = max(ax,p[i].second-p[i].first+1);
  }
  int res = ax+max(0,minr-maxl+1);
  

  RMQ<int> rmq(n,1e+9+10);
  rep(i,n){
    if(i==ml||i==mr) continue;
    rmq.update(i,p[i].second);
  }
  //  rmq.show();

  rep(i,n-1){
    if(i==ml||i==mr) continue;
    int x = rmq.query(i+1,rmq.n,0,0,rmq.n);
    int tmp;
    if(x==1e+9+10) tmp = max(0,minr-p[i].first+1) + p[ml].second-p[ml].first+1;
    else tmp = max(0,minr-p[i].first+1) + max(0,x-maxl+1);
    res = max(res,tmp);
  }

  cout << res << "\n";
  return 0;
}
