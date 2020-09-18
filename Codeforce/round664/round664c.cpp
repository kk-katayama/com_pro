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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n,m; cin >> n >> m;
  vector<int> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];

  int lb = -1, ub = (1 << 9);
  while(ub - lb > 1) {
    int mid = (ub + lb) / 2;
    bool f = true;
    rep(i,n) {
      bool ff = false;
      rep(j,m) {
	int c = a[i] & b[j];
	bool fff = true;
	rep(k,10) {
	  if(((mid >> k) & 1) == 0 && ((c >> k) & 1) == 1) fff = false;
	}
	if(fff) {
	  ff = true;
	  break;
	}
      }
      if(!ff) f = false;
    }
    (f ? ub : lb) = mid;
  }
  cout << ub << "\n";
  
  return 0;
}
