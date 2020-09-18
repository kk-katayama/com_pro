#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <limits>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vii = vector<vi>;
using vl = vector<ll>; using vll = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  ll n; cin >> n;
  if(n == 1) {cout << 1 << "\n";return 0;}
  ll t = 2;

  auto f = [](ll x) {
	     ll res = 0;
	     ll y = 0;
	     for(;;) {
	       res += x;
	       if( (x + y) % 2 == 1) break;
	       ll tmp = x;
	       x = (x + y) / 2;
	       y = tmp;
	     }
	     return res;
	   };

  ll res = 0;
  while(t <= n){
    ll x = n / t * t;
    chmax(res, f(x));
    t *= 2;
  }
  cout << res << "\n";
  
  return 0;
}
