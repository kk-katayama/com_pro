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
    int cnt0 = 0, cnt1 = 0;
    int idx = 0;
    while(s[idx] == '0') {
      cnt0++;
      idx++;
      if(idx == n) break;
    }
    idx = n - 1;
    while(s[idx] == '1') {
      cnt1++;
      idx--;
      if(idx == -1) break;
    }
    if(cnt0 + cnt1 == n) {
      cout << s << "\n";
    }
    else {
      rep(i,cnt0) cout << '0';
      cout << '0';
      rep(i,cnt1) cout << '1';
      cout << "\n";
    }
  }
  return 0;
}
