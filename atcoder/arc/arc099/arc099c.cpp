#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
  }

  int cnt = 0;
  int res = 0;
  rep(i,n){
    if(a[i]==1){
      res += (cnt+k-2)/(k-1);
      cnt = 0;
    }
    else{
      cnt++;
    }
  }
  res += (cnt+k-2)/(k-1);  
  cout << res << "\n";
  return 0;
}
