#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll n,k;
ll a[210000];
ll cntmtk(ll l,ll r,ll z){ //k以上の要素の個数
  ll lb=l-1,ub=r+1;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(a[mid]>=z) ub=mid;
    else lb=mid;
  }
  return n-ub;
}

ll cntltk(ll l,ll r,ll z){ //k以下の要素の個数
  ll lb=l-1,ub=r+1;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(a[mid]<=z) lb=mid;
    else ub=mid;
  }
  return lb+1;
}

bool C(ll x){
  ll cnt = 0;
  ll cnt2=0;
  rep(i,n){
    if(x>=0){
      if(a[i]>0) cnt += cntltk(0,n-1,x/a[i]);      
      else if(a[i]<0) cnt += cntmtk(0,n-1,x/a[i]);      
      else cnt += n;
    }
    else{
      if(a[i]>0) cnt += cntltk(0,n-1,(x-a[i]+1)/a[i]);      
      else if(a[i]<0) cnt += cntmtk(0,n-1,(x+a[i]+1)/a[i]);      
    }
    if(a[i]*a[i]<=x) cnt2++;
  }
  return (cnt-cnt2)/2>=k;
}
ll upper(ll l,ll r){//条件を満たす中で最小のものを返す
  ll lb=l-1,ub=r+1;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(C(mid)) ub=mid;
    else lb=mid;
  }
  return ub;
}

int main()
{
  cin >> n >> k;
  rep(i,n) cin >> a[i];

  sort(a,a+n);
  
  ll in=-1e+18;
  ll ax=1e+18;;
  cout << upper(in,ax) << "\n";
  
  return 0;
}
