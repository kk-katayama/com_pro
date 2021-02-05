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
#include <cassert>
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
  int k; cin >> k;
  int x,y; cin >> x >> y;
  int a = abs(x), b = abs(y);

  if(k % 2 == 0 && (a + b) % 2 == 1) {
    cout << -1 << "\n";
    return 0;
  }

  if((a + b) % k == 0) {
    vi resx, resy;
    while(a != 0 || b != 0) {
      if(a >= k) {
	resx.push_back(k);
	resy.push_back(0);
	a -= k;
      }
      else if(a > 0) {
	resx.push_back(a);
	resy.push_back(k-a);
	b -= k-a;	
	a = 0;
      }
      else {
	resx.push_back(0);
	resy.push_back(k);
	b -= k;	
      }
    }
    int ca = (x >= 0 ? 1 : -1);
    int cb = (y >= 0 ? 1 : -1);
    cout << sz(resx) << "\n";
    int nx = 0, ny = 0;
    rep(i,sz(resx)) {
      nx += ca*resx[i];
      ny += cb*resy[i];
      cout << nx << " " << ny << "\n";
    }
    return 0;
  }

  if(a + b < k) {
    vi resx,resy;    
    if((a + b) % 2 == 1) {
      resx.push_back(a);
      resy.push_back(k-a);
      b -= k-a;
      a = 0;
      b = -b;
      int c = (a + b) / 2;
      resy.push_back(-c);
      resx.push_back((k-c));
      resy.push_back(-(b-c));
      resx.push_back((b-c)-k);            
    }
    else {
      if(a > b) {
	int c = (a + b) / 2;
	resx.push_back(c);
	resy.push_back(-(k-c));
	resx.push_back(a-c);
	resy.push_back(k-(a-c));      
      }
      else {
	int c = (a + b) / 2;
	resy.push_back(c);
	resx.push_back(-(k-c));
	resy.push_back(b-c);
	resx.push_back(k-(b-c));      
      }
    }
    int ca = (x >= 0 ? 1 : -1);
    int cb = (y >= 0 ? 1 : -1);
    cout << sz(resx) << "\n";
    int nx = 0, ny = 0;
    rep(i,sz(resx)) {
      nx += ca*resx[i];
      ny += cb*resy[i];
      //      cout << ca*resx[i] << " " << cb*resy[i] << "\n";
      cout << nx << " " << ny << "\n";
    }
    
    return 0;
  }

  {
    int m = (a+b+k-1)/k;
    if(k % 2 == 1 && (m % 2 != (a+b) % 2)) m++;
    vi resx,resy;
    rep(i,m-2) {
      if(a >= k) {
	resx.push_back(k);
	resy.push_back(0);
	a -= k;
      }
      else if(a > 0) {
	resx.push_back(a);
	resy.push_back(k-a);
	b -= k-a;	
	a = 0;
      }
      else {
	resx.push_back(0);
	resy.push_back(k);
	b -= k;	
      }
    }
    assert((a+b) % 2 == 0);
    if(a > b) {
      int c = (a + b) / 2;
      resx.push_back(c);
      resy.push_back(-(k-c));
      resx.push_back(a-c);
      resy.push_back(k-(a-c));      
    }
    else {
      int c = (a + b) / 2;
      resy.push_back(c);
      resx.push_back(-(k-c));
      resy.push_back(b-c);
      resx.push_back(k-(b-c));      
    }
    int ca = (x >= 0 ? 1 : -1);
    int cb = (y >= 0 ? 1 : -1);
    cout << sz(resx) << "\n";
    int nx = 0, ny = 0;
    rep(i,sz(resx)) {
      nx += ca*resx[i];
      ny += cb*resy[i];
      //      cout << ca*resx[i] << " " << cb*resy[i] << "\n";
      cout << nx << " " << ny << "\n";
    }
  }
  
  return 0;
}
