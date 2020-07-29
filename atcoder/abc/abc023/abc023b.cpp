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
  int n; cin >> n;
  string s; cin >> s;

  string t = "b";
  int cnt = 0;
  while(t.size() <= n) {
    if(s == t) {
      cout << cnt << "\n";
      return 0;
    }
    cnt++;
    if(cnt % 3 == 1) {
      string tmp = "a";
      tmp += t;
      tmp.push_back('c');
      t = tmp;
    }
    else if(cnt % 3 == 2) {
      string tmp = "c";
      tmp += t;
      tmp.push_back('a');
      t = tmp;      
    }
    else {
      string tmp = "b";
      tmp += t;
      tmp.push_back('b');
      t = tmp;      
    }
  }
  cout << -1 << "\n";
  return 0;
}
