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
  int res = 2;
  int M = 5000000;
  vector<int> a(M);
  a[0] = 1;
  a[1] = 2;
  int i = 2;
  while(a[i-1] + a[i-2] <= 4000000) {
    a[i] = a[i-1] + a[i-2];
    if(a[i] % 2 == 1) res += a[i];
    i++;
  }
  cout << res << "\n";

  return 0;
}
