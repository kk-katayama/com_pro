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
  int t; cin >> t;
  while(t-- > 0) {
    int n; cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];

    int cnt = 0;
    rep(i,n) {
      if(a[i] == 0) cnt++;
    }
    if(cnt >= n/2) {
      cout << n/2 << "\n";
      rep(i,n/2) cout << 0 << " ";
      cout << "\n";
    }
    else {
      int m = (n-cnt)/2 * 2;
      cout << m << "\n";
      rep(i,m) cout << 1 << " ";
      cout << "\n";
    }
  }
  return 0;
}
