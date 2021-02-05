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
  string s; cin >> s;
  map<pi,ll> mp;
  vl suma(n+1, 0), sumt(n+1,0), sumc(n+1,0), sumg(n+1,0);
  mp[{0,0}]++;
  ll res = 0;
  rep(i,n) {
    if(s[i] == 'A') suma[i+1]++;
    if(s[i] == 'T') sumt[i+1]++;
    if(s[i] == 'C') sumc[i+1]++;
    if(s[i] == 'G') sumg[i+1]++;
    suma[i+1] += suma[i];
    sumt[i+1] += sumt[i];
    sumc[i+1] += sumc[i];
    sumg[i+1] += sumg[i];
    res += mp[{suma[i+1] - sumt[i+1], sumc[i+1] - sumg[i+1]}];
    mp[{suma[i+1] - sumt[i+1], sumc[i+1] - sumg[i+1]}]++;
  }
  cout << res << "\n";
  return 0;
}
