#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  int res = 1e+9;;
  rep1(i,n){
    int x = n/i;
    int y = n%i;
    res = min(res,abs(x-i)+y);
  }
  cout << res << "\n";
  return 0;
}
