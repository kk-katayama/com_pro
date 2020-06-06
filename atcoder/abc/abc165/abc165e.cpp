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
  int n,m;cin >> n >> m;
  if(n % 2 == 0) {
    int a = 1;
    int b = n;
    rep(i,m) {
      if((n/2) % 2 == 0 && i == m/2 + 1) b--;
      if((n/2) % 2 == 1 && i == m/2) b--;
      cout << a << " " << b << "\n";
      a++; b--;
    }
  }
  else {
    rep1(i,m) {
      cout << i << " ";
      cout << n - i << "\n";
    }
  }
  return 0;
}
