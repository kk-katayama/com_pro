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
  int n; cin >> n;
  auto fanc = [](string s)->pi {
    {
      int c = int(s[3] - '0');
      if(0 <= c && c <= 4) s[3] = '0';
      if(5 <= c && c <= 9) s[3] = '5';      
    }
    int x = 0;
    {
      int c = int(s[8] - '0');
      if(1 <= c && c <= 4) s[8] = '5';
      if(6 <= c && c <= 9) {
	s[8] = '0';
	s[7] += 1;
	if(s[7] == '6') {
	  x = 100;
	  s[7] = '0';
	}
      }
    }
    int a=0,b=0;
    rep(i,4) {
      int z = pow(10, 3-i);
      int c = int(s[i] - '0');
      a += c*z;
    }
    rep(i,4) {
      int z = pow(10, 3-i);
      int c = int(s[5+i] - '0');
      b += c*z;
    }
    return {a, b+x};
  };

  vector<pi> p(n);
  rep(i,n) {
    string tmp;
    cin >> tmp;
    p[i] = fanc(tmp);
  }
  sort(p.begin(), p.end());
  int id = 0;
  int s = -1;
  int t = -1;
  vector<pi> res;
  while(id < n) {
    if(s == -1 && t == -1) {
      s = p[id].first;
      t = p[id].second;
    }
    else if(p[id].first <= t) {
      chmax(t, p[id].second);
    }
    else {
      res.push_back({s, t});
      s = -1;
      t = -1;
      id--;
    }
    id++;
  }
  if(s != -1) {
    res.push_back({s, t});
  }

  for(auto tmp: res) {
    auto [a, b] = tmp;
    //    cout << a << ":" << b << "\n";
    rep(i,4) {
      int z = pow(10, 3-i);
      cout << a/z;
      a %= z;
    }
    cout << "-";
    rep(i,4) {
      int z = pow(10, 3-i);
      cout << b/z;
      b %= z;
    }
    cout  << "\n";
  }
  
  return 0;
}
