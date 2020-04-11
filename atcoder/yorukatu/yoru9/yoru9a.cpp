#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  int a, b;cin >> a >> b;
  int res = 0;
  rep1(i,n) {
    int sum = 0;
    int x = i;
    while(x > 0) {
      sum += x % 10;
      x /= 10;
    }
    if(a <= sum && sum <= b) res += i;
  }
  cout << res << "\n";
  return 0;
}
