#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> b(n-1);
  rep(i,n-1) cin >> b[i];
  int res = 0;
  rep(i,n-2){
    res += min(b[i] , b[i+1]);
  }
  res += b[0] + b[n-2];
  cout << res << "\n";
  return 0;
}
