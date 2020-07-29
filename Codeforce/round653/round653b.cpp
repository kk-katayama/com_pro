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
  int t; cin >> t;
  while(t-- > 0) {
    int n; cin >> n;
    int x = 0, y = 0;
    while(n % 2 == 0) {
      n /= 2;
      x++;
    }
    while(n % 3 == 0) {
      n /= 3;
      y++;
    }
    if(n == 1) {
      if(x <= y) cout << 2*y - x << "\n";
      else cout << -1 << "\n";
    }
    else cout << -1 << "\n";
  }
  return 0;
}
