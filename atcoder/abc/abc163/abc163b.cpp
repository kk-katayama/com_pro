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
  int n,m;cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];
  
  int sum = 0;
  rep(i,m) sum += a[i];
  int res = n - sum;
  if(res < 0) res = -1;
  cout << res << "\n";
  return 0;
}
