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
  int a,b,c;cin >> a >> b >> c;
  int k;cin >> k;

  if(k <= a) {
    cout << k << "\n";
    return 0;
  }
  else {
    k -= a;
  }

  if(k <= b) {
    cout << a << "\n";
    return 0;
  }
  else {
    k -= b;
  }

  cout << a - k << "\n";
  
  return 0;
}
