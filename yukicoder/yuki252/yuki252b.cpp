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
  vector<int> a(n);
  int maxi = 0;
  rep(i,n) {
    cin >> a[i];
    chmax(maxi, a[i]);
  }

  vector<vector<int>> sum(n+1, vector<int>(maxi + 1, 1e+9));
  rep(i,maxi+1) sum[0][i] = 0;
  rep1(i,n) {
    rep(j,maxi+1) {
      if(j > 0) sum[i][j] = min(sum[i][j-1], sum[i-1][j] + abs(a[i-1] - j));
      else sum[i][j] = sum[i-1][j] + abs(a[i-1] - j);
    }
  }
  cout << sum[n][maxi] << "\n";

  
  return 0;
}
