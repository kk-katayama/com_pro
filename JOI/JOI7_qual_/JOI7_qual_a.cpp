#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  n = 1000 - n;
  int res = 0;
  vector<int> c = {500 , 100 , 50 , 10 , 5 , 1};
  rep(i,6){
    res += n / c[i];
    n = n % c[i];
  }
  cout << res << "\n";
  return 0;
}
