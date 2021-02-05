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
  vi a(n);
  rep(i,n) cin >> a[i];

  vi res(1, -1);
  int M = 1000001;
  vi tab(M, 0);
  vi ch(M, 0);
  bool f = true;
  int sum = 0;
  vi st;
  rep(i,n) {
    if(a[i] > 0) {
      if(tab[a[i]] > 0) {
	f = false;
	break;
      }
      else {
	if(ch[a[i]] == 1) {
	  f = false;
	  break;
	}
	tab[a[i]]++;
	sum++;
	ch[a[i]] = 1;
	st.push_back(a[i]);
      }
    }
    else {
      a[i] = -a[i];
      if(tab[a[i]] != 1) {
	f = false;
	break;
      }
      else {
	tab[a[i]]--;
	sum--;
	if(sum == 0) {
	  res.push_back(i);
	  for(auto val: st) {
	    ch[val] = 0;
	  }
	}
      }
    }
  }
  
  if(f) {
    if(sum == 0) {
      cout << sz(res) - 1 << "\n";
      rep1(i,sz(res)-1) {
	cout << res[i] - res[i-1] << " ";
      }
      cout << "\n";
    }
    else {
      cout << -1 << "\n";
    }
  }
  else {
    cout << -1 << "\n";
  }
  
  return 0;
}
