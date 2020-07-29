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
  ll n,m; cin >> n >> m;
  vector<ll> x(m);
  rep(i,m) cin >> x[i];

  auto isok = [&](ll k)-> bool{
		ll left = 0;
		rep(i,m) {
		  if(x[i] <= left) {
		    left = max(x[i] + k, left);
		  }
		  else {
		    if(k < x[i] - left - 1) return false;
		    else {
		      ll y = x[i] - left - 1;
		      ll tmp = max(k - 2*y, (k - y) / 2);
		      left = x[i] + tmp;
		    }
		  }
		}
		return left >= n;
	      };


  
  ll lb = -1, ub = 2*n;
  while(ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    (isok(mid) ? ub : lb) = mid;
  }
  cout << ub << "\n";
  
  return 0;
}
