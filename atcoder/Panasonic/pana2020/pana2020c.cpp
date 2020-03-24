#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll a,b,c;cin >> a >> b >> c;
  ll x = 4*a*b;
  ll y = (c-a-b);
  if(y<0){
    cout << "No" << "\n";
    return 0;
  }
  if(x<y*y) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
