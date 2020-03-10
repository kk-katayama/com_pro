#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,a,b;cin >> n >> a >> b;
  ll res = (n/(a+b))*a + min(n%(a+b),a);
  cout << res << "\n";
  return 0;
}
