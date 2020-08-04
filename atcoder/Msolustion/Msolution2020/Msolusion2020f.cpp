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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int n; cin >> n;
  vector<int> x(n),y(n);
  vector<char> u(n);
  rep(i,n) {
    cin >> x[i] >> y[i] >> u[i];
  }
  using pic = pair<pi, char>;
  vector<pic> v;
  rep(i,n) {
    v.push_back({{x[i], y[i]}, u[i]});
  }

  sort(v.begin(), v.end(), [](pic a, pic b){
			     return a.F.F < b.F.F;
			   });
  int res = 2e+9;
  // L
  {
    map<int,int> R,U,D;
    rep(i,n) {
      if(v[i].S == 'R') {
	R[v[i].F.S] = v[i].F.F;
      }
      if(v[i].S == 'L') {
	if(R.find(v[i].F.S) != R.end()) {
	  int r = 5 * abs(v[i].F.F - R[v[i].F.S]);
	  chmin(res, r);
	}
	if(U.find(v[i].F.F - v[i].F.S) != U.end()) {
	  int u = 5 * abs((v[i].F.F + v[i].F.S) - U[v[i].F.F - v[i].F.S]);
	  chmin(res, u);
	}
	if(D.find(v[i].F.F + v[i].F.S) != D.end()) {
	  int d = 5 * abs((v[i].F.F - v[i].F.S) - D[v[i].F.F + v[i].F.S]);
	  chmin(res, d);
	}
      }
      if(v[i].S == 'U') {
	U[v[i].F.F - v[i].F.S] = v[i].F.F + v[i].F.S;
      }
      if(v[i].S == 'D') {
	D[v[i].F.F + v[i].F.S] = v[i].F.F - v[i].F.S;
      }
    }
  }
  // R
  {
    map<int,int> L,U,D;
    for (int i = n-1; i >= 0; --i) {
      if(v[i].S == 'R') {
	if(L.find(v[i].F.S) != L.end()) {
	  int l = 5 * abs(v[i].F.F - L[v[i].F.S]);
	  chmin(res, l);
	}
	if(U.find(v[i].F.F + v[i].F.S) != U.end()) {
	  int u = 5 * abs((v[i].F.F - v[i].F.S) - U[v[i].F.F + v[i].F.S]);
	  chmin(res, u);
	}
	if(D.find(v[i].F.F - v[i].F.S) != D.end()) {
	  int d = 5 * abs((v[i].F.F + v[i].F.S) - D[v[i].F.F - v[i].F.S]);
	  chmin(res, d);
	}	
      }
      if(v[i].S == 'L') {
	L[v[i].F.S] = v[i].F.F;
      }
      if(v[i].S == 'U') {
	U[v[i].F.F + v[i].F.S] = v[i].F.F - v[i].F.S;
      }
      if(v[i].S == 'D') {
	D[v[i].F.F - v[i].F.S] = v[i].F.F + v[i].F.S;
      }
    }
  }
  sort(v.begin(), v.end(), [](pic a, pic b) {
			     return a.F.S < b.F.S;
			   });
  // D
  {
    map<int,int> R,L,U;
    rep(i,n) {
      if(v[i].S == 'R') {
	R[v[i].F.F - v[i].F.S] = v[i].F.F + v[i].F.S;
      }
      if(v[i].S == 'L') {
	L[v[i].F.F + v[i].F.S] = v[i].F.F - v[i].F.S;
      }
      if(v[i].S == 'U') {
	U[v[i].F.F] = v[i].F.S;
      }
      if(v[i].S == 'D') {
	if(R.find(v[i].F.F - v[i].F.S) != R.end()) {
	  int r = 5 * abs((v[i].F.F + v[i].F.S) - R[v[i].F.F - v[i].F.S]);
	  chmin(res, r);
	}
	if(L.find(v[i].F.F + v[i].F.S) != L.end()) {
	  int l = 5 * abs((v[i].F.F - v[i].F.S) - L[v[i].F.F + v[i].F.S]);
	  chmin(res, l);
	}
	if(U.find(v[i].F.F) != U.end()) {
	  int u = 5 * abs(v[i].F.S - U[v[i].F.F]);
	  chmin(res, u);
	}
      }

    }
  }

  // U
  {
    map<int,int> R,L,D;
    for (int i = n - 1; i >= 0; --i) {
      if(v[i].S == 'R') {
	R[v[i].F.F + v[i].F.S] = v[i].F.F - v[i].F.S;
      }
      if(v[i].S == 'L') {
	L[v[i].F.F - v[i].F.S] = v[i].F.F + v[i].F.S;
      }
      if(v[i].S == 'U') {
	if(R.find(v[i].F.F + v[i].F.S) != R.end()) {
	  int r = 5 * abs((v[i].F.F - v[i].F.S) - R[v[i].F.F + v[i].F.S]);
	  chmin(res, r);
	}
	if(L.find(v[i].F.F - v[i].F.S) != L.end()) {
	  int l = 5 * abs((v[i].F.F + v[i].F.S) - L[v[i].F.F - v[i].F.S]);
	  chmin(res, l);
	}
	if(D.find(v[i].F.F) != D.end()) {
	  int d = 5 * abs(v[i].F.S - D[v[i].F.F]);
	  chmin(res, d);
	}
      }
      if(v[i].S == 'D') {
	D[v[i].F.F] = v[i].F.S;
      }
    }
  }    
  if(res == 2e+9) cout << "SAFE" << "\n";
  else cout << res << "\n";
  return 0;
}
