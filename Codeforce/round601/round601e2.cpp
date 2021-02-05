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
map<ll,int> primefactor(ll n){
  ll nn = n;
  map<ll,int> res;
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
  int n; cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];

  vl sum(n+1, 0);
  rep(i,n) sum[i+1] = sum[i] + a[i];

  map<ll,int> pf = primefactor(sum[n]);
  vl p;
  for(auto val: pf) p.push_back(val.first);
  if(sz(p) == 1) {
    cout << -1 << "\n";
  }
  else {
    ll res = infll;
    rep1(i, sz(p)-1) {
      ll d = p[i];
      ll id = 0;
      ll ans = 0;
      vl tmp;
      vl b(n);
      rep(i,n) {
	b[i] = a[i] % d;
      }
      ll cum = 0;
      rep(i,n) {
	cum += b[i];
	if(cum >= d) {
	  ll r = cum - d;
	  
	}
      }
      rep1(j,n) {
	if(a[j-1] == 1) tmp.push_back(j-1);
	if(sum[j] - sum[id] >= d) {
	  ll m = tmp[sz(tmp)/2];
	  for(auto val: tmp) {
	    ans += abs(val - m);
	  }
	  tmp.clear();
	  id = j;
	}
      }
      chmin(res, ans);
    }
    cout << res << "\n";
  }

  return 0;
}
