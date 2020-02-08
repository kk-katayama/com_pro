#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
bool comp(pair<int,int> &a,pair<int,int> &b){
  if(a.first==b.first) return a.second>b.second;
  else return a.first<b.first;
}

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
  int wax =0;
  rep(i,n){
    int h,w;
    cin >> h >> w;
    p[i] = {h,w};
    wax = max(wax,w);
  }

  sort(p.begin(), p.end(),comp);
  vector<int> dp(n,0);
  RMQ<int> rmq(wax+1,0);
  rep(i,n){
    int mx = rmq.query(0,p[i].second,0,0,rmq.n);
    dp[i] = mx + 1;
    rmq.update(p[i].second,dp[i]);
  }

  int res = 0;
  rep(i,n){
    res = max(res,dp[i]);
  }

  cout << res << "\n";
  
  return 0;
}
