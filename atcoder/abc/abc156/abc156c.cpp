#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i,n) cin >> x[i];

  int res = 1e+9;
  rep1(i,100){
    int sum=0;
    rep(j,n){
      sum += (x[j]-i)*(x[j]-i);
    }
    sum = max(0,sum);
    res = min(res,sum);
  }
  cout << res << "\n";
  return 0;
}
