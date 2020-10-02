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
// Uniqueな一次元座圧.
// 同じ値でも違う値に圧縮される
template <typename T>
class UniqueCompress{
public:
  vector<T> a; // 元の配列
  vector<int> data; // 座圧後の配列
  map<T, int> mp; // key->元の配列の値, val->座圧後の値のうち最小のもの
  T max_elem;
  
  void add(int val) {
    a.emplace_back(val);
  }

  void build() {
    vector<pair<T, int>> vals(sz(a));
    max_elem = -inf;
    rep(i,sz(a)) {
      vals[i] = {a[i], i};
      chmax(max_elem, a[i]);
    }
    
    sort(vals.begin(), vals.end()); 

    data.resize(sz(a));
    rep(i,sz(a)) {
      auto [val, id] = vals[i];
      if(mp.count(val) == 0) {
	mp[val] = i;
      }
      data[id] = i;
    }
  }

  int a2data(T val) {
    if(val > max_elem) return -1;
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

int main()
{
  UniqueCompress<int> uc;
  uc.test();
  return 0;
}
