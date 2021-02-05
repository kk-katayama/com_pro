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
  vector<string> s(n);
  rep(i,n) cin >> s[i];

  map<string,int> mp1,mp2;
  rep(i,n) {
    if(s[i][0] == '!') {
      string t = "";
      rep1(j,sz(s[i])-1) {
	t.push_back(s[i][j]);
      }
      mp2[t]++;
    }
    else mp1[s[i]]++;
  }

  for(auto tmp: mp1) {
    auto [key, val] = tmp;
    if(mp2[key] > 0) {
      cout << key << "\n";
      return 0;
    }
  }
  cout << "satisfiable" << "\n";
  
  return 0;
}
