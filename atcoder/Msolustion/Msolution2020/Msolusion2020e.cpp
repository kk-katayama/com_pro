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
  vl x(n),y(n),p(n);
  vector<pl> xp(n),yp(n);
  rep(i,n) {
    scanf("%lld%lld%lld", &x[i], &y[i], &p[i]);
  }

  vl dtmp(n, inf);
  rep(i,n) {
    dtmp[i] = min(abs(x[i]), abs(y[i]));
  }

  vl res(n+1, infll);
  res[n] = 0;
  rep(mask, (1<<n)-1) {
    int cnt = __builtin_popcount(mask);
    vl id, id2;
    rep(j,n) {
      if((mask >> j) & 1) {
	id.push_back(j);
      }
      else {
	// vx.push_back(x[j]);
	// vy.push_back(y[j]);
	// vp.push_back(p[j]);
	id2.push_back(j);
      }
    }
    for(int i=mask;i>=0;--i){
      i &= mask;
      //      vl xx = {-inf, 0, inf}, yy = {-inf, 0, inf};
      vl d = dtmp;
      rep(k,sz(id)) {
	int j = id[k];
	if( (i >> j) & 1) {
	  //	  xx.push_back(x[j]);
	  rep(kk,sz(id2)) {
	    int jj = id2[kk];
	    chmin(d[jj], abs(x[jj] - x[j]));
	  }
	}
	else {
	  //	  yy.push_back(y[j]);
	  rep(kk,sz(id2)) {
	    int jj = id2[kk];
	    chmin(d[jj], abs(y[jj] - y[j]));
	  }	  
	}
      }
      ll sum = 0;      
      rep(kk,sz(id2)) {
	int jj = id2[kk];	  
	sum += d[jj] * p[jj];	
      }
      // sort(xx.begin(), xx.end());
      // sort(yy.begin(), yy.end());


      // rep(j,sz(vx)) {
      // 	int lb = 0, ub = sz(xx);
      // 	while(ub - lb > 1) {
      // 	  int mid = (ub + lb) / 2;
      // 	  (xx[mid] >= vx[j] ? ub : lb) = mid;
      // 	}
      // 	chmin(d[j], xx[ub] - vx[j]);
      // 	chmin(d[j], vx[j] - xx[ub-1]);
      // 	lb = 0, ub = sz(yy);
      // 	while(ub - lb > 1) {
      // 	  int mid = (ub + lb) / 2;
      // 	  (yy[mid] >= vy[j] ? ub : lb) = mid;
      // 	}
      // 	chmin(d[j], yy[ub] - vy[j]);
      // 	chmin(d[j], vy[j] - yy[ub-1]);
      // 	sum += d[j] * vp[j];
      // }
      chmin(res[cnt], sum);
    }
  }
  for(auto val: res) cout << val << "\n";
  return 0;
}
