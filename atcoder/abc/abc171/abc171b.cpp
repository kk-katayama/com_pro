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
  int k; cin >> k;
  vector<int> p(n);
  rep(i,n) cin >> p[i];
  sort(p.begin(), p.end());
  int res = 0;
  rep(i,k) res += p[i];
  cout << res << "\n";
  return 0;
}
