#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,k;cin >> n >> k;
  ll res = 0;
  for(ll b = 1;b <= n;++b) {
    ll tmp = n/b * max((ll)0, b-k) + max((ll)0, n%b - k + 1);
    res += tmp;
  }
  if(k == 0) res = n*n;
  cout << res << "\n";
  return 0;
}
