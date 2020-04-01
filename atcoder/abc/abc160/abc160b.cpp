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
  res += (n / 500) * 1000;
  n = n % 500;
  res += (n / 5) * 5;
  cout << res << "\n";
  return 0;
}
