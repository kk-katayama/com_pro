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
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }

  ll res = a[0]-1;
  ll mx = 1;
  rep1(i,n-1){
    res += (a[i]-1)/(mx+1);
    if(a[i]==mx+1){
      mx++;
    }
  }

  cout << res << "\n";
  
  return 0;
}
