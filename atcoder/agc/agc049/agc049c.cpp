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
  ll n; cin >> n;
  vl a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  vl d(n,1);
  for (int i = n-2; i >= 0; --i) {
    if(a[i+1] == a[i] + 1) {
      d[i] = d[i+1] + 1;
    }
  }
  
  ll mn = infll/2;
  ll res = infll/2;
  ll sum = 0;
  for (int i = n - 1; i >= 0; --i) {
    if(a[i] - b[i] > 0) {
      chmin(mn, a[i] - b[i]);
      //      chmin(res, sum + a[0] - 1 - b[i]);
    }
    else {
      chmin(res, sum + b[i] - a[i] + 1);
      if(mn <= a[i]) continue;
      if(mn == infll/2 || d[i] == 1) {
	sum++;
      }
      else {
	sum += mn - a[i];	
      }
      mn = a[i];
    }
  }

  cout << min(res, sum) << "\n";
  
  return 0;
}
