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
#define sz(v) (int)v.size()
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long; using ld = long double;
using pi = pair<int,int>; using pl = pair<ll,ll>;
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
const int inf = numeric_limits<int>::max();
const ll infll = numeric_limits<ll>::max();
// xの約数を列挙する.返り値はvector.O(sqrt(x))
vector<ll> divisor(ll x){
  vector<ll> res;
  for(ll i=1;i*i<=x;++i){
    if(x%i==0){
      res.push_back(i);
      if(i!=x/i){
	res.push_back(x/i);
      }
    }
  }
  sort(res.begin(), res.end());
  return res;
}


int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    ll n,x,y; cin >> n >> x >> y;
    vl div = divisor(y - x);
    ll mn = infll;
    int id;
    bool f = false;
    rep(i, sz(div)) {
      ll a = x % div[i];
      ll tmp;
      if(a == 0) {
	tmp = n * div[i];
      }
      else {
	tmp = a + (n - 1) * div[i];
      }
      if(tmp < y) { }
      else if(chmin(mn, tmp)) {
	id = i;
      }
      if(0 < y - (n - 1) * div[i] && y - (n - 1) * div[i] <= x) {
	ll aa = y - (n - 1) * div[i];
	rep(j,n) {
	  cout << aa << " ";
	  aa += div[i];
	}
	cout << "\n";
	f = true;
	break;
      }
    }
    if(f) continue;
    ll aa = x % div[id];
    if(aa == 0) aa += div[id];
    rep(i,n) {
      cout << aa << " ";
      aa += div[id];
    }
    cout << "\n";
  }
  return 0;
}
