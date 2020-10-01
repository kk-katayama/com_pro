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
  vi a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  vi res(n);
  int j = 1;
  rep(i,n/2) {
    res[j] = a[i];
    j += 2;
  }
  j = 0;
  rep(i,n-n/2) {
    res[j] = a[n/2 + i];
    j += 2;
  }

  int cnt = 0;
  rep(i,n) {
    if(i-1 < 0 || i+1 >= n) continue;
    if(res[i] < res[i-1] && res[i] < res[i+1]) cnt++;
  }
  cout << cnt << "\n";
  rep(i,n) cout << res[i] << " ";
  cout << "\n";
  return 0;
}
