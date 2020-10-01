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
#define rep(i,n) for(ll i = 0; i < n; ++i)
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
  ll n,x,m; cin >> n >> x >> m;
  vl sum(m*2, 0);
  vector<ll> table(m*2, -1);
  ll idx = -1;
  rep(i,n) {
    sum[i+1] = sum[i] + x;
    if(table[x] != -1) {
      idx = i;
      break;
    }
    table[x] = i;
    x = (x*x) % m;
  }
  if(idx == -1) {
    cout << sum[n] << "\n";
  }
  else if(table[0] != -1) {
    cout << sum[idx] << "\n";
  }
  else if(table[1] != -1) {
    ll res = sum[idx] + n - idx;
    cout << res << "\n";
  }
  else {
    ll res = (n - table[x])/(idx - table[x]) * (sum[idx] - sum[table[x]]) + sum[(n - table[x]) % (idx - table[x]) + table[x]] - sum[table[x]] + sum[table[x]]; 
    cout << res << "\n";
  }

  return 0;
}
