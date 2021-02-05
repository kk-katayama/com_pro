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
  int n; cin >> n;
  int m = n;
  while(m % 2 == 0) {
    m /= 2;
  }
  if(m == 1) cout << "No" << "\n";
  else {
    cout << "Yes" << "\n";
    if(n % 2 == 1) {
      for (int i = 3; i <= n; i += 2) {
	cout << 1 << " " << i << "\n";
	cout << 1 << " " << i-1+n << "\n";
	cout << i-1 << " " << i << "\n";
	cout << i-1+n << " " << i+n << "\n";	
      }
      cout << n+1 << " " << 2*n << "\n";
    }
    else {
      int a = 2;
      while( a*2 < n ) a *= 2;
      int b = n - a;
      cout << a << " " << a+1 << "\n";
      cout << a << " " << 2*n << "\n";
      cout << a << " " << b << "\n";
      cout << b << " " << n << "\n";
      cout << b << " " << b+1 << "\n";
      cout << b+1 << " " << 1 << "\n";
      cout << 1 << " " << b+n << "\n";
      cout << b+n << " " << b+n+1 << "\n";
      cout << b+n+1 << " " << 1+n << "\n";
      cout << b+n+1 << " " << a+n+1 << "\n";
      cout << a+n << " " << a+n+1 << "\n";
      for (int i = 3; i < n; i += 2) {
	if(i == a+1 || i == b+1) continue;
	cout << 1 << " " << i << "\n";
	cout << 1 << " " << i-1+n << "\n";
	cout << i-1 << " " << i << "\n";
	cout << i-1+n << " " << i+n << "\n";	
      }
    }
  }
  
  return 0;
}
