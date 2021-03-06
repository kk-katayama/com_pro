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
  vi p(n);
  rep(i,n) {
    cin >> p[i];
    p[i]--;
  }

  vi a(n, 1);
  int M = 20000;
  rep(i,n-1) {
    a[i+1] = a[i] + M;
  }
  vi b = a;
  reverse(b.begin(), b.end());

  rep(i,n) {
    a[p[i]] += i;
    b[p[i]] += i;
  }

  rep(i,n) cout << a[i] << " ";
  cout << "\n";
  rep(i,n) cout << b[i] << " ";
  cout << "\n";
  return 0;
}
