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
