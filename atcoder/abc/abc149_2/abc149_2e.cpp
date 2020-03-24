#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
ll n,m;
ll a[110000];
ll cntmtk(ll k){
  ll lb=-1,ub=n;
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    if(a[mid]>=k) ub=mid;
    else lb=mid;
  }
  return n-ub;
}

int main()
{
  cin >> n >> m;
  rep(i,n) cin >> a[i];
  sort(a,a+n);
  ll lb = -1,ub = 2e+5+10;
  while(ub-lb>1){
    ll mid = (lb+ub)/2;
    ll cnt = 0;
    rep(i,n) cnt += cntmtk(mid-a[i]);
    if(cnt>=m) lb = mid;
    else ub = mid;
  }
  ll x = lb;
  ll mm = 0;
  rep(i,n) mm += cntmtk(x-a[i]);
  
  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i] + a[i];
  ll res = 0;
  rep(i,n){
    ll j = cntmtk(x-a[i]);
    res += sum[n] - sum[n-j] + a[i]*j;
  }
  res -= (mm-m)*x;
  cout << res << "\n";
  
  return 0;
}
