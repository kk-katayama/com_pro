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
  vi a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];

  map<int,int> mp;
  map<int,int> mpa,mpb;  
  rep(i,n) {
    mp[a[i]]++;
    mpa[a[i]]++;
    mp[b[i]]++;
    mpb[b[i]]++;
  }
  for(auto val: mp) {
    if(val.second > n) {
      cout << "No" << "\n";
      return 0;
    }
  }

  sort(a.begin(), a.end(), [&](int x, int y) {
    return mp[x] > mp[y];
  });
  sort(b.begin(), b.end(), [&](int x, int y) {
    return mp[x] > mp[y];
  });  
  
  vector<pi> p(n, {-1,-1});
  int id = 0, aid = 0, bid = 0;
  for(auto val: mp) {
    int num = val.first;
    if(mpa[num] > mpb[num]) {
      while(aid < n && a[aid] == num) {
	while(p[id].first != -1 || p[id].second == num) {
	  id = (id + 1)%n;
	}
	p[id].first = a[aid];
	aid++;
	id = (id + 1)%n;
      }
      while(bid < n && b[bid] == num) {
	while(p[id].second != -1 || p[id].first == num) {
	  id = (id + 1)%n;
	}      
	p[id].second = b[bid];
	bid++;
	id = (id + 1)%n;
      }
    }
    else {
      while(bid < n && b[bid] == num) {
	while(p[id].second != -1 || p[id].first == num) {
	  id = (id + 1)%n;
	}      
	p[id].second = b[bid];
	bid++;
	id = (id + 1)%n;
      }
      while(aid < n && a[aid] == num) {
	while(p[id].first != -1 || p[id].second == num) {
	  id = (id + 1)%n;
	}
	p[id].first = a[aid];
	aid++;
	id = (id + 1)%n;
      }
    }
  }

  cout << "Yes" << "\n";
  sort(p.begin(), p.end());
  rep(i,n) {
    cout << p[i].second << " ";
  }
  cout << "\n";
  return 0;
}
