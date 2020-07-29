#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll a,v,b,w,t;
  cin >> a >> v >> b >> w >> t;
  if(a < b) {
    if(a + v*t >= b + w*t) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
  else {
    if(a - v*t <= b - w*t) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
  return 0;
}
