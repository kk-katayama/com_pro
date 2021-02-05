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
  ll k,n,m; cin >> k >> n >> m;
  vector<pl> p(k);
  rep(i,k) {
    ll tmp; cin >> tmp;
    p[i] = {tmp, i+1};
  }

  sort(p.begin(), p.end(), [](pl a, pl b){
    return a.first > b.first;
  });

  vl res1,res2;
  ll b = (k + 12 - 1) / 12;
  rep(i,k) {
    ll x = p[i].first - (n - m)*100;
    if(x >= 0) {
      ll lb = -1, ub = k;
      while(ub - lb > 1) {
	ll mid = (ub + lb) / 2;
	(p[mid].first <= x ? ub : lb) = mid;
      }
      if(n - m == 0) {
	if(ub+1 <= b) {
	  res1.push_back(p[i].second);
	}
      }
      else {
	if(ub <= b) {
	  res1.push_back(p[i].second);
	}
      }
    }
    x = p[i].first + (n - m)*100;
    ll lb = -1, ub = k;
    while(ub - lb > 1) {
      ll mid = (ub + lb) / 2;
      (p[mid].first <= x ? ub : lb) = mid;
    }
    if(ub + 1 <= b) {
      res2.push_back(p[i].second);
    }    
  }

  sort(res1.begin(), res1.end());
  sort(res2.begin(), res2.end());  

  if(k < 12) {
    res1.clear();
    res2.clear();
  }
  for(auto tmp: res1) cout << tmp << "\n";
  cout << "--------" << "\n";
  for(auto tmp: res2) cout << tmp << "\n";  
  return 0;
}
