#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
typedef long long ll;
int main()
{
  ll h,w;cin >> h >> w;
  if(h==1||w==1) cout << 1 << "\n";
  else {
    //    ll res = (h*w+(ll)1)/2;
    ll res = ((h+1)/2)*((w+1)/2)+(h/2)*(w/2);
    cout << res << "\n";
  }
  return 0;
}
