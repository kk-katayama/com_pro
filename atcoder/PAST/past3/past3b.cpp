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
  int n,m,q; cin >> n >> m >> q;
  vector<int> s(q), x(q), y(q);
  rep(i,q) {
    cin >> s[i];
    if(s[i] == 1) {
      cin >> x[i]; x[i]--;
    }
    else {
      cin >> x[i] >> y[i];
      x[i]--; y[i]--;
    }
  }

  vector<set<int>> st(n);
  vector<int> score(m, n);
  rep(i,q) {
    if(s[i] == 1) {
      int res = 0;
      for(auto w: st[x[i]]) {
	res += score[w];
      }
      cout << res << "\n";
    }
    else {
      st[x[i]].insert(y[i]);
      score[y[i]]--;
    }
  }
  return 0;
}
