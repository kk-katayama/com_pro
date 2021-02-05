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
#include <bitset>
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
class xor_base{
public:
  vector<ll> base; // 基底の集合

  // 要素を追加
  // 要素が線形独立ならtrue, 線形従属ならfalseをreturn
  bool insert(ll a) {
    for(auto val: base) {
      a = min(a, a ^ val);
      if(a == 0) return false;
    }
    base.push_back(a);
    sort(base.begin(), base.end(), [](ll a, ll b){
      return a > b;
    });
    return true;
  }

  // 要素が線形独立かチェック
  bool check(ll a) {
    for(auto val: base) {
      a = min(a, a ^ val);
      if(a == 0) return false;
    }
    return true;    
  }
  
  void show() {
    for(auto val: base) {
      cout << bitset<4>(val) << "\n";
    }
  }
  
};
int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    xor_base xb;
    int n; cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    string s; cin >> s;

    reverse(a.begin(), a.end());
    reverse(s.begin(), s.end());
    bool f = true;
    rep(i,n) {
      if(s[i] == '0') {
	xb.insert(a[i]);
      }
      else {
	if( xb.check(a[i]) ) {
	  f = false;
	}
      }
    }
    cout << (f ? 0 : 1) << "\n";
  }
  
  return 0;
}
