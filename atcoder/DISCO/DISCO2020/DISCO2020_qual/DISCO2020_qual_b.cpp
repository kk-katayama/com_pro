#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum=0;
  rep(i,n){
    cin >> a[i];
    sum+=a[i];
  }
  
  ll res=1e+15;
  ll tmp=0;
  rep(i,n){
    res = min(res,abs(sum-2*tmp));
    tmp += a[i];
  }
  
  cout << res << "\n";
  
  return 0;
}
