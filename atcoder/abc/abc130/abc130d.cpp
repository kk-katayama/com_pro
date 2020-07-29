#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  ll n; cin >> n;
  ll k; cin >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i] + a[i];

  ll lb = 0, ub = 1;
  ll res = 0;
  while(ub <= n) {
    while(ub <= n && sum[ub] - sum[lb] < k) ub++;
    res += n - ub + 1;
    lb++;
  }
  cout << res << "\n";
  
  return 0;
}
