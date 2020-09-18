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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n,m,x,y;
  cin >> n >> m >> x >> y;
  int sx = x;
  rep(i,n) {
    rep(j,m) {
      cout << x << " " << y << "\n";
      y++;
      if(j == m-1) {
	y--;
	continue;
      }
      if(y == m+1) y = 1;
    }
    x++;
    if(x == sx) x++;
    if(x == n+1) x = 1;
  }
  return 0;
}
