#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
int main()
{
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll x = 0;
  for (int i = 2; i < n; ++i) {
    x ^= a[i];
  }

  vector<ll> u,v;
  ll pow2 = 1;
  ll usum = 0, vsum = 0;
  ll inf = (1LL << 60);
  vector<bool> f(65, false);
  rep(i,46) {
    if((((a[0] ^ a[1]) >> i) & 1) == ((x >> i) & 1)) {
      if(usum + 1 == pow2 - vsum) {
	u.push_back(0);
	v.push_back(inf);
	f[i] = true;
      }
      else {
	u.push_back(0);
	v.push_back(usum + 1);
      }
    }
    else {
      if(usum + 1 == pow2 - vsum) {
	cout << -1 << "\n";
	return 0;
      }
      else {
	u.push_back(usum + 1);
	v.push_back(pow2 - vsum);
      }      
    }
    if(u[i] > v[i]) swap(u[i], v[i]);
    if((a[0] >> i) & 1) usum += pow2;
    if((a[1] >> i) & 1) vsum += pow2;
    pow2 *= 2;
  }
  

  ll maxi = 0, mini = inf;
  ll idx = -1;
  vector<ll> p(60);
  p[0] = 1;
  rep(i,59) {
    p[i+1] = p[i] * 2;
  }
  //  rep(i,u.size()) cout << u[i] << ":" << v[i] << ":" << p[i] << "\n";  
  rep(i,u.size()) {
    if(f[i]) continue;
    ll uu = u[i];
    while(a[0] > uu) {
      bool flag = true;
      rep(j,u.size()) {
	if(i == j) continue;
	if(f[j]) continue;
	ll xx = (uu - u[j]) / p[j];
	if(uu - u[j] < 0) flag = false;
	if(uu < u[j] + p[j]*xx || v[j] + p[j]*xx <= uu) flag = false;
      }
      if(flag) chmin(mini, uu);
      uu += p[i];
    }
  }
  if(mini == inf) cout << -1 << "\n";
  else cout << mini << "\n";
  cout << ((a[0] - mini) ^ (a[1] + mini)) << "\n";
  cout << x << "\n";
  return 0;
}
