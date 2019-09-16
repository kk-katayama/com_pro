#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int k;
  cin >> k;
  vector<ll> a(k);
  rep(i,k) cin >> a[i];
  reverse(a.begin(), a.end());

  bool f = true;
  ll l=2,r=2;
  rep(i,k){
    ll temp = l;
    l = (l+a[i]-1)/a[i]*a[i];
    if(l<temp||r<l){
      f = false;
      break;
    }
    r = r/a[i]*a[i]+a[i]-1;
  }

  if(f) cout << l << " " << r << "\n";
  else cout << -1 << "\n";
  
  return 0;
}
