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
  string s; cin >> s;
  int n;cin >> n;
  int m = s.size();
  rep(i,m) {
    rep(j,m) {
      n--;
      if(n == 0) {
	cout << s[i] << s[j] << "\n";
	return 0;
      }
    }
  }
  return 0;
}
