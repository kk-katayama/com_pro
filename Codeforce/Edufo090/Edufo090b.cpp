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
    string s; cin >> s;
    int a = 0, b = 0;
    for(auto val: s) {
      if(val == '0') a++;
      else b++;
    }
    if(min(a, b) % 2 == 0) {
      cout << "NET" << "\n";
    }
    else {
      cout << "DA" << "\n";
    }
  }
  return 0;
}
