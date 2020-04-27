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
  int n;cin >> n;
  vector<int> d(n);
  rep(i,n) cin >> d[i];

  int sum = 0;
  int maxi = 0;
  rep(i,n) {
    sum += d[i];
    chmax(maxi, d[i]);
  }

  cout << sum << "\n";
  if(maxi - (sum - maxi) <= 0) cout << 0 << "\n";
  else cout << maxi - (sum - maxi) << "\n";
  
  return 0;
}
