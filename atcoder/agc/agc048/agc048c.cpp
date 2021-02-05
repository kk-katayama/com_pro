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
// ランレングス圧縮.配列の連続している要素をまとめてしまう圧縮.
vector<pair<ll,ll>> rle(vector<ll> a){
  vector<pair<ll,ll>> res;
  ll n = a.size();
  ll cnt = 1;
  pair<ll,ll> p;
  p.first = a[0];
  rep(i,n-1){
    if(a[i]==a[i+1]){
      cnt++;
    }
    else{
      p.second = cnt;
      res.push_back(p);
      cnt = 1;
      p.first = a[i+1];
    }
  }
  p.second = cnt;
  res.push_back(p);
  return res;
}

int main()
{
  ll n,l; cin >> n >> l;
  vl a(n+1),b(n+1);
  rep1(i,n) cin >> a[i];
  rep1(i,n) cin >> b[i];

  a[0] = 0; b[0] = 0;
  a.push_back(l+1);
  b.push_back(l+1);

  vl c(n+2);
  rep(i,n+2) {
    if(a[i] > b[i]) c[i] = -1;
    else if(a[i] < b[i]) c[i] = 1;
    else c[i] = 0;
  }

  vector<pl> p = rle(c);
  ll id = 0;
  ll res = 0;
  bool f = true;
  rep(i,sz(p)) {
    if(p[i].first == -1) {
      if(p[i-1].first != 0) {
	f = false;
	goto FIN;
      }
      ll id2 = id + p[i].second - 1;
      ll cnt = 0;
      for (ll j = id2; j >= id; --j) {
	if(b[j] == a[id2] + cnt) {
	  cnt--;
	  continue;
	}
	while(id2 >= id - 1 && b[j] != a[id2] + cnt) {
	  id2--;
	  cnt++;
	}
	if(id2 < id - 1) {
	  f = false;
	  goto FIN;
	}
	res += cnt;
	cnt--;
      }
    }
    if(p[i].first == 1) {
      if(p[i+1].first != 0) {
	f = false;
	goto FIN;
      }
      ll id2 = id;
      ll cnt = 0;
      for (ll j = id; j < id + p[i].second ; ++j) {
	if(b[j] == a[id2] - cnt) {
	  cnt--;
	  continue;
	}
	while(id2 <= id + p[i].second && b[j] != a[id2] - cnt) {
	  id2++;
	  cnt++;
	}
	if(id2 > id + p[i].second) {
	  f = false;
	  goto FIN;
	}
	res += cnt;

	cnt--;
      }
    }
    id += p[i].second;
  }

 FIN:
  cout << (f ? res : -1) << "\n";
  return 0;
}
