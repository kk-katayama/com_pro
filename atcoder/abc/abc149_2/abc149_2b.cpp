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
  if(a<=k){
    k -= a;
    a = 0;
    b = max((ll)0,b-k);
  }
  else a -= k;
  cout << a << " " << b << "\n";
  
  return 0;
}
