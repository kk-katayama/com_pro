#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];

  rep(i,n){
    if(x[i]-y[i]==1) cout << "NO" << "\n";
    else cout << "YES" << "\n";
  }
  return 0;
}
