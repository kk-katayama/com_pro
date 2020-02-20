#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }

  rep(i,n){
    ll x = (a[i]-b[i])/(b[i]+1);
    ll y = (a[i]-b[i])%(b[i]+1);
    ll res = (x+1)*(x+2)/2*y + x*(x+1)/2*(b[i]+1-y);
    cout << a[i]*(a[i]+1)/2 - res << "\n";
  }
  
  return 0;
}
