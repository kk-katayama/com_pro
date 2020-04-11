#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,m;cin >> n >> m;
  vector<int> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  int j = 0;
  int res;
  rep(i,m) {
    j += b[i];
    if(j >= n - 1) {
      res = i + 1;
      break;
    }
    else {
      j += a[j];
      if(j >= n - 1) {
	res = i + 1;
	break;
      }
    }
  }

  cout << res << "\n";
  return 0;
}
