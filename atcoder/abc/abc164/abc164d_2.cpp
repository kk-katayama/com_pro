#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int p = 2019;
  string s;cin >> s;
  int n = s.size();
    ll x = 1;
    map<ll,ll> mp;
    ll sum = 0;
    mp[0]++;
    for(int i=n-1;i>=0;i--){
      ll c = s[i] - '0';
      sum = (sum+(c*x)%p)%p;
      mp[sum]++;
      x = (x*10)%p;
    }
    ll res = 0;
    for(auto m:mp){
      res += (m.second-1)*m.second/2;
    }
    cout << res << "\n";

  return 0;
}
