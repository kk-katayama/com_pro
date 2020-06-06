#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  vector<vector<ll>> a(20, vector<ll>(20));
  rep(i,20) {
    rep(j,20) {
      cin >> a[i][j];
    }
  }

  rep(i,20) {
    rep(j,20) cout << a[i][j] << " ";
    cout << "\n";
  }
  
  ll res = 0;
  rep(i,20) {
    rep(j,20) {
      if(i + 3 < 20) {
	ll tmp = a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j];
	chmax(res, tmp);
      }
      if(j + 3 < 20) {
	ll tmp = a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
	chmax(res, tmp);
      }
      if(i + 3 < 20 && j + 3 < 20) {
	ll tmp = a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
	chmax(res, tmp);				    
      }
      //      if(res == 11258324400) cout << i << ":" << j << "\n";
    }
  }
  cout << res << "\n";
  return 0;
}
