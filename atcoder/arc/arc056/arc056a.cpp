#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll a,b,k,l;
  cin >> a >> b >> k >> l;
  ll c = b/l;
  if(c<a){
    ll res = 0;
    res += (k/l)*b;
    ll d = (k%l)*a;
    if(d<b){
      res += d;
    }
    else{
      res += b;
    }
    cout << res << "\n";
  }
  else{
    cout << a*k << "\n";
  }
  return 0;
}
