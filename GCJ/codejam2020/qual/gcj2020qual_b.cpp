#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int t;cin >> t;
  vector<string> s(t);
  rep(i,t) cin >> s[i];

  rep(i,t) {
    int n = s[i].size();
    string t = "0";
    t += s[i];
    t += "0";
    vector<string> res(n+1, "");
    rep(j,n+1) {
      int x = t[j+1] - t[j];
      if(x > 0) {
	rep(k,x) res[j] += "(";
      }
      else {
	rep(k,-x) res[j] += ")";
      }
    }
    cout << "Case #" << i + 1 << ": ";
    rep(j,n+1) {
      if(j != 0) cout << t[j];
      cout << res[j];
    }
    cout << "\n";
  }
  return 0;
}
