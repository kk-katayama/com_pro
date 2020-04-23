#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n;cin >> n;
  string s;cin >> s;
  vector<string> t(n);
  rep(i,n) cin >> t[i];

  int res = 0;
  int ss = s.size();
  rep(i,n) {
    int index = 0;
    rep(j,t[i].size()) {
      if(s[index] == t[i][j]) index++;
      if(index == ss) {
	res++; break;
      }
    }
  }

  cout << res << "\n";
  return 0;
}
