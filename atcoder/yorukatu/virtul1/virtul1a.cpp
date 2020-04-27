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
  int n,m,k;cin >> n >> m >> k;
  rep(i,n+1) {
    rep(j,m+1) {
      int tmp = i*m + j*n - 2*i*j;
      if(tmp == k) {
	cout << "Yes" << "\n";
	return 0;
      }
    }
  }
  cout << "No" << "\n";
  return 0;
}
