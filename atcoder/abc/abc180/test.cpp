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
template<class T> inline int sz(T &a) { return a.size(); }
template<class T> inline T Ceil2(T &y, T &x) { if(x == 0) return -1;  return (y + x - 1) / x; } // ceil(y/x)
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{

  
  rep1(i,100) {
    rep1(j,100) {
      rep1(k,10000) {
	if( (i*j > k) != (i > k/j) ) cout << "!1" << "\n";
	if( (i*j >= k) != (i >= Ceil2(k, j))) cout << "!2" << "\n";
	if( (i*j < k) != (i < Ceil2(k, j))) cout << "!3" << "\n";	
	// if( (i*j >= k) != (i >= (k+j-1)/j) ) cout << "!2" << "\n";
        // if( (i*j < k) != (i < (k+j-1)/j) ) cout << "!3" << "\n";
	if( (i*j <= k) != (i <= k/j) ) cout << "!4" << "\n";	
      }
    }
  }

  
  return 0;
}
