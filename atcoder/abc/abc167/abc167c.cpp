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
  int n,m,x; cin >> n >> m >> x;
  vector<int> c(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i,n) {
    cin >> c[i];
    rep(j,m) cin >> a[i][j];
  }

  int res = 1e+9;
  rep(mask, (1 << n)) {
    vector<int> vec(m, 0);
    int sum = 0;
    rep(j,n) {
      if((mask >> j) & 1) {
	sum += c[j];
	rep(k,m) {
	  vec[k] += a[j][k];
	}
      }
    }
    bool f = true;
    rep(k,m) {
      if(vec[k] < x) {
	f = false;
	break;
      }
    }
    if(f) chmin(res, sum); 
  }

  if(res == 1e+9) cout << -1 << "\n";
  else cout << res << "\n";
  
  return 0;
}
