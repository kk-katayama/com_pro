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
  vl a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  vector<pl> odd, even;
  rep(i,n) {
    if(i & 1) odd.push_back({a[i], b[i]});
    else even.push_back({a[i], b[i]});
  }

  sort(odd.begin(), odd.end(), [](pl a, pl b){
    return a.first - a.second > b.first - b.second;
  });
  sort(even.begin(), even.end(), [](pl a, pl b){
    return a.first - a.second > b.first - b.second;
  });  

  vl oddbsum(n/2+1, 0), evenbsum(n/2+1, 0);
  rep(i,n/2) {
    oddbsum[i+1] = oddbsum[i] + odd[i].second;
    evenbsum[i+1] = evenbsum[i] + even[i].second;    
  }

  ll res = 0;
  ll sum = 0;
  rep(i,n/2+1) {
    chmax(res, sum + oddbsum[n/2] - oddbsum[i] + evenbsum[n/2] - evenbsum[i]);
    if(i < n/2) sum += odd[i].first + even[i].first;
  }
  cout << res << "\n";
  return 0;
}
