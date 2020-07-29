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
  int n,m; cin >> n >> m;
  vector<int> k(m);
  vector<vector<int>> s(m);
  rep(i,m) {
    cin >> k[i];
    s[i].resize(k[i]);
    rep(j,k[i]) {
      cin >> s[i][j];
      s[i][j]--;
    }
  }
  vector<int> p(m);
  rep(i,m) cin >> p[i];

  int res = 0;
  rep(mask,(1 << n)) {
    bool f = true;
    rep(j,m) {
      int cnt = 0;
      rep(l,k[j]) {
	if((mask >> s[j][l]) & 1) cnt++;
      }
      if(cnt % 2 != p[j]) f = false;
    }
    if(f) res++;
  }
  cout << res << "\n";
  
  return 0;
}
