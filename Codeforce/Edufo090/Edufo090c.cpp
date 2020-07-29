#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    string s; cin >> s;
    ll res = s.size();
    ll cnt = 0;
    ll mini = 0;
    rep(i,s.size()) {
      if(s[i] == '-') {
	cnt--;
	if(chmin(mini, cnt)) {
	  res += (i + 1);
	}
      }
      else cnt++;
    }
    cout << res << "\n";
  }
  return 0;
}
