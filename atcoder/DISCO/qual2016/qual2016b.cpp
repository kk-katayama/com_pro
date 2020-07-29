#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

  int M = 1e+5+1;
  vector<set<int>> st(M);
  rep(i,n) {
    st[a[i]].insert(i);
  }

  int tail = -1;
  int res = 0;
  rep(i,M) {
    if(st[i].empty()) continue;
    auto it = st[i].upper_bound(tail);
    if(it == st[i].begin()) {
      auto endit = st[i].end();
      endit--;
      tail = *endit;
    }
    else {
      res++;
      it--;
      tail = *it;
    }
  }
  res += (tail == 0 ? 0 : 1);
  cout << res << "\n";
  return 0;
}
