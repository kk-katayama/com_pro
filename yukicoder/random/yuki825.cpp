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

  int res = -1;
  rep1(x, 220) {
    rep(i,a+1){
      rep(j,b+1) {
	int y = i + 10*j;
	if(x > y) continue;
	int cnt = a - i + b - j;
	cnt += (y - x) / 10 + (y - x) % 10;
	if(cnt == c) {
	  res = x;
	  goto FIN;
	}
      }
    }
  }

 FIN:
  if(res == -1) cout << "Impossible" << "\n";
  else cout << res << "\n";
  
  return 0;
}
