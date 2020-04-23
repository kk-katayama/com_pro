#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int modpow(int x, int n, int mod) {
  int res = 1;
  while(n > 0) {
    if(n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
int main()
{
  int p,n; cin >> p >> n;
  map<int,int> mp;
  rep(i,p) {
    mp[modpow(i, n, p)]++;
  }

  int res = 0;
  for(auto i : mp) {
    for(auto j : mp) {
      int z = (i.first + j.first) % p;
      res += i.second * j.second * mp[z];
    }
  }
  cout << res << "\n";
  return 0;
}
