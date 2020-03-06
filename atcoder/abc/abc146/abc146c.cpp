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
  ll a,b,x;cin >> a >> b >> x;
  ll res = 0;
  for (ll i=1; i<=9; ++i) {
    ll y = x - b*i;
    if(y<=0) continue;
    ll z = y/a;
    ll cnt = 0;
    while(z>0){
      cnt++;
      z /= 10;
    }
    if(cnt==i){
      res = max(res,y/a);
    }
    else if(cnt<i) continue;
    else{
      ll w = pow((ll)10,i);
      w--;
      res = max(res,w);
    }
  }

  ll inf = 1e+9;
  if(inf*a+9*b<=x) cout << inf << "\n";
  else cout << res << "\n";
  
  return 0;
}
