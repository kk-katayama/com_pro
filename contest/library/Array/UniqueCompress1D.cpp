// Uniqueな一次元座圧.
// 同じ値でも違う値に圧縮される
template <typename T>
class UniqueCompress{
public:
  vector<T> a; // 元の配列
  vector<int> data; // 座圧後の配列
  map<T, int> mp; // key->元の配列の値, val->座圧後の値のうち最小のもの

  void add(int val) {
    a.emplace_back(val);
  }

  void build() {
    vector<pair<T, int>> vals;

    sort(vals.begin(), vals.end()); 

    data.resize(sz(a));
    rep(i,sz(a)) {
      int val = vals[i].second;
      if(mp.count(val) == 0) {
	mp[val] = i;
      }
      data[val] = i;
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
    // 2 3 0 4 1

    cout << a2data(2) << "\n";
    // 2
  }

};