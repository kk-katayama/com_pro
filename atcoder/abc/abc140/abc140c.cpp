#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int n;
int b[110];
int main()
{
  cin >> n;
  rep(i,n-1) cin >> b[i];
  
  int res = 0;
  res += b[0] + b[n-2];
  rep(i,n-2){
    res += min(b[i],b[i+1]);
  }
  
  cout << res << "\n";
  
  return 0;
}
