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
  int t; cin >> t;
  while(t-- > 0) {
    int n; cin >> n;
    string s; cin >> s;
    int res = 0;
    int cnt = 0;
    rep(i,n) {
      if(s[i] == '(') cnt++;
      else cnt--;
      if(cnt < 0) {
	res++;
	cnt++;
      }
    }
    cout << res << "\n";
  }
  return 0;
}
