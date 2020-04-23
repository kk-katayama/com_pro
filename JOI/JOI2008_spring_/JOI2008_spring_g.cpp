#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
vector<pair<int,int>> mass[1000010];
int main()
{
  int n;cin >> n;
  int a,b;cin >> a >> b;
  vector<int> p(n), q(n), r(n), s(n);
  rep(i,n) {
    cin >> p[i] >> q[i] >> r[i] >> s[i];
    p[i]--; q[i]--; r[i]--; s[i]--;
  }
  
  rep(i,n) {
    for(int j = q[i]; j <= s[i]; ++j) {
      mass[j].push_back( {p[i], 1} );
      mass[j].push_back( {r[i]+1, 0} );      
    }
  }

  rep(i,b) sort(mass[i].begin(), mass[i].end());
  vector<int> res(5001, 0);

  rep(i,b) {
    if(mass[i].size() == 0) continue;
    int cnt = 0;
    rep(j,mass[i].size()-1) {
      if(mass[i][j].second == 1) cnt++;
      else cnt--;
      res[cnt] += mass[i][j+1].first - mass[i][j].first;
    }
  }

  for(int i = 5000; i > 0; --i) {
    if(res[i] != 0) {
      cout << i << "\n";
      cout << res[i] << "\n";
      break;
    }
  }
  
  return 0;
}
