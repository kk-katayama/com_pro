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
  int n; cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n) {
    cin >> a[i] >> b[i];
  }

  ll inf = 1LL << 60;
  ll mini = inf;
  ll sum = 0;
  rep(i,n) {
    if(a[i] > b[i]) chmin(mini, b[i]);
    sum += a[i];
  }
  if(mini == inf) {
    cout << 0 << "\n";
  }
  else {
    cout << sum - mini << "\n";
  }
  
  
  return 0;
}
