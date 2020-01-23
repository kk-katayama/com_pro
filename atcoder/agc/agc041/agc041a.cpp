#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,a,b;
  cin >> n >> a >> b;

  if((b-a)%2==0){
    cout << (b-a)/2 << "\n";
  }
  else{
    ll c = n-b+1+(b-a-1)/2;
    ll d = a + (b-a-1)/2;
    ll res = min(c,d);
    cout << res << "\n";
  }
  return 0;
}
