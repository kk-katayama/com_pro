#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll a,b,c,d;cin >> a >> b >> c >> d;
  ll mini, top;
  if(b-a+1 < c-b+1) {
    mini = b-a+1;
    top = a+c;
  }
  else {
    mini = c-b+1;
    top = b+b;
  }
  vector<ll> x;
  ll cnt = 1;
  for(ll i = a+b; i <= b+c; ++i) {
    x.push_back(cnt);
    if(i >= top) cnt--;
    else cnt = min(mini, cnt+1);
  }
  int n = x.size();
  vector<ll> sum(n+1);
  sum[0] = 0;
  rep(i,n) sum[i+1] = sum[i] + x[i];

  ll res = 0;
  for(int i = c; i <= d; ++i) {
    ll idx = min(max(i - (a + b) + 1, (ll)0), (ll)n);
    res += sum[n] - sum[idx];
  }
  cout << res << "\n";
  
  return 0;
}
