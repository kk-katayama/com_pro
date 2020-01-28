#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll h;
  cin >> h;

  ll x = 1;
  ll res = 0;
  while(h>0){
    h /= (ll)2;
    res += x;
    x *= (ll)2;
  }

  cout << res << "\n";
  return 0;
}
