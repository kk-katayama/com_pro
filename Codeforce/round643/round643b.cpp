#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int t;cin >> t;
  vector<int> n(t);
  vector<vector<int>> e(t);
  rep(i,t) {
    cin >> n[i];
    e[i].resize(n[i]);
    rep(j,n[i]) cin >> e[i][j];
  }

  rep(i,t) {
    map<int,int> mp;
    rep(j,n[i]) {
      mp[e[i][j]]++;
    }
    int res = 0;
    int red = 0;
    for(auto m: mp) {
      res += m.second / m.first;
      red += m.second % m.first;
      res += red / m.first;
      red -= (red / m.first) * m.first;
    }
    cout << res << "\n";
  }
  
  return 0;
}
