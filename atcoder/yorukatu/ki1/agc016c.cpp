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
template<class T> inline T Ceil2(T y, T x) { if(x == 0) return -1;  return (y + x - 1) / x; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
int main()
{
  ll h,w,a,b; cin >> h >> w >> a >> b;
  if(h % a == 0 && w % b == 0) {
    cout << "No" << "\n";
  }
  else {
    cout << "Yes" << "\n";
    if(w % b != 0) {
      vl sum(w+1, -1000);
      int x = 0;
      for (int i = 0; i < w; i += b) {
	sum[i] = x--;
      }
      for (int i = w; i >= 0; --i) {
	if(sum[i] != -1000) continue;
	x = 1;
	for (int j = i; j >= 0; j -= b) {
	  sum[j] = x++;
	}	
      }
      rep(i,h) {
	rep(j,w) {
	  cout << sum[j+1] - sum[j] << " ";
	}
	cout << "\n";
      }
    }
    else {
      vl sum(h+1, -1000);
      int x = 0;
      for (int i = 0; i < h; i += a) {
	sum[i] = x--;
      }
      for (int i = h; i >= 0; --i) {
	if(sum[i] != -1000) continue;
	x = 1;
	for (int j = i; j >= 0; j -= a) {
	  sum[j] = x++;
	}	
      }
      rep(i,h) {
	rep(j,w) {
	  cout << sum[i+1] - sum[i] << " ";
	}
	cout << "\n";
      }
    }
  }
  
  return 0;
}
