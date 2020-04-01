#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(n),b(n),c(n-1);
  rep(i,n){ cin >> a[i];a[i]--;}
  rep(i,n) cin >> b[i];
  rep(i,n-1) cin >> c[i];
  int res = 0;
  rep(i,n){
    res += b[a[i]];
    if(i != n - 1){
      if(a[i] + 1 == a[i+1]) res += c[a[i]];
    }
  }
  cout << res << "\n";
  return 0;
}
