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
  vector<string> res;
  while(t-- > 0) {
    int n,x; cin >> n >> x;
    int odd = 0, even = 0;
    rep(i,n) {
      int a; cin >> a;
      (a % 2 == 0 ? even : odd)++;
    }
    if(odd == 0) {
      res.push_back("No");
      continue;
    }
    odd -= (odd % 2 == 0 ? 1 : 0);
    if(x % 2 == 0) {
      if(x <= odd) res.push_back((even >= 1 ? "Yes" : "No"));
      else res.push_back((x - odd <= even ? "Yes" : "No"));
    }
    else {
      if(x <= odd) res.push_back("Yes");
      else res.push_back((x - odd <= even ? "Yes" : "No"));
    }
  }
  for(auto val: res) cout << val << "\n";
  
  return 0;
}
