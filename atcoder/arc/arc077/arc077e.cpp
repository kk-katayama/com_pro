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
  ll n,m; cin >> n >> m;
  vl a(n);
  rep(i,n) cin >> a[i];

  vl b(n);
  rep1(i,n-1) {
    b[i] = (a[i] - a[i-1] + m) % m;
  }

  ll sum = 0;
  rep1(i,n-1) {
    sum += min(a[i], b[i]);
  }
  
  vector<pl> imos;
  rep1(i,n-1) {
    if(b[i] <= a[i]) {
      imos.push_back({a[i] - b[i] + 1, -1});
      imos.push_back({a[i], b[i]});
      imos.push_back({a[i] + 1, 1 - b[i]});
    }
    else {
      imos.push_back({1, -1});
      imos.push_back({a[i], b[i]});
      imos.push_back({a[i] + 1, 1 - b[i]});      
      imos.push_back({a[i] + m - b[i] + 1, -1});
    }
  }

  sort(imos.begin(), imos.end());

  ll res = sum;
  ll d = 0;
  int id = 0;
  rep1(i,m-1) {
    while(id < sz(imos) && i == imos[id].first) {
      d += imos[id].second;
      id++;
    }
    sum += d;
    chmin(res, sum);
  }

  cout << res << "\n";
  return 0;
}
