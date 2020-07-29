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
  vector<int> l(n);
  rep(i,n) cin >> l[i];

  sort(l.begin(), l.end());
  int res = 0;
  rep(i,n) {
    rep(j,n) {
      if(i >= j) continue;
      int sum = l[i] + l[j];
      int lb = j, ub = n;
      while(ub - lb > 1) {
	int mid = (ub + lb) / 2;
	(l[mid] < sum ? lb : ub) = mid;
      }
      res += lb - j;
    }
  }
  
  cout << res << "\n";
  return 0;
}
