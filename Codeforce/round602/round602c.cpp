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
    int n,k; cin >> n >> k;
    string s; cin >> s;

    vi a,b;
    rep(i,n) {
      if(i % 2 == 0 && s[i] == ')') {
	a.push_back(i+1);
	int id = i+1;
	while(s[id] == ')') id++;
	b.push_back(id+1);
	string u;
	for(int j = id; j >= i; --j) {
	  u.push_back(s[j]);
	}
	rep(j,sz(u)) {
	  s[i+j] = u[j];
	}
      }
      else if(i % 2 == 1 && s[i] == '(') {
	a.push_back(i+1);
	int id = i+1;
	while(s[id] == '(') id++;
	b.push_back(id+1);
	string u;
	for(int j = id; j >= i; --j) {
	  u.push_back(s[j]);
	}
	rep(j,sz(u)) {
	  s[i+j] = u[j];
	}
      }
    }
    rep1(i, n/2-k) {
      a.push_back(2*i);
      b.push_back(2*i+1);      
    }
    cout << sz(a) << "\n";
    rep(i,sz(a)) {
      cout << a[i] << " " << b[i] << "\n";
    }
  }
  return 0;
}
