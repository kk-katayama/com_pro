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
struct Vec {
  int x,y;
};

int dot(Vec a, Vec b) {
  return a.x*b.x + a.y*b.y;
}

int cross(Vec a, Vec b) {
  return a.x*b.y - a.y*b.x;
}

int main()
{
  ll n; cin >> n;
  vector<Vec> p(n);
  rep(i,n) {
    cin >> p[i].x >> p[i].y;
  }
  
  ll res = 0, res2 = 0;
  rep(i,n) {
    vector<Vec> p2;
    rep(j,n) {
      if(i == j) continue;
      Vec tmp;
      tmp.x = p[j].x - p[i].x;
      tmp.y = p[j].y - p[i].y;      
      p2.push_back(tmp);
    }
    sort(p2.begin(), p2.end(), [&](Vec a, Vec b) {
      //      return atan2(a.y - p[i].y, a.x - p[i].x) < atan2(b.y - p[i].y, b.x - p[i].x);
      return atan2(a.y, a.x) < atan2(b.y, b.x);      
    });
    // cout << p[i].x << ":" << p[i].y << "\n";
    // rep(j,n-1) {
    //   cout << p2[j].x << " " << p2[j].y << "\n";
    // }
    rep(j,n-1) {
      ll lb = j, ub = n-1;
      while(ub - lb > 1) {
	ll mid = (ub+lb)/2;
	if(dot(p2[j],p2[mid]) >= 0 && cross(p2[j],p2[mid]) >= 0) lb = mid;
	else ub = mid;
      }
      ll bot = lb;
      if(bot < n-1 && dot(p2[j], p2[bot]) == 0) res2++;
      lb = j; ub = n-1;
      while(ub - lb > 1) {
	ll mid = (ub+lb)/2;
	if(dot(p2[j],p2[mid]) >= 0 && cross(p2[j],p2[mid]) <= 0) ub = mid;
	else lb = mid;
      }
      ll top = ub;
      if(top < n-1 && dot(p2[j], p2[top]) == 0) res2++;
      //      cout << top << ":" << bot << "\n";
      res += max(ll(0), top - bot - 1);
    }
    //    cout << res2 << "******\n";
  }

  ll ei = n*(n-1)*(n-2)/6 - res - res2;
  cout << ei << " " << res2 << " " << res << "\n";
  
  return 0;
}
