#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll h,w; cin >> h >> w;
  ll res = 1e+15;
  if(h % 3 == 0 || w % 3 == 0) res = 0;
  else res = min(h, w);

  rep1(i,h-1) {
    ll a = i*w;
    ll b = (h - i)*(w/2);
    ll c = (h - i)*((w+1)/2);
    chmin(res, max({a,b,c}) - min({a,b,c}));
  }

  rep1(i,w-1) {
    ll a = i*h;
    ll b = (w - i)*(h/2);
    ll c = (w - i)*((h+1)/2);
    chmin(res, max({a,b,c}) - min({a,b,c}));
  }  

  cout << res << "\n";
  return 0;
}
