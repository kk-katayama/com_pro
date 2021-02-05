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
  string s; cin >> s;

  int n = sz(s);
  vl a(n+1, 0);
  rep(i,n) {
    if(s[i] == '<') {
      if(i != 0 && s[i-1] == '>') chmax(a[i+1], (ll)1);
      else if(i == 0) {
	a[i] = 0;
	a[i+1] = 1;
      }
      else {
	a[i+1] = a[i] + 1;
      }
    }
  }

  for (int i = n-1; i >= 0; --i) {
    if(s[i] == '>') {
      if(i != n-1 && s[i+1] == '<') chmax(a[i], (ll)1);
      else if(i == n-1) {
	a[i+1] = 0;
	chmax(a[i], (ll)1);
      }
      else {
	chmax(a[i], a[i+1] + 1);
      }
    }    
  }


  ll sum = 0;
  rep(i,n+1) {
    sum += a[i];
  }
  cout << sum << "\n";
  
  return 0;
}
