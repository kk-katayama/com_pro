#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int n;
ll h[110000],s[110000];
bool ok(ll x){
  vector<ll> v(n);
  rep(i,n){
    if(x-h[i]<0) return false;
    v[i] = (x-h[i])/s[i];
  }
  sort(v.begin(), v.end());
  ll cnt=0;
  bool f = true;
  rep(i,n) if(v[i]<cnt++) f = false;
  return f;
}
ll bins(){
  ll left=-1,right=1e+18;
  while(right-left>1){
    ll mid = (right+left)/2;
    if(ok(mid)) right = mid;
    else left = mid;
  }
  return right;
}
int main()
{
  cin >> n;
  rep(i,n) cin >> h[i] >> s[i];
  cout << bins() << "\n";
  return 0;
}
