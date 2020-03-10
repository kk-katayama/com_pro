#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,p,q;cin >> n >> p >> q;
  vector<ll> a(n);rep(i,n) cin >> a[i];
  if(p%2!=q%2){
    cout << 0 << "\n";
    return 0;
  }
  map<ll,ll> mp1,mp2;
  ll x = (p+q)/2;
  rep(i,n) mp1[a[i]]++;
  ll res = 0;
  rep(i,n){
    ll tmp=mp2[x];
    mp2[a[i]]++;mp1[a[i]]--;
    ll z = (p-q)/2-a[i];
    tmp *= mp1[z];
    res += tmp;
  }
  cout << res << "\n";
  return 0;
}
