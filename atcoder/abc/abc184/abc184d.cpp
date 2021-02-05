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
  int a,b,c; cin >> a >> b >> c;
  vector<vector<vector<ld>>> dp(110, vector<vector<ld>>(110, vector<ld>(110, -1)));
  //  dp[a][b][c] = 0;
  auto rec = [&](auto self, int x, int y, int z)-> ld{
    if(dp[x][y][z] != -1) return dp[x][y][z];
    if(x >= 100 || y >= 100 || z >= 100) return dp[x][y][z] = 0;
    ld res = 1;
    ld sum = x+y+z;
    res += self(self, x+1, y, z)/sum*(ld)(x);
    res += self(self, x, y+1, z)/sum*(ld)(y);
    res += self(self, x, y, z+1)/sum*(ld)(z);
    return dp[x][y][z] = res;
  };
  ld ans = rec(rec, a, b, c);
  printf("%.10Lf\n", ans);
  return 0;
}
