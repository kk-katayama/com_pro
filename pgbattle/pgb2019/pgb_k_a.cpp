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
  string s; cin >> s;

  vi t(n+2, 0);
  int l1 = 1, l2 = 1, r1 = n, r2 = n;
  vi res(n);
  bool f = true;
  rep(i,n) {
    if(s[i] == 'L') {
      if(f) {
	res[i] = l1;
	t[l1] = 1;
      }
      else {
	res[i] = l2;
	t[l2] = 1;
      }
    }
    else {
      if(f) {
	res[i] = r1;
	t[r1] = 1;
      }
      else {
	res[i] = r2;
	t[r2] = 1;
      }
    }
    while(l1 < n && !(t[l1-1] == 0 && t[l1] == 0 && t[l1+1] == 0) ) l1++;
    if(l1 == n) f = false;
    while(t[l2] == 1) l2++;
    while(0 < r1 && !(t[r1-1] == 0 && t[r1] == 0 && t[r1+1] == 0) ) r1--;
    if(r1 == 0) f = false;
    while(t[r2] == 1) r2--;
  }

  for(auto val: res) cout << val << "\n";
  
  return 0;
}
