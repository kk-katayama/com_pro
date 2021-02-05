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
  ll n,m,k,q; cin >> n >> m >> k >> q;
  vvl tre(n);
  rep(i,k) {
    ll r,c; cin >> r >> c;
    r--; c--;
    tre[r].push_back(c);
  }
  vl b(q);
  rep(i,q) {
    cin >> b[i];
    b[i]--;
  }
  sort(b.begin(), b.end());
  int nn = n;
  while(sz(tre[nn-1]) == 0) nn--;
  
  map<ll,ll> dp1;
  dp1[0] = 0;
  rep(i,nn) {
    ll mm = sz(tre[i]);
    if(sz(tre[i]) == 0) {
      if(i == 0) {
	map<ll,ll> dp2;
	dp2[b[0]] = b[0] + ll(1);
	swap(dp1, dp2);
	continue;
      }
      for(auto tmp: dp1) {
	auto [key, val] = tmp;
	dp1[key]++;
      }
      continue;
    }
    map<ll,ll> dp2;
    if(sz(tre[i]) == 1) {
      vl c;
      ll lb = -1, ub = q;
      while(ub - lb > 1) {
	ll mid = (ub + lb) / 2;
	(tre[i][0] <= b[mid] ? ub : lb) = mid;
      }
      if(ub == q) {
	c.push_back(b[q-1]);
      }
      else if(ub == 0) {
	c.push_back(b[0]);	
      }
      else if(b[ub] == tre[i][0]) {
	c.push_back(b[ub]);
      }
      else {
	c.push_back(b[ub]);
	c.push_back(b[ub-1]);
      }
      for(auto tmp: dp1) {
	auto [key, val] = tmp;
	ll kk = abs(tre[i][0] - key) + val + ll(1);
	rep(j,sz(c)) {
	  ll nval = kk + abs(c[j] - tre[i][0]);
	  if(i == nn-1) {
	    nval = kk;
	  }
	  if(dp2.find(c[j]) == dp2.end()) {
	    dp2[c[j]] = nval;
	  }
	  else {
	    chmin(dp2[c[j]], nval);
	  }
	}
      }
    }
    else {
      sort(tre[i].begin(), tre[i].end());
      vl c;
      ll lb = -1, ub = q;
      while(ub - lb > 1) {
	ll mid = (ub + lb) / 2;
	(tre[i][0] <= b[mid] ? ub : lb) = mid;
      }
      if(ub == q) {
	c.push_back(b[q-1]);
      }
      else if(ub == 0) {
	c.push_back(b[0]);	
      }
      else if(b[ub] == tre[i][0]) {
	c.push_back(b[ub]);
      }
      else {
	c.push_back(b[ub]);
	c.push_back(b[ub-1]);
      }
      lb = -1, ub = q;
      while(ub - lb > 1) {
	ll mid = (ub + lb) / 2;
	(tre[i][mm-1] <= b[mid] ? ub : lb) = mid;
      }
      if(ub == q) {
	c.push_back(b[q-1]);
      }
      else if(ub == 0) {
	c.push_back(b[q-1]);	
      }
      else if(b[ub] == tre[i][mm-1]) {
	c.push_back(b[ub]);
      }
      else {
	c.push_back(b[ub]);
	c.push_back(b[ub-1]);
      }      
      for(auto tmp: dp1) {
	auto [key, val] = tmp;
	if(tre[i][0] < key && key < tre[i][mm-1]) {
	  ll kk = abs(tre[i][mm-1] - key) * 2 + abs(tre[i][0] - key) + val + ll(1);
	  rep(j,sz(c)) {
	    ll nval = kk + abs(c[j] - tre[i][0]);
	    if(i == nn-1) {
	      nval = kk;
	    }	    
	    if(dp2.find(c[j]) == dp2.end()) {
	      dp2[c[j]] = nval;
	    }
	    else {
	      chmin(dp2[c[j]], nval);
	    }
	  }
	  kk = abs(tre[i][mm-1] - key) + abs(tre[i][0] - key) * 2 + val + ll(1);
	  rep(j,sz(c)) {
	    ll nval = kk + abs(c[j] - tre[i][mm-1]);
	    if(i == nn-1) {
	      nval = kk;
	    }	    	    
	    if(dp2.find(c[j]) == dp2.end()) {
	      dp2[c[j]] = nval;
	    }
	    else {
	      chmin(dp2[c[j]], nval);
	    }
	  }	  
	}
	else if(key <= tre[i][0]) {
	  ll kk = abs(tre[i][mm-1] - key) + val + ll(1);
	  rep(j,sz(c)) {
	    ll nval = kk + abs(c[j] - tre[i][mm-1]);
	    if(i == nn-1) {
	      nval = kk;
	    }	    	    
	    if(dp2.find(c[j]) == dp2.end()) {
	      dp2[c[j]] = nval;
	    }
	    else {
	      chmin(dp2[c[j]], nval);
	    }
	  }	  
	}
	else {
	  ll kk = abs(tre[i][0] - key) + val + ll(1);
	  rep(j,sz(c)) {
	    ll nval = kk + abs(c[j] - tre[i][0]);
	    if(i == nn-1) {
	      nval = kk;
	    }	    	    
	    if(dp2.find(c[j]) == dp2.end()) {
	      dp2[c[j]] = nval;
	    }
	    else {
	      chmin(dp2[c[j]], nval);
	    }
	  }	  	  
	}
      }
    }
    swap(dp1, dp2);
    // cout << i << "\n";
    // for(auto tmp: dp1) {
    //   auto [key, val] = tmp;
    //   cout << key << ":" << val << "\n";
    // }
  }

  if(sz(tre[nn-1]) == 0) {
    ll res = infll;
    for(auto tmp: dp1) {
      auto [key, val] = tmp;
      chmin(res, val);
    }
    cout << res-1 << "\n";
  }
  else {
    ll res = infll;
    for(auto tmp: dp1) {
      auto [key, val] = tmp;
      chmin(res, val);
    }
    cout << res-1<< "\n";    
  }
  
  return 0;
}
