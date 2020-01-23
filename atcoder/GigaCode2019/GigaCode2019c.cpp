#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int d;
  cin >> d;
  vector<ll> a(d);
  rep(i,d){
    cin >> a[i];
  }
  vector<ll> b(d);
  rep(i,d){
    cin >> b[i];
  }

  ll sum=0;
  ll res=1e+10;
  rep(i,d){
    sum+=a[i];
    if(sum>=b[i]){
      res = min(res,b[i]);
    }
  }

  if(res==1e+10) cout << -1 << "\n";
  else cout << res << "\n";
  
  return 0;
}
