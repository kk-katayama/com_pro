#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
int main()
{
  int n;cin >> n;
  vector<int> a(9);
  rep(i,9) cin >> a[i];

  rep(i,9) n -= a[i];
  cout << n << "\n";
    
  return 0;
}
