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
  vi d1(n), d2(n);
  rep(i,n) cin >> d1[i] >> d2[i];

  bool f = false;
  rep(i,n) {
    if(i + 2 >= n) break;
    if(d1[i] == d2[i] && d1[i+1] == d2[i+1] && d1[i+2] == d2[i+2]) {
      f = true;
    }
  }
  cout << (f ? "Yes" : "No") << "\n";

  
  return 0;
}
