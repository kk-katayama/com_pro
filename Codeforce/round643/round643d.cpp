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
  int n,s; cin >> n >> s;
  if(s/n >= 2) {
    cout << "YES" << "\n";
    rep(i,n) {
      if(i != n-1) cout << s/n << " ";
      else cout << s/n + s%n << "\n";
    }
    cout << 1 << "\n";
  }
  else {
    cout << "NO" << "\n";
  }
  return 0;
}
