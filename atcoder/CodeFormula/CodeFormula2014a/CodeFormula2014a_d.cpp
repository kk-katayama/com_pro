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
  string s; cin >> s;
  string k; cin >> k;

  auto conv = [](char c)->int{
    int x = c - '0';
    if(0 <= x && x <= 9) return x;
    else {
      int res = c - 'a' + 10;
      return res;
    }
  };

  vi table(36, 0);
  rep(i,sz(k)) {
    int x = conv(k[i]);
    table[x] = 1;
  }

  ld res = 0;
  vi table2(36, 0);
  int cnta = 0, cntb = 0;;
  rep(i,sz(s)) {
    int x = conv(s[i]);
    if(table[x] || table2[x]) {
      res += 1;
    }
    else {
      table2[x] = 1;
      cnta++;
    }
  }

  rep(i,36) if(!table[i]) cntb++;

  vector<vector<ld>> dp(cnta+1, vector<ld>(cntb+1, -1));
  
  auto rec = [&](auto self, int a, int b)->ld{
    if(dp[a][b] >= 0) return dp[a][b];
    if(a == 0) return dp[a][b] = 0;
    ld ans = 0;
    ans += (self(self, a-1, b-1) + 1)/(ld)b;
    ans += (self(self, a-1, b-1) + 3)*(ld)(a-1)/(ld)b;
    if(a != b) ans += (self(self, a, b-1) + 2)*(ld)(b-a)/(ld)b;
    return dp[a][b] = ans;
  };

  res += rec(rec, cnta, cntb);
  printf("%.10Lf\n", res);
  
  return 0;
}
