#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int A,B,m;cin >> A >> B >> m;
  vector<int> a(A),b(B);
  rep(i,A) cin >> a[i];
  rep(i,B) cin >> b[i];
  vector<int> x(m),y(m),c(m);
  rep(i,m) {
    cin >> x[i] >> y[i] >> c[i];
    x[i]--;y[i]--;
  }
  int res = 1e+9;
  rep(i,m){
    res = min(res,a[x[i]]+b[y[i]]-c[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  res = min(res,a[0]+b[0]);
  cout << res << "\n";
  return 0;
}
