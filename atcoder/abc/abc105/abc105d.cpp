#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n, m;cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = (sum[i] + a[i]) % m;
  
  map<int,ll> mp;
  ll res = 0;
  rep(i,n+1) {
    res += mp[sum[i]];
    mp[sum[i]]++;
  }
  cout << res << "\n";
  
  return 0;
}
