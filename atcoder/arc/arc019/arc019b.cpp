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
  string t = s;
  reverse(t.begin(), t.end());

  int n = s.size();
  if(n == 1) {
    cout << 0 << "\n";
    return 0;
  }
  int cnt = 0;
  rep(i,n) {
    if(s[i] != t[i]) cnt++;
  }
  int res;
  if(cnt == 0) {
    if(n % 2 == 0) res = 25*n;
    else res = 25*(n-1);
  }
  else if(cnt == 2) {
    res = 24*2 + 25*(n-2);
  }
  else {
    res = 25*n;
  }
  cout << res << "\n";
  
  return 0;
}
