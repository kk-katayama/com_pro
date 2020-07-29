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
  int a,b,c; cin >> a >> b >> c;
  int x; cin >> x;

  int res = 0;
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      for (int k = 0; k <= c; ++k) {
	if(x == 500*i + 100*j + 50*k) res++;
      }
    }
  }
  cout << res << "\n";
  
  return 0;
}
