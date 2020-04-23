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
  int l, a, b, c, d;cin >> l >> a >> b >> c >> d;
  int k = (a + c - 1) / c;
  int s = (b + d - 1) / d;
  cout << l - max(k, s) << "\n";
  return 0;
}
