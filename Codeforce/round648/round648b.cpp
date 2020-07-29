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
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bool f0 = false, f1 = false;
    rep(i,n) {
      int b; cin >> b;
      (b == 0 ? f0 : f1) = true;
    }
    if(f0 && f1) {
      res.push_back("Yes");
    }
    else {
      bool f = true;
      rep(i,n-1) {
	if(a[i] > a[i+1]) f = false;
      }
      res.push_back((f ? "Yes" : "No"));
    }
  }

  for(auto val: res) cout << val << "\n";

  
  return 0;
}
