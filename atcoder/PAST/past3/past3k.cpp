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
  int n,q; cin >> n >> q;
  vector<int> f(q), t(q), x(q);
  rep(i,q) cin >> f[i] >> t[i] >> x[i];
  vector<int> a(2*n+1);
  rep1(i, n) a[i] = n+i;
  rep1(i, n) a[n+i] = n+i;

  vector<int> b(n+1);
  rep1(i,n) b[i] = i;

  rep(i,q) {
    int tmp = a[x[i]];
    a[x[i]] = b[t[i]];
    b[t[i]] = b[f[i]];
    b[f[i]] = tmp;
  }

  vector<vector<int>> na(2*n+1, vector<int>(21));
  rep1(i,2*n) na[i][0] = a[i];

  rep(j, 20) {
    rep1(i, 2*n) {
      na[i][j+1] = na[na[i][j]][j];
    }
  }

  rep1(i,n) cout << na[i][20]-n << "\n";
  
  
  return 0;
}
