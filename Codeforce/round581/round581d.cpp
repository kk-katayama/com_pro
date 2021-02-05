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
  int n = sz(s);

  set<int> st;
  string t = s;
  rep(i,n-1) {
    if(s[i] == '1' && s[i+1] == '1') {
      t[i] = '0';
      st.insert(i);
    }
  }
  if(s[n-1] == '1') {
    t[n-1] = '0';
    st.insert(n-1);
  }
  

  int cnt = 0, mx = 0;
  int cnt2 = 0, mx2 = 0;
  rep(i,n) {
    if(s[i] == '0') {
      if(cnt == mx) {
	cnt++; mx++;
      }
      else {
	cnt++;
      }
    }
    else {
      mx++;
    }
    if(t[i] == '0') {
      if(cnt2 == mx2) {
	cnt2++; mx2++;
      }
      else {
	cnt2++;
      }
    }
    else {
      mx2++;
    }    
    if(mx < mx2) {
      auto it = st.lower_bound(i);
      it--;
      t[*it] = '1';
      st.erase(*it);
      cnt2--; mx2--;
    }
  }

  cout << t << "\n";
  return 0;
}
