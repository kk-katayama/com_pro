#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll n,a,b;cin >> n >> a >> b;
  ll res = b*(n-1)+a - (a*(n-1)+b) + 1;
  cout << (ll)max((ll)0 , res) << "\n";
  return 0;
}
