#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  string s,t; cin >> s >> t;
  if(s == t) cout << "same" << "\n";
  else {
    bool f = true;
    rep(i,3) {
      if( ! ((abs((int)s[i] - t[i])) == 32 || s[i] == t[i]) ) f = false;
    }
    if(f) cout << "case-insensitive" << "\n";
    else cout << "different" << "\n";
  }
  
  return 0;
}
