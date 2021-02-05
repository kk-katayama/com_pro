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
template<class T> inline int  sz(T &a) { return a.size(); }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  ll n,m,p; cin >> n >> m >> p;
  vl a(n);
  rep(i,n) cin >> a[i];

  vl c(40, 0);
  vi id(40, -1);
  rep(i,n) {
    int cnt = 0;
    ll tmp = a[i];
    while(tmp % p == 0) {
      tmp /= p;
      cnt++;
    }
    if(chmax(c[cnt], tmp)) {
      id[cnt] = i;
    }
  }

  priority_queue<pl, vector<pl>, greater<pl>> pq;
  map<ll,ll> d;
  d[1] = 1;
  pq.push({1, 1});
  while(!pq.empty()) {
    auto [dd, num] = pq.top(); pq.pop();
    rep(i,40) {
      if(c[i] == 0) continue;
      if(num*a[id[i]] >= m+1) {
	if(d[m+1] == 0 || d[m+1] > dd+1) {
	  d[m+1] = dd+1;
	}
      }
      else if(d[num*c[i]] == 0 || d[num*c[i]] > dd+i+1) {
	d[num*c[i]] = dd+i+1;
	pq.push({dd+i+1, num*c[i]});
      }
    }
  }

  cout << d[m+1]-1 << "\n";
  
  return 0;
}
