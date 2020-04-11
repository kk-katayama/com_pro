#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int sum = 0;
  rep(i,n) sum += a[i];

  int cnt = 0;
  int th;
  if( sum % (4*m) == 0) {
    th = sum / (4*m);
  }
  else {
    th = sum / (4*m) + 1;
  }
  rep(i,n) {
    if( th <= a[i] ) cnt++;
  }
  if(cnt >= m) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
