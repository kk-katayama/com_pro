#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
const int inf = 1e+8;
template <typename X>
struct RMinQ{
  vector<X> dat;
  int n;
  X init;
  
  RMinQ(int _n,X _init)
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

template <typename X>
struct RMaxQ{
  vector<X> dat;
  int n;
  X init;
  
  RMaxQ(int _n,X _init)
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

int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i,n) cin >> p[i];

  vector<int> rle(0);
  int cnt = 1;
  rep(i,n-1){
    if(p[i]<p[i+1]) cnt++;
    else{
      rle.push_back(cnt);
      cnt = 1;
    }
  }
  rle.push_back(cnt);

  vector<int> len(0);
  rep(i,rle.size()){
    while(rle[i]>0){
      len.push_back(rle[i]);
      rle[i]--;
    }
  }
  
  RMinQ<int> rminq(n,inf);
  RMaxQ<int> rmaxq(n,-1);

  bool f = false;
  if(len[n-k]>=k) f = true;  
  
  rep(i,n){
    rminq.update(i,p[i]);
    rmaxq.update(i,p[i]);    
  }

  int res = 1;
  rep(i,n-k){
    if(len[i]>=k){
      if(!f){
	res++;
	f = true;
      }
      continue;
    }
    int in = rminq.query(i,i+k,0,0,rminq.n);
    int ax = rmaxq.query(i+1,i+k+1,0,0,rmaxq.n);
    if(!(in==p[i]&&ax==p[i+k])) res++;
  }

  cout << res << "\n";
  return 0;
}
