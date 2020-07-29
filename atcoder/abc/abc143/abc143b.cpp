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
  vector<int> d(n);
  rep(i,n) cin >> d[i];

  int res = 0;
  rep(i,n) {
    rep(j,n) {
      if(i >= j) continue;
      res += d[i]*d[j];
    }
  }
  cout << res << "\n";
  return 0;
}
