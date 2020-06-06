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

  if(s.size() == 2) {
    cout << "dict" << "\n";
    return 0;
  }
  int cnt = 0;
  rep(i,s.size()) {
    if(s[i] == '{') cnt++;
    else if(s[i] == '}') cnt--;
    else if(s[i] == ':') {
      if(cnt == 1) {
	cout << "dict" << "\n";
	return 0;
      }
    }
  }
  cout << "set" << "\n";
  return 0;
}
