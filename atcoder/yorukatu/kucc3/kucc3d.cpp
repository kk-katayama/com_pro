#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  string s;cin >> s;
  reverse(s.begin(), s.end());
  int n = s.size();
  vector<int> w(n, 0);
  rep(i,n) {
    rep(j,n) {
      if(s[(i+j)%n] == 'o') {
	w[i] += (1 << j);
      }
    }
  }

  const int  inf = 1e+9;
  vector<int> dp((1 << n), inf);
  dp[0] = 0;
  rep(i, (1 << n) ) {
    if(dp[i] == inf) continue;
    rep(j,n) {
      chmin(dp[i | w[j]], dp[i] + 1);
    }
  }

  cout << dp[(1<<n)-1] << "\n";

  ll x = 1;
  rep1(i,10) x *= i;
  cout << x << "\n";
  
  return 0;
}
