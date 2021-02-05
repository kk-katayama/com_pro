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
  int n,m,t; cin >> n >> m >> t;
  vi a(m),b(m);
  rep(i,m) cin >> a[i] >> b[i];

  int time = 0;
  int bat = n;
  rep(i,m) {
    bat -= (a[i] - time);
    if(bat <= 0) {
      cout << "No" << "\n";
      return 0;
    }
    bat = min(n, bat + b[i] - a[i]);
    time = b[i];
  }

  bat -= (t - time);
  cout << (bat > 0 ? "Yes" : "No") << "\n";

    
  
  return 0;
}
