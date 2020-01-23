#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int t;
  cin >> t;
  vector<int> n(t),x(t),a(t),b(t);
  rep(i,t) cin >> n[i] >> x[i] >> a[i] >> b[i];

  rep(i,t){
    int d = abs(a[i]-b[i]);
    cout << min(d+x[i],n[i]-1) << "\n";
  }
  return 0;
}
