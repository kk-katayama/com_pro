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
// xの約数を列挙する.返り値はvector.O(sqrt(x))
vector<int> divisor(int x){
  vector<int> res;
  for(int i=1;i*i<=x;++i){
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
  int n; cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];

  vi sum(n+1, 0);
  rep(i,n) sum[i+1] = sum[i] + a[i];

  vi div = divisor(sum[n]);
  if(sz(div) == 1) {
    cout << -1 << "\n";
  }
  else {
    ll res = infll;
    rep1(i, sz(div)-1) {
      int d = div[i];
      int id = 0;
      ll ans = 0;
      vi tmp;
      rep1(j,n) {
	if(a[j-1] == 1) tmp.push_back(j-1);
	if(sum[j] - sum[id] == d) {
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
