// 二次元座圧.同じ要素でも違う数に圧縮する.
class UniqueCompress2D{
public:
  vector<pair<ll,ll>> p;
  map<ll, int> xmp;
  map<ll, int> ymp;
  vector<int> data;

  UniqueCompress2D() {}

  void add(int x, int y) {
    p.emplace_back(x, y);
  }

  void build() {
    sort(p.begin(), p.end(), [](pair<ll,ll> a, pair<ll,ll> b) {
			       return a.second < b.second; // yの昇順にソート
			     });
    rep(i,sz(p)) {
      if(ymp.count(p[i].second) == 0) {
	ymp[p[i].second] = i;
      }
      p[i].second = i;
    }

    sort(p.begin(), p.end()); // xの昇順にソート
    rep(i,sz(p)) {
      if(xmp.count(p[i].first) == 0) {
	xmp[p[i].first] = i;
      }
      p[i].first = i;
    }

    data.resize(sz(p));
    rep(i,sz(p)) {
      data[i] = p[i].second;
    }
  }

  // (x1,y1), (x2,y2) を座圧したものに変換する
  tuple<int, int, int, int> grid(ll x1, ll y1, ll x2, ll y2) {
        return
	  { xmp.lower_bound(x1)->second,
	    ymp.lower_bound(y1)->second,
	    xmp.lower_bound(x2)->second,
	    ymp.lower_bound(y2)->second};
  }
  
};