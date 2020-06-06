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
  int n;cin >> n;
  vector<int> b(n);
  rep(i,n) cin >> b[i];

  int sum = 0;
  rep(i,n) sum ^= b[i];
  if(sum != 0) {
    cout << -1 << "\n";
    return 0;
  }

  int a = 0;
  rep(i,n) {
    cout << a << "\n";
    a ^= b[i];
  }

  
  return 0;
}
