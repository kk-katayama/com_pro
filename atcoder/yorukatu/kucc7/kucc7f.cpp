#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
int main()
{
  int n; cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  int l; cin >> l;
  int q; cin >> q;
  vector<int> a(q), b(q);
  rep(i,q) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }

  int M = 20;
  vector<vector<int>> c(n, vector<int>(M));
  rep(i,n) {
    int lb = -1, ub = n;
    while(ub - lb > 1) {
      int mid = (ub + lb)/2;
      (x[mid] <= x[i] + l ? lb : ub) = mid;
    }
    c[i][0] = lb;
  }

  // ダブリングテーブル作成
  rep1(j,M-1) {
    rep(i,n) {
      c[i][j] = c[c[i][j-1]][j-1];
    }
  }

  vector<int> pow2(M+1);
  pow2[0] = 1;
  rep(i,M) {
    pow2[i+1] = pow2[i] * 2;
  }
  
  rep(i,q) {
    if(a[i] > b[i]) swap(a[i], b[i]);
    int res = 0;
    int v = a[i];
    while(1) {
      int idx = 0;
      while(c[v][idx] < b[i]) idx++;
      if(idx == 0) {
	res += pow2[idx];
	break;
      }
      else {
	res += pow2[idx-1];
      }
      v = c[v][idx-1];
    }
    cout << res << "\n";
  }
  
  return 0;
}
