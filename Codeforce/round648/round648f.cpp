#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int t; cin >> t;
  using pi = pair<int,int>;
  vector<string> res;
  while(t-- > 0) {
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    map<pi,int> mp;
    rep(i,n/2) {
      if(a[i] > a[n-1-i]) swap(a[i], a[n-1-i]);
      mp[{a[i], a[n-1-i]}] = 1;
    }
    bool f = true;
    rep(i,n/2) {
      if(b[i] > b[n-1-i]) swap(b[i], b[n-1-i]);
      if(mp[{b[i], b[n-1-i]}] == 0) f = false;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    rep(i,n) if(a[i] != b[i]) f = false;
    res.push_back((f ? "Yes" : "No"));
  }

  for(auto val: res) cout << val << "\n";
  return 0;
}
