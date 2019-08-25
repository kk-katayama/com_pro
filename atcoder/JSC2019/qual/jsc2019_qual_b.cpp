#include <iostream>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
const ll MOD = 1e+9+7;
int n;
ll k;
int a[2010];
int main()
{
  cin >> n >> k;
  rep(i,n) cin >> a[i];

  ll res = 0;
  rep(i,n){
    ll cnt1 = 0,cnt2 = 0;
    rep(j,n){
      if(i==j) continue;
      if(i<j&&a[i]>a[j]) cnt1++;
      else if(i>j&&a[i]>a[j]) cnt2++;
    }
    ll x1 = ((k+1)*k/2)%MOD;
    ll x2 = ((k-1)*k/2)%MOD;
    ll y1 = (cnt1*x1)%MOD;
    ll y2 = (cnt2*x2)%MOD;

    res = (res+y1)%MOD;
    res = (res+y2)%MOD;
  }

  cout << res << "\n";
  
  return 0;
}
