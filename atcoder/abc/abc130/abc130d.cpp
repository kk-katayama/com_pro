#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll s=0,t=0;
  ll sum=a[0],res=0;
  while(s<n&&t<n){
    if(sum>=k){
      res += n-t;
      if(s==t){ s++;t++;sum=a[t]; }
      else{ sum-=a[s];s++; }
    }
    else{
      t++;sum+=a[t];
    }
  }
  cout << res << "\n";
  
  return 0;
}
