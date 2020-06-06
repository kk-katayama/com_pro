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
  int k; cin >> k;
  string s; cin >> s;
  if(k >= (int)s.size()) cout << s << "\n";
  else {
    rep(i,k) cout << s[i];
    cout << "..." << "\n";
  }
  return 0;
}
