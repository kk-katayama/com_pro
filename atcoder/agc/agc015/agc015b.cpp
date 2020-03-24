#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  string s;cin >> s;
  ll n = s.size();
  ll res = 0;
  for (ll i = 0; i < n; ++i) {
    if(s[i] == 'U') res += (n - i - 1) + i*2;
    else res += i + (n - i - 1)*2;
  }
  cout << res << "\n";

  return 0;
}
