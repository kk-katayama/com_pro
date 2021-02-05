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
int main()
{
  int n,s; cin >> n >> s;

  vi res;
  auto rec = [&](auto self, int t, int val)-> void{
    //    cout << val << "\n";
    res.push_back(val);
    if(sz(res) == n) {
      if(t == s) {
	rep(i, sz(res)) {
	  cout << res[i];
	  if(i != sz(res) - 1) cout << " ";
	  else cout << "\n";
	}
      }
      res.pop_back();      
      return ;
    }
    for(int i = val; i + t <= s; ++i) {
      self(self, i + t, i);
    }
    res.pop_back();
    return ;
  };
  rep1(i,s) {
    rec(rec, i, i);
  }
  return 0;
}
