#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int res = 0;
  for (int i = 100; i < 1000; ++i) {
    for (int j = 100; j < 1000; ++j) {
      int x = i*j;
      ostringstream oss;
      oss << x;
      string s = oss.str();
      string t = s;
      reverse(s.begin(), s.end());      
      if(s == t) chmax(res, x);
    }
  }
  cout << res << "\n";
  return 0;
}
