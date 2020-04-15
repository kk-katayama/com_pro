#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n;cin >> n;
  ll res = 0;
  for(ll i = 1;i <= n;++i) {
    if(i % 3 !=0 && i % 5 != 0) {
      res += i;
    }
  }
  cout << res << "\n";
  return 0;
}
