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
  ll n,k; cin >> n >> k;
  vl a(k);
  rep(i,k) cin >> a[i];

  rep(i,k) {
    rep(j,k) {
      if(i >= j) continue;
      if(a[i] + 1 == a[j]) {
	if(a[i] - 1 == 1 || a[i] - 2 == 1 || a[i] - 4 == 1 || a[i] - 7 == 1) {
	}
	else {
	  cout << "No" << "\n";
	  return 0;
	}
      }
      if(a[i] + 3 == a[j]) {
	if(a[i] - 1 == 1 || a[i] - 4 == 1) {
	}
	else {
	  cout << "No" << "\n";
	  return 0;
	}	
      }
      if(a[i] + 5 == a[j]) {
	if(a[i] - 2 == 1 || a[i] - 3 == 1 || a[i] - 5 == 1 || a[i] - 8 == 1) {
	}
	else {
	  cout << "No" << "\n";
	  return 0;
	}		
      }
    }
  }
  cout << "Yes" << "\n";
  return 0;
}
