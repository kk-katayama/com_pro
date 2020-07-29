#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
typedef long long ll;
using pl = pair<ll,ll>;
using pll = pair<pl,pl>;
int main()
{
  int t; cin >> t;
  vector<ll> ans;
  while(t-- > 0) {
    int n; cin >> n;
    vector<int> k(n),l(n),r(n);
    rep(i,n) cin >> k[i] >> l[i] >> r[i];
    vector<pll> a, b;
    ll res = 0;
    rep(i,n) {
      if(l[i] > r[i]) {
	a.push_back({{k[i] - 1, l[i]}, {r[i], l[i] - r[i]}});
      }
      else {
	b.push_back({{n - k[i] - 1, l[i]}, {r[i], r[i] - l[i]}});	
      }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // for(auto val: a) cout << val.first.first << ":" << val.first.second << ":" << val.second.first << ":" << val.second.second << "\n";
    // for(auto val: b) cout << val.first.first << ":" << val.first.second << ":" << val.second.first << ":" << val.second.second << "\n";
    // cout << a.size() << ":" << b.size() << "\n";
    {
      int m = a.size();
      priority_queue<pair<ll,pl>> pq;
      int idx = m - 1;
      for (int i = m - 1; i >= 0; --i) {
	while(idx >= 0 && a[idx].first.first >= i) {
	  pq.push({a[idx].second.second, {a[idx].first.second, a[idx].second.first}});
	  idx--;
	}
	if( !pq.empty() ){
	  pair<ll,pl> p = pq.top(); pq.pop();
	  res += p.second.first;
	}
      }
      while(idx >= 0) {
	pq.push({a[idx].second.second, {a[idx].first.second, a[idx].second.first}});
	idx--;
      }      
      while( !pq.empty() ) {
	pair<ll,pl> p = pq.top(); pq.pop();
	res += p.second.second;
      }
    }
    {
      int m = b.size();
      priority_queue<pair<ll,pl>> pq;
      int idx = m - 1;
      for (int i = m - 1; i >= 0; --i) {
	while(idx >= 0 && b[idx].first.first >= i) {
	  pq.push({b[idx].second.second, {b[idx].first.second, b[idx].second.first}});
	  idx--;
	}
	if( !pq.empty() ){
	  pair<ll,pl> p = pq.top(); pq.pop();
	  res += p.second.second;
	}
      }
      while(idx >= 0) {
	pq.push({b[idx].second.second, {b[idx].first.second, b[idx].second.first}});
	idx--;
      }
      while( !pq.empty() ) {
	pair<ll,pl> p = pq.top(); pq.pop();
	res += p.second.first;
      }
    }    
    ans.push_back(res);
  }
  for(auto val: ans) cout << val << "\n";
  
  return 0;
}
