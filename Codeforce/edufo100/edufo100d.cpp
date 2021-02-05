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
  int q; cin >> q;
  while(q-- > 0) {
    int n; cin >> n;
    vi a(n);
    rep(i,n) scanf("%d", &a[i]);
    int l = 0;
    vi b;
    rep(i,n) {
      for (int j = l+1; j < a[i]; ++j) {
	b.push_back(j);
      }
      l = a[i];
    }
    for (int j = l+1; j <= 2*n; ++j) {
      b.push_back(j);
    }    
    int mx = 0, mn = n;
    int lb = -1, ub = n;
    rep(i,n) {
      while(ub - lb > 1) {
	int mid = (ub + lb)/2;
	(a[i] < b[mid] ? ub : lb) = mid;
      }
      if(ub < n) {
	mx++;
	lb = ub;
	ub = n;
      }
      else break;
    }
    lb = -1; ub = n;
    for (int i = n-1; i >= 0; --i) {
      while(ub - lb > 1) {
	int mid = (ub + lb)/2;
	(b[mid] < a[i] ? lb : ub) = mid;
      }
      if(0 <= lb) {
	mn--;
	ub = lb;
	lb = -1;
      }
      else break;      
    }
    cout << mx - mn + 1 << "\n";
  }
  return 0;
}
