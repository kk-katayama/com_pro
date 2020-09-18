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
  int h,w,m; cin >> h >> w >> m;
  vector<ll> x(m),y(m);
  rep(i,m) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  vector<pi> xx(h,{0,0}), yy(w,{0,0});
  rep(i,h) xx[i].S = i;
  rep(i,w) yy[i].S = i;  
  rep(i,m) {
    xx[x[i]].F--;
    yy[y[i]].F--;
  }

  sort(xx.begin(), xx.end());
  sort(yy.begin(), yy.end());
  ll cnx = 0, cny = 0;
  set<int> stx, sty;
  while(cnx < xx.size() && xx[0].F == xx[cnx].F) {
    stx.insert(xx[cnx].S);
    cnx++;
  }
  while(cny < yy.size() && yy[0].F == yy[cny].F) {
    sty.insert(yy[cny].S);
    cny++;
  }  

  if(cnx * cny > m) cout << - xx[0].F - yy[0].F << "\n";
  else {
    ll cnt = 0;
    rep(i,m) {
      if(stx.find(x[i]) != stx.end() && sty.find(y[i]) != sty.end()) {
	cnt++;
      }
    }
    if(cnt >= cnx*cny) cout << - xx[0].F - yy[0].F - 1 << "\n";
    else cout << - xx[0].F - yy[0].F << "\n";
  }
  return 0;
}
