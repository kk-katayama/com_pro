#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int l,h;cin >> l >> h;
  int n;cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n){
    if(l<=a[i]&&a[i]<=h) cout << 0 << "\n";
    else if(h<a[i]) cout << -1 << "\n";
    else cout << l-a[i] << "\n";
  }
  return 0;
}
