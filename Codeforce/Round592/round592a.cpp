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
  vector<int> a(t),b(t),c(t),d(t),k(t);
  rep(i,t) cin >> a[i] >> b[i] >> c[i] >> d[i] >> k[i];

  rep(i,t){
    int x = (a[i]+c[i]-1)/c[i];
    int y = (b[i]+d[i]-1)/d[i];

    if(x+y<=k[i]) cout << x << " " << y << "\n";
    else cout << -1 << "\n";
  }

  return 0;
}
