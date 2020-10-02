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
// 座圧.配列aを入れると、0-indexedで座圧した配列を返す.同じ要素は同じ数に圧縮される.
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

int main()
{
  int n; cin >> n;
  Compress<int> cp;
  rep(i,n) {
    int a; cin >> a;
    cp.add(a);
  }
  cp.build();

  for(auto val: cp.data) cout << val << "\n";

  return 0;
}
