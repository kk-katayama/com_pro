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
#define sz(v) (int)v.size()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  vl ten(20);
  ten[0] = 1;
  rep(i,19) {
    ten[i+1] = ten[i] * 10;
  }
  
  int t; cin >> t;
  while(t-- > 0) {
    ll n, s; cin >> n >> s;
    ll d = 0;
    vl b;
    while(n > 0) {
      d += n % 10;
      b.push_back(n % 10);
      n /= 10;
    }
    if(d <= s) {
      cout << 0 << "\n";
    }
    else {
      b.push_back(0);
      ll res = 0;
      rep(i,sz(b)-1) {
	res += (10 - b[i]) * ten[i];
	d -= b[i] - 1;
	if(d <= s) break;
	b[i+1]++;
      }
      cout << res << "\n";
    }
  }
  return 0;
}
