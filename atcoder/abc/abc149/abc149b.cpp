#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll a,b,k;
  cin >> a >> b >> k;
  if(k>=a){
    cout << 0 << " ";
    ll res = max(0LL,b-(k-a));
    cout << res << "\n";    
  }
  else{
    cout << a-k << " ";
    cout << b << "\n";    
  }
  return 0;
}
