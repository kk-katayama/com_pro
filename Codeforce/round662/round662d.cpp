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
  int n,m; cin >> n >> m;
  using vc = vector<char>;
  using vcc = vector<vc>;
  vcc s(n, vc(m));
  rep(i,n) rep(j,m) cin >> s[i][j];

  using vi = vector<int>;
  using vii = vector<vi>;
  vii u(n, vi(m, 0));
  vii d(n, vi(m, 0));
  vii r(n, vi(m, 0));  
  vii l(n, vi(m, 0));
  rep(j,m) {
    int cnt = 1;
    rep(i,n) {
      if(i == 0) u[i][j] = 1;
      else if(s[i-1][j] == s[i][j]) {
	cnt++;
	u[i][j] = cnt;
      }
      else {
	cnt = 1;
	u[i][j] = cnt;	
      }
    }
  }
  // d
  rep(j,m) {
    int cnt = 1;
    for(int i = n - 1; i >= 0; --i) {
      if(i == n - 1) {
	u[i][j] = min(u[i][j], 1);
      }
      else if(s[i+1][j] == s[i][j]) {
	cnt++;
	u[i][j] = min(u[i][j], cnt);	
      }
      else {
	cnt = 1;
	u[i][j] = min(u[i][j], cnt);		
      }
    }
  }  

  vii num(n, vi(m));
  // rep(i,n) rep(j,m) {
  //   num[i][j] = min(u[i][j], d[i][j]);
  // }

  // rep(i,n) {
  //   rep(j,m) cout << u[i][j];
  //   cout << "\n";
  // }
  // cout << "******" << "\n";
  // rep(i,n) {
  //   rep(j,m) cout << d[i][j];
  //   cout << "\n";
  // }
  // cout << "******" << "\n";    

  rep(i,n) {
    int cnt = 1;
    rep(j,m) {
      if(j == 0) l[i][j] = 1;
      else if(s[i][j-1] == s[i][j]) {
	cnt++;
	l[i][j] = cnt;
      }
      else {
	cnt = 1;
	l[i][j] = cnt;	
      }
    }
  }
  rep(i,n) {
    int cnt = 1;
    for (int j = m - 1; j >= 0; --j) {
      if(j == m - 1) {
	l[i][j] = min(l[i][j], 1);
      }
      else if(s[i][j+1] == s[i][j]) {
	cnt++;
	l[i][j] = min(l[i][j], cnt);	
      }
      else {
	cnt = 1;
	l[i][j] = min(l[i][j], cnt);		
      }
    }
  }  
  
  rep(i,n) {
    int cnt = 1;
    rep(j,m) {
      if(j == 0) num[i][j] = 1;
      else if(cnt < u[i][j]) {
	cnt++;
	num[i][j] = cnt;
      }
      else {
	cnt = u[i][j];
	num[i][j] = cnt;
      }
    }
  }

  rep(i,n) {
    int cnt = 1;
    for(int j = m - 1; j >= 0; --j) {
      if(j == m - 1) {
	num[i][j] = min(l[i][j], min(num[i][j], 1));
      }
      else if(cnt < u[i][j]) {
	cnt++;
	num[i][j] = min(l[i][j], min(num[i][j], cnt));	
      }
      else {
	cnt = u[i][j];
	num[i][j] = min(l[i][j], min(num[i][j], cnt));		
      }
    }
  }  

  ll res = 0;
  rep(i,n) {
    rep(j,m) {
      ll tmp = (ll)num[i][j];
      res += tmp;
    }
  }

  cout << res << "\n";
  
  
  return 0;
}
