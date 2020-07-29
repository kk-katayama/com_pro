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
  string s,t; cin >> s >> t;
  int n = s.size(), m = t.size();
  int idx = -1;
  vector<string> res;
  for (int i = n - 1; i >= 0; --i) {
    int k = i - m + 1;
    if(k < 0) break;
    bool f = true;
    rep(j,m) {
      if(s[k + j] != t[j] && s[k + j] != '?') {
	f = false;
	break;
      }
    }
    if(f) {
      idx = k;
      string ss = s;
      for (int j = k; j < k + m; ++j) {
	ss[j] = t[j - k];
      }
      rep(i,n) {
	if(ss[i] == '?') ss[i] = 'a';
      }
      res.push_back(ss);
    }
  }
  if(idx == -1) cout << "UNRESTORABLE" << "\n";
  else {
    sort(res.begin(), res.end());
    cout << res[0] << "\n";
  }

  return 0;
}
