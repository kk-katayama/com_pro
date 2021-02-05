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
const ld inf = 1e+9;
const ll infll = numeric_limits<ll>::max();
int main()
{
  int n; cin >> n;
  using pld = pair<ld,ld>;
  vector<pld> u,d,r,l;
  rep(i,n) {
    ld x,y;
    char c;
    cin >> x >> y >> c;
    if(c == 'U') u.push_back({x, y});
    if(c == 'D') d.push_back({x, y});
    if(c == 'L') l.push_back({x, y});
    if(c == 'R') r.push_back({x, y});    
  }

  // t, position, ch
  vector<pair<ld, pair<vector<ld>,int>>> event;
  // xmax
  sort(u.begin(), u.end());
  sort(d.begin(), d.end());
  sort(r.begin(), r.end());
  sort(l.begin(), l.end());
  ld rxmax = (sz(r) == 0 ? -inf : r[sz(r)-1].first);
  ld lxmax = (sz(l) == 0 ? -inf : l[sz(l)-1].first);
  ld udxmax = (sz(u) == 0 ? -inf : u[sz(u)-1].first);
  if(sz(d) != 0) chmax(udxmax, d[sz(d)-1].first);    
  if(rxmax >= lxmax && rxmax >= udxmax) {
    event.push_back( {0, {{rxmax, 1}, 0}} );
  }
  else if(udxmax >= rxmax && udxmax >= lxmax) {
    event.push_back( {0, {{udxmax, 0}, 0}} );
    if(rxmax != -inf) event.push_back( {udxmax - rxmax, {{rxmax, 1}, 0}} );    
  }
  else if(lxmax >= rxmax && lxmax >= udxmax) {
    event.push_back( {0, {{lxmax, -1}, 0}} );
    if(udxmax != -inf && lxmax - udxmax <= (lxmax - rxmax) / 2) {
      event.push_back( {lxmax - udxmax, {{udxmax, 0}, 0}} );
      event.push_back( {udxmax - rxmax, {{rxmax, 1}, 0}} );            
    }
    else if(rxmax != -inf) {
      event.push_back( {(lxmax - rxmax) / 2, {{rxmax, 1}, 0}} );      
    }
  }

  // xmin
  ld rxmin = (sz(r) == 0 ? inf : r[0].first);
  ld lxmin = (sz(l) == 0 ? inf : l[0].first);
  ld udxmin = (sz(u) == 0 ? inf : u[0].first);
  if(sz(d) != 0) chmin(udxmin, d[0].first);  
  if(lxmin <= rxmin && lxmin <= udxmin) {
    event.push_back( {0, {{lxmin, -1}, 1}} );
  }
  else if(udxmin <= rxmin && udxmin <= lxmin) {
    event.push_back( {0, {{udxmin, 0}, 1}} );
    if(lxmin != inf) event.push_back( {lxmin - udxmin, {{lxmin, -1}, 1}} );    
  }
  else if(rxmin <= lxmin && rxmin <= udxmin) {
    event.push_back( {0, {{rxmin, 1}, 1}} );
    if(udxmin != inf && udxmin - rxmin <= (lxmin - rxmin) / 2) {
      event.push_back( {udxmin - rxmin, {{udxmin, 0}, 1}} );
      event.push_back( {lxmin - udxmin , {{lxmin, -1}, 1}} );            
    }
    else if(lxmin != inf) {
      event.push_back( {(lxmin - rxmin) / 2, {{lxmin, -1}, 1}} );      
    }
  }

  // ymax
  sort(u.begin(), u.end(), [](pi a, pi b){
    return a.second < b.second;
  });
  sort(d.begin(), d.end(), [](pi a, pi b){
    return a.second < b.second;
  });
  sort(r.begin(), r.end(), [](pi a, pi b){
    return a.second < b.second;
  });
  sort(l.begin(), l.end(), [](pi a, pi b){
    return a.second < b.second;
  });
  ld uymax = (sz(u) == 0 ? -inf : u[sz(u)-1].second);
  ld dymax = (sz(d) == 0 ? -inf : d[sz(d)-1].second);
  ld rlymax = (sz(r) == 0 ? -inf : r[sz(r)-1].second);
  if(sz(l) != 0) chmax(rlymax, l[sz(l)-1].second);

  if(uymax >= dymax && uymax >= rlymax) {
    event.push_back( {0, {{uymax, 1}, 2}} );
  }
  else if(rlymax >= uymax && rlymax >= dymax) {
    event.push_back( {0, {{rlymax, 0}, 2}} );
    if(uymax != -inf) event.push_back( {rlymax - uymax, {{uymax, 1}, 2}} );    
  }
  else if(dymax >= uymax && dymax >= rlymax) {
    event.push_back( {0, {{dymax, -1}, 2}} );
    if(rlymax != -inf && dymax - rlymax <= (dymax - uymax) / 2) {
      event.push_back( {dymax - rlymax, {{rlymax, 0}, 2}} );
      event.push_back( {rlymax - uymax , {{uymax, 1}, 2}} );            
    }
    else if(uymax != -inf) {
      event.push_back( {(dymax - uymax) / 2, {{uymax, 1}, 2}} );      
    }
  }

  ld uymin = (sz(u) == 0 ? inf : u[0].second);
  ld dymin = (sz(d) == 0 ? inf : d[0].second);
  ld rlymin = (sz(r) == 0 ? inf : r[0].second);
  if(sz(l) != 0) chmin(rlymin, l[0].second);

  if(dymin <= uymin && dymin <= rlymin) {
    event.push_back( {0, {{dymin, -1}, 3}} );
  }
  else if(rlymin <= uymin && rlymin <= dymin) {
    event.push_back( {0, {{rlymin, 0}, 3}} );
    if(dymin != inf) event.push_back( {dymin - rlymin, {{dymin, -1}, 3}} );    
  }
  else if(uymin <= dymin && uymin <= rlymin) {
    event.push_back( {0, {{uymin, 1}, 3}} );
    if(rlymin != inf && rlymin - uymin <= (dymin - uymin) / 2) {
      event.push_back( {rlymin - uymin, {{rlymin, 0}, 3}} );
      event.push_back( {dymin - rlymin , {{dymin, -1}, 3}} );            
    }
    else if(dymin != inf) {
      event.push_back( {(dymin - uymin) / 2, {{dymin, -1}, 3}} );      
    }
  }  

  sort(event.begin(), event.end());
  vector<vector<ld>> pos(4, vector<ld>(2));
  ld res = 2e8;
  res = res*res;
  rep(i,sz(event)) {
    auto [t, p] = event[i];
    auto [v, c] = p;
    //    cout << t << ":" << v[0] << ":" << v[1] << ":" << c << "\n";
    pos[c] = v;
    if(i == sz(event) - 1) {
      ld t1 = event[i].first;
      vector<ld> nx = {pos[0][0] - pos[1][0], pos[0][1] - pos[1][1]};
      vector<ld> ny = {pos[2][0] - pos[3][0], pos[2][1] - pos[3][1]};
      ld c0 = nx[0]*ny[0];
      ld c1 = nx[0]*ny[1] + nx[1]*ny[0];
      ld c2 = nx[1]*ny[1];
      if(c1 == 0 && c2 == 0) chmin(res, c0);
      else if(c2 == 0) {
	chmin(res, c0 + c1*t1);
      }
      else {
	ld top = - c1 / (2*c2);
	if(t1 <= top) {
	  chmin(res, c0 + c1*top + c2*top*top);
	}
	chmin(res, c0 + c1*t1 + c2*t1*t1);
      }      
    }
    else if(event[i+1].first != event[i].first) {
      ld t1 = event[i].first;
      ld t2 = event[i+1].first;
      vector<ld> nx = {pos[0][0] - pos[1][0], pos[0][1] - pos[1][1]};
      vector<ld> ny = {pos[2][0] - pos[3][0], pos[2][1] - pos[3][1]};
      ld c0 = nx[0]*ny[0];
      ld c1 = nx[0]*ny[1] + nx[1]*ny[0];
      ld c2 = nx[1]*ny[1];
      if(c1 == 0 && c2 == 0) chmin(res, c0);
      else if(c2 == 0) {
	chmin(res, c0 + c1*t1);
	chmin(res, c0 + c1*t2);
      }
      else {
	ld top = - c1 / (2*c2);
	if(t1 <= top && top <= t2) {
	  chmin(res, c0 + c1*top + c2*top*top);
	}
	chmin(res, c0 + c1*t1 + c2*t1*t1);
	chmin(res, c0 + c1*t2 + c2*t2*t2);
      }
    }
    // cout << event[i].first << ":";
    // printf("%.10Lf\n", res);
  }
  
  printf("%.10Lf\n", res);
  
  return 0;
}
