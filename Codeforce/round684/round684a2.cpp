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

  int q; cin >> q;
  while(q-- > 0) {
    int n,m; cin >> n >> m;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<string> t = s;
    auto rev = [&](int x, int y){
      if(s[x][y] == '1') s[x][y] = '0';
      else s[x][y] = '1';
    };
    vvi res;
    if(m % 2 == 1) {
      rep(i,n-2) {
	if(s[i][0] == '1') {
	  vi v = {i+1, 1, i+1, 2, i+2, 2};
	  res.push_back(v);
	  rev(i, 1); rev(i+1, 1); rev(i, 0);
	}
      }
    }
    if(n % 2 == 1) {
      for (int j = m-1; j >= 2; --j) {
	if(s[n-1][j] == '1') {
	  vi v = {n, j+1, n-1, j+1, n-1, j};
	  res.push_back(v);
	  rev(n-2, j); rev(n-2, j-1); rev(n-1, j);
	}
      }
    }

    // rep(i,n) {
    //   rep(j,m) cout << s[i][j];
    //   cout << "\n";
    // }

    if(n % 2 == 1 || m % 2 == 1) {
      int i = n-2, j = 0;
      vvi tmp(4);
      tmp[0] = {i+1, j+1, i+1, j+2, i+2, j+2};
      tmp[1] = {i+1, j+2, i+2, j+2, i+2, j+1};
      tmp[2] = {i+2, j+2, i+2, j+1, i+1, j+1};
      tmp[3] = {i+2, j+1, i+1, j+1, i+1, j+2};
      int cnt = 0;
      if(s[i][j] == '1') {
	cnt++;
      }
      if(s[i+1][j] == '1') {
	cnt++;
      }
      if(s[i][j+1] == '1') {
	cnt++;
      }
      if(s[i+1][j+1] == '1') {
	cnt++;
      }
      if(cnt == 1) {
	rep(k,4) {
	  rep(l,6) {
	    int ni = tmp[k][l], nj = tmp[k][l+1];
	    if(s[ni-1][nj-1] == '1') {
	      res.push_back(tmp[k]);
	      break;
	    }
	    l++;
	  }
	}
      }
      if(cnt == 2) {
	rep(k,4) {
	  int c = 0;
	  rep(l,6) {
	    int ni = tmp[k][l], nj = tmp[k][l+1];
	    if(s[ni-1][nj-1] == '1') {
	      c++;
	    }
	    l++;
	  }
	  if(c == 1) {
	    res.push_back(tmp[k]);
	  }
	}	    
      }
      if(cnt == 3) {
	rep(k,4) {
	  int c = 0;
	  rep(l,6) {
	    int ni = tmp[k][l], nj = tmp[k][l+1];
	    if(s[ni-1][nj-1] == '1') {
	      c++;
	    }
	    l++;
	  }
	  if(c == 3) {
	    res.push_back(tmp[k]);
	  }
	}	    	    
      }
      if(cnt == 4) {
	res.push_back(tmp[2]);
      }
      s[n-1][0] = '0';
      if(cnt != 4) s[n-2][1] = '0';
      s[n-1][1] = '0';
      s[n-2][0] = '0';      
    }
    // rep(i,n) {
    //   rep(j,m) cout << s[i][j];
    //   cout << "\n";
    // }

    int sta = (m % 2 == 1 ? 1 : 0);
    for (int i = 0; i < n; i += 2) {
      for (int j = sta; j < m; j += 2) {
	//	cout << i << ":" << j << "\n";
	if(i + 1 < n && j + 1 < m) {
	  vvi tmp(4);
	  tmp[0] = {i+1, j+1, i+1, j+2, i+2, j+2};
	  tmp[1] = {i+1, j+2, i+2, j+2, i+2, j+1};
	  tmp[2] = {i+2, j+2, i+2, j+1, i+1, j+1};
	  tmp[3] = {i+2, j+1, i+1, j+1, i+1, j+2};	  
	  int cnt = 0;
	  if(s[i][j] == '1') {
	    cnt++;
	  }
	  if(s[i+1][j] == '1') {
	    cnt++;
	  }
	  if(s[i][j+1] == '1') {
	    cnt++;
	  }
	  if(s[i+1][j+1] == '1') {
	    cnt++;
	  }
	  if(cnt == 0) continue;
	  if(cnt == 1) {
	    rep(k,4) {
	      rep(l,6) {
		int ni = tmp[k][l], nj = tmp[k][l+1];
		if(s[ni-1][nj-1] == '1') {
		  res.push_back(tmp[k]);
		  break;
		}
		l++;
	      }
	    }
	  }
	  if(cnt == 2) {
	    rep(k,4) {
	      int c = 0;
	      rep(l,6) {
		int ni = tmp[k][l], nj = tmp[k][l+1];
		if(s[ni-1][nj-1] == '1') {
		  c++;
		}
		l++;
	      }
	      if(c == 1) {
		res.push_back(tmp[k]);
	      }
	    }	    
	  }
	  if(cnt == 3) {
	    rep(k,4) {
	      int c = 0;
	      rep(l,6) {
		int ni = tmp[k][l], nj = tmp[k][l+1];
		if(s[ni-1][nj-1] == '1') {
		  c++;
		}
		l++;
	      }
	      if(c == 3) {
		res.push_back(tmp[k]);
	      }
	    }	    	    
	  }
	  if(cnt == 4) {
	    rep(k,4) {
	      res.push_back(tmp[k]);
	    }	    	    
	  }	  
	}
      }
    }
    cout << sz(res) << "\n";
    rep(i,sz(res)) {
      rep(j,6) cout << res[i][j] << " ";
      cout << "\n";
    }
    // s = t;
    // rep(i,sz(res)) {
    //   rep(j,6) {
    // 	int ni = res[i][j], nj = res[i][j+1];
    // 	rev(ni-1, nj-1);
    // 	j++;
    //   }
    // }
    // rep(i,n) {
    //   rep(j,m) cout << s[i][j];
    //   cout << "\n";
    // }
  }
  return 0;
}
