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
  int n,a,b; cin >> n >> a >> b;

  if(a == b) {
    if(n % (a + 1) == 0) cout << "Aoki" << "\n";
    else cout << "Takahashi" << "\n";
  }
  else if(a > b) {
    cout << "Takahashi" << "\n";
  }
  else {
    if(n <= a) cout << "Takahashi" << "\n";
    else cout << "Aoki" << "\n";
  }
  return 0;
}
