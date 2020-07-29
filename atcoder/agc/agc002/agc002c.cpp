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
  int n,l; cin >> n >> l;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  rep(i,n-1) {
    if(a[i] + a[i+1] >= l) {
      cout << "Possible" << "\n";
      rep(j,i) {
	cout << j+1 << "\n";
      }
      for (int j = n-1; j >= i + 2; --j) {
	cout << j << "\n";
      }
      cout << i+1 << "\n";
      return 0;
    }
  }
  cout << "Impossible" << "\n";

  
  return 0;
}
