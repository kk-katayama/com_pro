// 一次元座圧.
// 同じ値は同じ値に圧縮される
template <typename T>
class Compress{
public:
  vector<T> a; // 元の配列
  vector<int> data; // 座圧後の配列
  map<T, int> mp; // key->元の配列の値, val->座圧後の値

  void add(int val) {
    a.emplace_back(val);
  }

  void build() {
    vector<T> vals = a;

    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    rep(i,sz(a)) {
      int id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
      // id + 1にすれば1-indexedになる
      mp[a[i]] = id;
      data.push_back(id);
    }
  }

  int a2data(T val) {
    return mp.lower_bound(val)->second;
  }

  void test() {
    vector<T> v = {3, 3, 1, 6, 1};
    for(auto val: v) add(val);
    build();

    for(auto val: data) cout << val << " ";
    cout << "\n";
    // 1 1 0 2 0

    cout << a2data(2) << "\n";
    // 1
  }

};
