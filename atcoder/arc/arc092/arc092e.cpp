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
      dat[k] = dat[2*k+1]+dat[2*k+2];
    }
  }
  
  X query(int a,int b,int k,int l,int r)
  {
    if(r<=a||b<=l) return init;

    if(a<=l&&r<=b) return dat[k];
    else{
      X vl = query(a,b,2*k+1,l,(l+r)/2);
      X vr = query(a,b,2*k+2,(l+r)/2,r);
      return vl+vr;
    }
  }
};


int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }

  int s1,s2;
  if(n%2==0){
    s1 = n/2;
    s2 = n/2;
  }
  else{
    s1 = (n+1)/2;
    s2 = n/2;
  }  
  RMQ<ll> st1(s1,0);
  RMQ<ll> st2(s2,0);  
  rep(i,n){
    if(i%2==0){
      st1.update(i/2,a[i]);
    }
    else{
      st2.update(i/2,a[i]);      
    }
  }

  int l1,r1;
  ll res1 = -(1LL<<60);
  rep(i,s1){
    rep1(j,s1){
      if(i>=j) continue;
      ll x = st1.query(i,j,0,0,st1.n);
      if(x>res1){
	res1 = x;
	l1 = i;
	r1 = j;
      }
    }
  }

  int l2,r2;
  ll res2 = -(1LL<<60);
  rep(i,s2){
    rep1(j,s2){
      if(i>=j) continue;
      ll x = st2.query(i,j,0,0,st2.n);
      if(x>res2){
	res2 = x;
	l2 = i;
	r2 = j;
      }
    }
  }

  if(res1>res2){
    vector<int> res;
    for(int i=n;i>=r1*2;--i){
      res.push_back(i);
    }
    rep(i,l1*2){
      res.push_back(1);
    }
    rep(i,r1-l1-1){
      res.push_back(2);
    }
    cout << res1 << "\n";
    cout << (int)res.size() << "\n";
    rep(i,res.size()){
      cout << res[i] << "\n";
    }
  }
  else{
    vector<int> res;
    for(int i=n;i>r2*2;--i){
      res.push_back(i);
    }
    rep(i,l2*2+1){
      res.push_back(1);
    }
    rep(i,r2-l2-1){
      res.push_back(2);
    }
    cout << res2 << "\n";    
    cout << (int)res.size() << "\n";
    rep(i,res.size()){
      cout << res[i] << "\n";
    }    
  }
  
  return 0;
}
