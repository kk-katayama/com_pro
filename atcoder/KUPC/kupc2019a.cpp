#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n,x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(), a.end());
  int res = 0;
  rep(i,n){
    if(a[i]+x>=a[n-1]) res++;
  }
  cout << res << "\n";
  return 0;
}
