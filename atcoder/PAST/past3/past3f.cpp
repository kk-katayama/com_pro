#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  vector<set<char>> st(n);
  rep(i,n) rep(j,n) {
    st[i].insert(s[i][j]);
  }

  vector<char> res(n);
  rep(i,n/2) {
    bool f = true;
    for(auto w: st[i]) {
      if(st[n-1-i].find(w) != st[n-1-i].end()) {
	res[i] = w;
	res[n-1-i] = w;
	f = false;
	break;
      }
    }
    if(f) {
      cout << -1 << "\n";
      return 0;
    }
  }

  if(n % 2 == 1) res[n/2] = s[n/2][0];
  rep(i,n) cout << res[i];
  cout << "\n";
  
  return 0;
}
