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
  ll a,b,c,d; cin >> a >> b >> c >> d;
  if(a == c && b == d) {
    cout << 0 << "\n";
  }
  else if(abs(a-c) + abs(b-d) <= 3) {
    cout << 1 << "\n";
  }
  else {
    ll w1 = a+b, w2 = c+d, s1 = a-b, s2 = c-d;
    if(w1 == w2 || s1 == s2) cout << 1 << "\n";
    else if(abs(a-c) + abs(b-d) <= 6) {
      cout << 2 << "\n";
    }      
    else if((w1 + s2) % 2 == 0 || (w2 + s1) % 2 == 0) {
      cout << 2 << "\n";
    }
    else if(abs(w1 - w2) <= 3 || abs(s1 - s2) <= 3) {
      cout << 2 << "\n";
    }
    else cout << 3 << "\n";
  }
  return 0;
}
