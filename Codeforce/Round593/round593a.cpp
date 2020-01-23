#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int t;
  cin >> t;
  vector<int> a(t),b(t),c(t);
  rep(i,t) cin >> a[i] >> b[i] >> c[i];
  
  rep(i,t){
    int res = 0;
    while(b[i]>0&&c[i]>1){
      b[i]--;
      c[i]-=2;
      res+=3;
    }
    while(a[i]>0&&b[i]>1){
      a[i]--;
      b[i]-=2;
      res+=3;
    }
    cout << res << "\n";
  }
  
  return 0;
}
