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
    int n,x; cin >> n >> x;
    int sum = 0;
    bool f = true;
    bool ff = false;
    rep(i,n) {
      int a; cin >> a;
      if(x != a) f = false;
      else ff = true;
      sum += a;
    }
    if(f) cout << 0 << "\n";
    else if(sum % n == 0 && sum/n == x) {
      cout << 1 << "\n";
    }
    else if(ff) cout << 1 << "\n";
    else cout << 2 << "\n";
  }
  return 0;
}
