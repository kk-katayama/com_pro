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
  int t; cin >> t;
  while(t-- > 0) {
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];

    map<string,int> mp, check;
    rep(i,n) {
      mp[s[i]]++;
      check[s[i]] = 1;
    }

    int cnt = 0;
    rep(i,n) {
      if(mp[s[i]] > 1) {
	cnt++;
	string old = s[i];
	rep(j,10) {
	  if(s[i][0] == '9') s[i][0] = '0';
	  else s[i][0] = (char)(s[i][0] + 1);
	  if(mp.find(s[i]) == mp.end()) {
	    mp[s[i]]++;
	    mp[old]--;
	    break;
	  }
	}
      }
    }
    cout << cnt << "\n";
    rep(i,n) {
      cout << s[i] << "\n";
    }
  }
  return 0;
}
