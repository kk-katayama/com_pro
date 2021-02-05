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
#define rep(i,n) for(ll i = 0; i < n; ++i)
#define rep1(i,n) for(ll i = 1; i <= n; ++i)
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
  int n; cin >> n;
  string s; cin >> s;
  string t; cin >> t;

  int l = 0;
  while(l < n && s[l] == t[l]) l++;
  
  int cnts = 0, cntt = 0;
  rep(i,n) if(s[i] == '1') cnts++;
  rep(i,n) if(t[i] == '1') cntt++;
  
  if(cnts < cntt) {
    cout << -1 << "\n";
    return 0;
  }

  if((cnts - cntt) % 2 != 0) {
    cout << -1 << "\n";
    return 0;
  }

  ll s1 = 0, t1 = 0;
  bool f = false;
  ll id;
  ll res = 0;
  queue<ll> q;
  rep(i,n) {
    if(t[i] == '1') {
      q.push(i);
    }
    if(s[i] == '1') {
      if(f) {
	res += i - id;
	f = false;
      }
      else if( q.empty() ) {
	f = true;
	id = i;
      }
      else {
	ll idx = q.front(); q.pop();
	res += i - idx;
      }
    }
  }
  if(q.empty()) cout << res << "\n";
  else cout << -1 << "\n";
  
  return 0;
}



