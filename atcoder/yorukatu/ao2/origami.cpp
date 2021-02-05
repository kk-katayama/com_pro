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

  void add(ll x, ll y) {
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

  int a2datax(ll num) {
    return xmp.lower_bound(num)->second;
  }
  int a2datay(ll num) {
    return ymp.lower_bound(num)->second;
  }  
  
};



int main()
{
  int n; cin >> n;
  ll a,b; cin >> a >> b;
  vl p(n),q(n),r(n),s(n);
  rep(i,n) {
    cin >> p[i] >> q[i] >> r[i] >> s[i];
    p[i]--;
    q[i]--;
  }
  
  Compress2D cp;
  rep(i,n) {
    cp.add(p[i], q[i]);
    cp.add(r[i], s[i]);
  }

  cp.add(0, 0);
  cp.add(a, b);
  cp.build();

  vector<pair<pi,int>> imos;
  rep(i,n) {
    int l = cp.a2datay(q[i]);    
    while(l != cp.ymp[s[i]]) {
      imos.push_back({{cp.xmp[p[i]], l}, 1});
      imos.push_back({{cp.xmp[r[i]], l}, -1});
      //      cout << cp.xmp[p[i]] << ":" << l << "\n";
      // cout << r[i] << ":" << l << "\n";      
      l++;
    }
  }
  
  int mx = 0;
  ll res = 0;
  int cnt = 0;
  sort(imos.begin(), imos.end(), [](pair<pi,int> a, pair<pi,int> b){
				   if(a.first.second == b.first.second) return a.first.first < b.first.first;
				   else return a.first.second < b.first.second;
				 });
  // rep(i, sz(imos)) {
  //   auto [x, y] = imos[i];
  //   auto [z, w] = x;
  //   cout << z << ":" << w << ":" << y << "\n";
  // }
  rep(i, sz(imos)) {
    while( (imos[i].first.first == imos[i+1].first.first && imos[i].first.second == imos[i+1].first.second) ) {
      cnt += imos[i].second;
      i++;
    }
    cnt += imos[i].second;
    if(cnt == mx) {
      res += (cp.xpm[imos[i+1].first.first] - cp.xpm[imos[i].first.first]) * (cp.ypm[imos[i].first.second + 1] - cp.ypm[imos[i].first.second]);
    }
    else if(cnt > mx) {
      mx = cnt;
      res = 0;
      res += (cp.xpm[imos[i+1].first.first] - cp.xpm[imos[i].first.first]) * (cp.ypm[imos[i].first.second + 1] - cp.ypm[imos[i].first.second]);      
    }
    //    cout << res << "\n";
  }

  cout << mx << "\n";
  cout << res << "\n";
  return 0;
}
