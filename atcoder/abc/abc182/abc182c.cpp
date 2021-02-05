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
  ll n; cin >> n;
  vl a;
  while(n > 0) {
    a.push_back(n % 10);
    n /= 10;
  }

  int m = sz(a);
  map<int,int> mp;
  int sum = 0;
  rep(i,m) {
    a[i] %= 3;
    mp[a[i]]++;
    sum += a[i];
  }

  if(sum % 3 == 0) cout << 0 << "\n";
  if(sum % 3 == 1) {
    if(mp[1] >= 1 && m > 1) cout << 1 << "\n";
    else if(mp[2] >= 2 && m > 2) cout << 2 << "\n";
    else cout << -1 << "\n";
  }
  if(sum % 3 == 2) {
    if(mp[2] >= 1 && m > 1) cout << 1 << "\n";
    else if(mp[1] >= 2 && m > 2) cout << 2 << "\n";
    else cout << -1 << "\n";    
  }  
  
  
  return 0;
}
