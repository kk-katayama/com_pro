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
  int n,k; cin >> n >> k;
  if(n % 2 == 0) {
    if(k <= n/2) {
      int s = k + n + n/2 - 1;
      int x = k;
      int c = k + 2*n;
      for (int i = s; i >= k+n; --i) {
	cout << x << " " << i << " " << c << "\n";
	x++;
	cout << x << " " << i + n/2 << " " << c+n/2 << "\n";
	x++;
	c++;
      }
    }
    else cout << -1 << "\n";
  }
  else {
    if(k <= (n+1)/2) {
      int s = k + n + n/2 - 1;
      int x = k + 1;
      int c = k + 2*n;
      for (int i = s; i >= k+n; --i) {
	cout << x << " " << i << " " << c << "\n";
	x++;
	cout << x << " " << i + n/2 << " " << c+(n+1)/2 << "\n";
	x++;
	c++;
      }
      cout << k << " " << k + 2*n - 1 << " " << k + 2*n + n/2 << "\n";
    }
    else cout << -1 << "\n";    
  }
  return 0;
}
