#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];
  bool f = true;
  h[0] = max(h[0] - 1, 0);
  rep1(i,n-1) {
    if(h[i-1] <= h[i] - 1) h[i]--;
    else if(h[i-1] > h[i]) {
      f = false;
      break;
    }
  }
  if(f) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
