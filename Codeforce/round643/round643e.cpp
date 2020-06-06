#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  ll n;cin >> n;
  ll a,r,m; cin >> a >> r >> m;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];

  sort(h.begin(), h.end());
  ll ac = 0, rc = 0, mc = 0;
  ll sum = 0;
  rep(i,n) {
    rc += h[i] - h[0];
    sum += h[i];
  }
  
  auto score = [&]()-> ll{
		 return ac*a + rc*r + mc*m;
	       };

  ll res = 1e+15;
  rep(i,n) {
    chmin(res, score());
    if(i == n-1) break;
    ac += (i+1)*(h[i+1]-h[i]);
    rc -= (n-(i+1))*(h[i+1]-h[i]);
  }
  
  ll ave = sum / n;
  ac = rc = mc = 0;
  ll cp = 0, cm = 0;
  rep(i,n) {
    cp += max((ll)0, h[i] - ave);
    cm += max((ll)0, ave - h[i]);
  }
  mc = min(cp, cm);
  (cp >= cm ? rc : ac) = abs(cp - cm);
  chmin(res, score());
  ave++;
  
  ac = rc = mc = 0;
  cp = cm = 0;
  rep(i,n) {
    cp += max((ll)0, h[i] - ave);
    cm += max((ll)0, ave - h[i]);
  }
  mc = min(cp, cm);
  (cp >= cm ? rc : ac) = abs(cp - cm);
  chmin(res, score());

  cout << res << "\n";
  
  return 0;
}
