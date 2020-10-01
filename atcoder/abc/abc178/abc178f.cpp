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
  int n; cin >> n;
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  int m = 0;
  rep1(i,n) {
    int lb = -1, ub = a.size();
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (a[mid] <= i ? lb : ub) = mid;
    }
    int amax = lb;
    lb = -1; ub = b.size();
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (b[mid] >= i ? ub : lb) = mid;
    }
    int bmin = ub;
    chmax(m, amax - bmin + 1);
  }

  vi c(n);
  rep(i,n) {
    c[i] = b[(i+m)%n];
  }

  bool f = false;
  rep(i,n) {
    if(a[i] == c[i]) f = true;
  }

  if(f) cout << "No" << "\n";
  else {
    cout << "Yes" << "\n";
    rep(i,n) cout << c[i] << " ";
    cout << "\n";
  }
  return 0;
}
