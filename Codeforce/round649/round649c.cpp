#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<int> a(n+1);
  a[0] = 0;
  rep1(i,n) cin >> a[i];

  vector<bool> f(1000001, false);
  rep1(i,n) f[a[i]] = true;

  vector<int> res(n+1);
  int cnt = 0;
  if(a[1] == 1) cnt = 1;
  rep1(i,n) {
    if(a[i] > i) {
      cout << -1 << "\n";
      return 0;
    }
    if(a[i-1] < a[i]) res[i] = a[i-1];
    else {
      while(f[cnt]) cnt++;
      res[i] = cnt;
      cnt++;
    }
  }

  rep1(i,n) cout << res[i] << " ";
  cout  << "\n";
  return 0;
}
