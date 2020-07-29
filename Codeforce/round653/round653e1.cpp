#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n,k; cin >> n >> k;
  vector<vector<int>> v(3);
  rep(i,n) {
    int t,a,b; cin >> t >> a >> b;
    if(a == 1 && b == 1) v[0].push_back(t);
    else if(a == 1 && b == 0) v[1].push_back(t);
    else if(a == 0 && b == 1) v[2].push_back(t);    
  }

  sort(v[1].begin(), v[1].end());
  sort(v[2].begin(), v[2].end());  
  rep(i, min(v[1].size(), v[2].size()) ) {
    v[0].push_back(v[1][i] + v[2][i]);
  }
  sort(v[0].begin(), v[0].end());

  if(k > v[0].size() ) cout << -1 << "\n";
  else {
    int res = 0;
    rep(i,k) res += v[0][i];
    cout << res << "\n";
  }
  
  return 0;
}
