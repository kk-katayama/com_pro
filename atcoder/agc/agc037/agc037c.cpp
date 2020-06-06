#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  using ll = long long;
  using pi = pair<ll,int>;
  using pq = priority_queue<pi>;
  
  int n; cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  pq q;
  rep(i,n) {
    if(a[i] < b[i]) q.push({b[i], i});
    else if(a[i] > b[i]) {
      cout << -1 << "\n";
      return 0;
    }
  }

  ll res = 0;
  while( !q.empty() ) {
    pi p = q.top(); q.pop();
    int idx = p.second;
    ll x = b[(idx - 1 + n) % n], y = b[idx], z = b[(idx + 1) % n];
    if((y - a[idx]) % (x + z) == 0) {
      res += (y - a[idx]) / (x + z);
      b[idx] = a[idx];
      continue;
    }
    ll m = (y - max(x, z) + (x + z) - 1) / (x + z);
    res += m;
    b[idx] -= m * (x + z);
    if(a[idx] < b[idx]) q.push({b[idx], idx});
    else if(a[idx] > b[idx]) {
      cout << -1 << "\n";
      return 0;
    }
  }

  cout << res << "\n";
  
  return 0;
}
