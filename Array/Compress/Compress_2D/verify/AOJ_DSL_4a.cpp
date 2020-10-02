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
#include <array>
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
// 二次元座圧.
// 同じ数は同じ数に圧縮
class Compress2D{
public:
  vector<pair<ll,ll>> p; // 元の座標
  map<ll, int> xmp; // key->元の座標 val->座圧後の座標
  map<ll, int> ymp; // key->元の座標 val->座圧後の座標
  vector<pair<ll,ll>> data; // 座圧後の座標
  vector<ll> xpm; // xpm[座圧後の座標] = 元の座標
  vector<ll> ypm; // ypm[座圧後の座標] = 元の座標  
  int xmax, ymax; // 座圧後のmax
  
  Compress2D() {}

  void add(int x, int y) {
    p.emplace_back(x, y);
  }

  void build() {
    vector<ll> xvals(sz(p)), yvals(sz(p));
    rep(i,sz(p)) {
      xvals[i] = p[i].first;
      yvals[i] = p[i].second;
    }

    // x
    sort(xvals.begin(), xvals.end());
    xvals.erase(unique(xvals.begin(), xvals.end()), xvals.end());
    // y
    sort(yvals.begin(), yvals.end());
    yvals.erase(unique(yvals.begin(), yvals.end()), yvals.end());

    xmax = sz(xvals);
    ymax = sz(yvals);
    xpm.resize(xmax+1);
    ypm.resize(ymax+1);
    rep(i,sz(p)) {
      int xid = lower_bound(xvals.begin(), xvals.end(), p[i].first) - xvals.begin();
      int yid = lower_bound(yvals.begin(), yvals.end(), p[i].second) - yvals.begin();      
      // id + 1にすれば1-indexedになる
      xmp[p[i].first] = xid;
      ymp[p[i].second] = yid;
      xpm[xid] = p[i].first;
      ypm[yid] = p[i].second;
      data.emplace_back(xid, yid);
    }
     
  }
};
int main()
{
  int n; cin >> n;
  Compress2D cp;
  vl x1(n),y1(n),x2(n),y2(n);
  rep(i,n) {
    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
  }

  rep(i,n) {
    cp.add(x1[i], y1[i]);
  }
  rep(i,n) {
    cp.add(x2[i], y2[i]);
  }  

  cp.build();
  using ppi = pair<pi, int>;
  vector<ppi> imos;
  rep(i,n) {
    auto [xx1, yy1] = cp.data[i];
    auto [xx2, yy2] = cp.data[n+i];
    for(int j = xx1; j < xx2; ++j) {
      imos.push_back({{j, yy1}, 1});
      imos.push_back({{j, yy2}, -1});
    }
  }

  sort(imos.begin(), imos.end());
  int idx = 0;
  int sum = 0;
  ll res = 0;
  rep(i,cp.xmax+1) {
    rep(j,cp.ymax+1) {
      while(idx < sz(imos) && i == imos[idx].first.first && j == imos[idx].first.second) {
	sum += imos[idx].second;
	idx++;
      }
      if(sum > 0) {
	res += (cp.xpm[i+1] - cp.xpm[i]) * (cp.ypm[j+1] - cp.ypm[j]);
	//	cout << i << ":" << j << "\n";
      }
    }
  }
  cout << res << "\n";
  
  return 0;
}
