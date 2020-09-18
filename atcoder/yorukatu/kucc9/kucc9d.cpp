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
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;
int main()
{
  int n; cin >> n;
  int cnt = 0;
  while(n-- > 0) {
    int x,y,z; cin >> x >> y >> z;
    int m; cin >> m;
    vi a(m),b(m),c(m);
    rep(i,m) cin >> a[i] >> b[i] >> c[i];

    int inf = 1e+9;
    vi buf(6, inf);
    rep(i,m) {
      chmin(buf[0], a[i]);
      chmin(buf[1], b[i]);
      chmin(buf[2], c[i]);
      chmin(buf[3], x - 1 - a[i]);
      chmin(buf[4], y - 1 - b[i]);
      chmin(buf[5], z - 1 - c[i]);      
    }
    
    rep(i,6) {
      cnt = cnt ^ buf[i];
    }
  }
  cout << (cnt == 0 ? "LOSE" : "WIN") << "\n";
  return 0;
}
