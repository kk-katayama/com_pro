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
  int t; cin >> t;
  while(t-- > 0) {
    ll a,b,c; cin >> a >> b >> c;
    if(a < c) cout << 1 << " ";
    else cout << -1 << " ";
    if(a*b > c) cout << b << "\n";
    else cout << -1 << "\n";
  }
  return 0;
}
