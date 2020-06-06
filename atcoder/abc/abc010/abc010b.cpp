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
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  int res = 0;
  rep(i,n) {
    while(a[i] % 2 == 0 || a[i] % 3 == 2) {
      res++;
      a[i]--;
    }
  }

  cout << res << "\n";
  return 0;
}
