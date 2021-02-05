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
// n を素因数分解する.返り値はmap.計算量はO(sqrt(n))
map<ll,ll> primefactor(ll n){
  ll nn = n;
  map<ll,ll> res;
  for(ll i=2;i*i<=nn;++i){
    while(nn%i==0){
      res[i]++;
      nn /= i;
    }
  }
  if(nn!=1) res[nn] = 1;
  return res;
}


int main()
{
  ll n; cin >> n;
  map<ll,ll> pf = primefactor(n);

  ll lb = 0, ub = n;
  while(ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    bool f = true;
    for(auto val: pf) {
      auto [num, cnt] = val;
      ll tmp = num;
      ll c = 0;
      while(mid / tmp > 0) {
	c += mid / tmp;
	tmp *= num;
      }
      if(c < cnt) f = false;
    }
    (f ? ub : lb) = mid;
  }
  cout << ub << "\n";
  
  return 0;
}
