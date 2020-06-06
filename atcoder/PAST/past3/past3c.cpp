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
  ll a,r,n; cin >> a >> r >> n;
  n--;
  int M = 1e+9;
  ll res = a;
  bool f = false;
  while(n > 0) {
    if(n & 1) {
      if(f) {
	cout << "large" << "\n";
	return 0;	
      }
      res *= r;
    }
    if(res > M) {
      cout << "large" << "\n";
      return 0;
    }
    r *= r;
    if(r > M) {
      f = true;
    }    
    n >>= 1;
  }
  cout << res << "\n";
  
  return 0;
}
