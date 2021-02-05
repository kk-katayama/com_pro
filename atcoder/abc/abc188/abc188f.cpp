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
  ll x,y; cin >> x >> y;
  if(x >= y) cout << x - y << "\n";
  else {
    map<ll,ll> dp;
    queue<ll> q;
    q.push(y);
    ll res = infll;
    while( !q.empty() ) {
      ll num = q.front(); q.pop();
      if(num <= x) {
	chmin(res, dp[num] + x - num);
	continue;
      }
      chmin(res, dp[num] + num - x);
      if(num % 2 == 0) {
	if(dp[num/2] == 0) {
	  dp[num/2] = dp[num]+1;
	  q.push(num/2);	  	  
	}
	else if(chmin(dp[num/2], dp[num]+1)) {
	  q.push(num/2);	  	  
	}
      }
      else {
	if(dp[num/2] == 0) {
	  dp[num/2] = dp[num]+2;
	  q.push(num/2);	  
	}
	else if(chmin(dp[num/2], dp[num]+2)) {
	  q.push(num/2);	  	  
	}
	if(dp[num/2+1] == 0) {
	  dp[num/2+1] = dp[num]+2;
	  q.push(num/2+1);		  
	}
	else if(chmin(dp[num/2+1], dp[num]+2)) {
	  q.push(num/2+1);		  	  
	}
      }
    }
    cout << res << "\n";
  }
  return 0;
}
