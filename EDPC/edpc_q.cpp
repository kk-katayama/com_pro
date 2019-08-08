#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i = 0 ; i < n ; ++i)
#define rep1(i,n) for(int i = 1 ; i <= n ; ++i)
using namespace std;
typedef long long ll;
const int NMAX = 300010;
/***************RMQ(Range Minimum Query)************/
class RMQ{
public:
  ll dat[NMAX*2-1];
  int nn;
  RMQ(int n_);
  void update(int k,ll a);
  ll query(int a,int b,int k,int l,int r);
};
RMQ::RMQ(int n_){
  nn=1;
  while(nn<n_) nn*=2;
  for(int i = 0 ; i < 2*nn-1 ; ++i){
    dat[i]=0; 
  }
}
void RMQ::update(int k,ll a){
  k+=nn-1;
  dat[k]=a;
  while(k>0){
    k=(k-1)/2;
    dat[k]=max(dat[2*k+1],dat[2*k+2]);
  }
}
ll RMQ::query(int a,int b,int k,int l,int r) {
  if(r<=a||b<=l) return 0;
  if(a<=l&&r<=b) return dat[k];
  else{
    ll v1=query(a,b,2*k+1,l,(l+r)/2);
    ll v2=query(a,b,2*k+2,(l+r)/2,r);
    return max(v1,v2);
  }
}
/********************************************************/
int n;
int h[200010];
ll A[200010];
ll dp[200010];

int main()
{
  cin >> n;
  rep(i,n) cin >> h[i];
  rep(i,n) cin >> A[i];
  
  RMQ r(n+1);
  rep(i,n){
    ll hight = r.query(0,h[i]+1,0,0,r.nn);
    r.update(h[i],dp[h[i]] = hight + A[i]);
    //    rep(i,32) cout << r.dat[i] << " ";
    //    cout  << "\n";
    //    rep(i,n+1) cout << dp[i] << " ";
    //    cout  << "\n";
  }
  
  ll res = r.query(0,n+1,0,0,n+1);
  cout << res << "\n";

  return 0;
}
