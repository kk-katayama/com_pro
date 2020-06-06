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
  int n;cin >> n;

  int cnt = 0;
  rep(mask, (1 << n)) {
    for(int sub = mask; sub >= 0; --sub) {
      sub &= mask;
      cnt++;
    }
  }
  cout << "3^n    " << pow(3,n) << "\n";
  cout << "計算量 " << cnt << "\n";
  
  
  return 0;
}
