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
  string s; cin >> s;
  if(sz(s) <= 3) {
    bool f = false;
    vi vec(sz(s));
    rep(i,sz(s)) vec[i] = i;
    do{
      string t(sz(s), '1');
      rep(j,sz(s)) {
	t[j] = s[vec[j]];
      }
      int x = 0;
      rep(i,sz(t)) {
	x *= 10;
	x += int(t[i] - '0');
      }
      if(x % 8 == 0) f = true;
    } while(next_permutation(vec.begin(), vec.end()));
    cout << (f ? "Yes" : "No") << "\n";
    
    return 0;
  }

  vector<map<int,int>> vmp;
  for(int i = 13; i < 125; ++i) {
    int d = 8*i;
    map<int,int> mp;
    bool f = true;
    rep(j,3) {
      if(d % 10 == 0) {
	f = false;
	break;
      }
      else {
	mp[d % 10]++;
      }
      d /= 10;
    }
    if(f) {
      vmp.push_back(mp);
    }
  }

  map<int,int> smp;
  rep(i,sz(s)) {
    smp[(int)s[i] - '0']++;
  }

  bool ff = false;
  for(auto val: vmp) {
    bool f = true;
    for(auto val2: val) {
      auto [c, num] = val2;
      if(smp[c] < num) f = false;
    }
    if(f) ff = true;
  }
  
  cout << (ff ? "Yes" : "No") << "\n";

  return 0;
}
