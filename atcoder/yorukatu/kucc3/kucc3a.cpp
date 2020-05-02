#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n,a,b;cin >> n >> a >> b;
  vector<ll> s(n);
  rep(i,n) cin >> s[i];

  ll sum = 0;
  ll maxi = 0, mini = 1e+9+1;
  rep(i,n) {
    sum += s[i];
    chmax(maxi, s[i]);
    chmin(mini, s[i]);
  }

  if(maxi == mini) {
    cout << -1 << "\n";
    return 0;
  }

  double p = (double)b / (maxi - mini);
  double q = ((double)(n*a) - p*sum) / n;

  printf("%.7f %.7f\n", p, q);
  
  return 0;
}
