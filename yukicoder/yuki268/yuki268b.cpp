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
  vl pow2(60);
  pow2[0] = 1;
  rep(i,59) {
    pow2[i+1] = pow2[i] * 2;
  }
  
  int t; cin >> t;
  while(t-- > 0) {
    ll a,b; cin >> a >> b;
    ll c = b;
    vl res;    
    int cnt = 0;
    while(c > 0) {
      c /= 2;
      cnt++;
    }
    cnt--;
    int j = cnt;
    while((!((a >> j) ^ (b >> j))) & 1) {
      j--;
    }
    bool f = true;
    rep(i, j) {
      if((a >> i) & 1) {
	f = false;
      }
    }
    if(!f) {
      int k = 0;
      while(!((a >> k) & 1)) {
	k++;
      }
      res.push_back(pow2[k]);
      for(int i = k; i < j; ++i) {
	if( !((a >> i) & 1) ) {
	  res.push_back(pow2[i]);
	}
      }
    }    
    for(int i = j - (f ? 0 : 1); i >= 0; --i) {
      if( (b >> i) & 1) {
	res.push_back(pow2[i]);
      }
    }
    cout << sz(res) << "\n";
    for(auto val: res) {
      cout << val << " ";
      a += val;
    }
    cout << "\n";    

  }
  return 0;
}
