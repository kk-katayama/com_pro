#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n,k;
  cin >> n >> k;
  vector<ll> h(n);
  rep(i,n){
    cin >> h[i];
  }
  int z = max(0,n-k);
  ll res = 0;
  sort(h.begin(), h.end());
  rep(i,z){
    res += h[i];
  }
  cout << res << "\n";
  return 0;
}
