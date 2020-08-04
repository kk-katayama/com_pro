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
using ld = long double;
int main()
{
  int n,k; cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int lb = 0, ub = 1e+9+1;
  while(ub - lb > 1) {
    int mid = (ub + lb) / 2;
    int cnt = 0;
    rep(i,n) {
      cnt += (a[i] - 1) / mid;
    }
    (cnt <= k ? ub : lb) = mid;
  }
  cout << ub << "\n";
  return 0;
}
