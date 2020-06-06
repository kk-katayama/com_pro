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
  int t;cin >> t;
  vector<int> x(t), y(t);
  vector<string> s(t);
  rep(i,t) cin >> x[i] >> y[i] >> s[i];

  vector<int> res(t, -1);
  rep(i,t) {
    int n = s[i].size();
    int xx = x[i], yy = y[i];
    rep(j,n) {
      if(abs(xx) + abs(yy) <= j) {
	res[i] = j;
	break;
      }
      if(s[i][j] == 'S') yy--;
      else if(s[i][j] == 'N') yy++;
      else if(s[i][j] == 'E') xx++;
      else if(s[i][j] == 'W') xx--;      
    }
    if(res[i] == -1 && abs(xx) + abs(yy) <= n) res[i] = n; 
  }

  rep(i,t) {
    cout << "Case #" << i + 1 << ": ";
    if(res[i] == -1) cout << "IMPOSSIBLE" << "\n";
    else cout << res[i] << "\n";
  }
    
  return 0;
}
