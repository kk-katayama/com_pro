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
  vector<char> a(13), b(13);
  vector<int> x(13), y(13);  
  rep(i,13) {
    a[i] = 'a' + 2*i;
    x[i] = 2*i;
  }
  rep(i,13) {
    b[i] = 'b' + 2*i;
    y[i] = 2*i + 1;    
  }  

  vi p = {2, 3, 5, 7, 11, 13};
  int m = 13;
  vvi s(m, vi(m));  
  cout << m << "\n";
  rep(i,m/2) {
    int j = 0;
    rep(c,m) {
      //      cout << a[j];
      s[2*i][c] = x[j];
      //      cout << x[j] << " ";
      j = (j + p[i] - 1) % 13;
    }
    //    cout << "\n";
    j = i;
    rep(c,m) {
      //      cout << b[j];
      s[2*i+1][c] = y[j];      
      //      cout << y[j] << " ";      
      j = (j + p[i] - 1) % 13;
    }    
    //    cout << "\n";
  }
  int j = 0;
  rep(c,m) {
    //    cout << a[j];
    s[m-1][c] = x[j];    
    //    cout << x[j] << " ";    
    j = (j + m/2 + 1) % 13;
  }
  //  cout << "\n";  

  map<pi,pi> mp;
  int cnt = 0;
  rep(i,m) {
    rep(j,m) {
      if(i + 1 < m) {
	if(mp[{s[i][j], s[i+1][j]}] != pi{0, 0}) {
	  // cout << "(" << i << "," << j << ") ";
	  // cnt++;
	  
	  // cout << "(" << mp[{s[i][j], s[i+1][j]}].first << "," << mp[{s[i][j], s[i+1][j]}].second << ")\n";
	  swap(s[i][j], s[i][(j+1)%13]);	  
	  //	  swap(s[i][j], s[mp[{s[i][j], s[i+1][j]}].first][mp[{s[i][j], s[i+1][j]}].second]);
	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
	}
	mp[{s[i][j], s[i+1][j]}] = {i, j};
      }
      if(j + 1 < m) {
	if(mp[{s[i][j], s[i][j+1]}] != pi{0, 0}) {
	  cout << "(" << i << "," << j << ") ";
	  cnt++;
	  
	  cout << "(" << mp[{s[i][j], s[i][j+1]}].first << "," << mp[{s[i][j], s[i][j+1]}].second << ")\n";
	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
	}
	mp[{s[i][j], s[i][j+1]}] = {i, j};	  
      }            
    }
  }
  cout << cnt << "\n";

  s[12][4] = 1;
  s[12][5] = 5;
  s[12][7] = 23;
  s[12][11] = 13;  
  
  mp.clear();
  cnt = 0;
  rep(i,m) {
    rep(j,m) {
      if(i + 1 < m) {
	if(mp[{s[i][j], s[i+1][j]}] != pi{0, 0}) {
	  // cout << "(" << i << "," << j << ") ";
	  // cnt++;
	  
	  // cout << "(" << mp[{s[i][j], s[i+1][j]}].first << "," << mp[{s[i][j], s[i+1][j]}].second << ")\n";
	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
	}
	mp[{s[i][j], s[i+1][j]}] = {i, j};
      }
      if(j + 1 < m) {
	if(mp[{s[i][j], s[i][j+1]}] != pi{0, 0}) {
	  cout << "(" << i << "," << j << ") ";
	  cnt++;
	  
	  cout << "(" << mp[{s[i][j], s[i][j+1]}].first << "," << mp[{s[i][j], s[i][j+1]}].second << ")\n";
	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
	}
	mp[{s[i][j], s[i][j+1]}] = {i, j};	  
      }            
    }
  }
  cout << cnt << "\n";

  mp.clear();
  cnt = 0;
  rep(i,m) {
    rep(j,m) {
      if(i + 1 < m) {
	if(mp[{s[i][j], s[i+1][j]}] != pi{0, 0}) {
	  // cout << "(" << i << "," << j << ") ";
	  // cnt++;
	  
	  // cout << "(" << mp[{s[i][j], s[i+1][j]}].first << "," << mp[{s[i][j], s[i+1][j]}].second << ")\n";
	  //	  swap(s[i][j], s[i][(j+11)%13]);	  
	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
	}
	mp[{s[i][j], s[i+1][j]}] = {i, j};
      }
      if(j + 1 < m) {
	if(mp[{s[i][j], s[i][j+1]}] != pi{0, 0}) {
	  cout << "(" << i << "," << j << ") ";
	  cnt++;
	  
	  cout << "(" << mp[{s[i][j], s[i][j+1]}].first << "," << mp[{s[i][j], s[i][j+1]}].second << ")\n";
	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
	}
	mp[{s[i][j], s[i][j+1]}] = {i, j};	  
      }            
    }
  }
  cout << cnt << "\n";  

  // mp.clear();
  // cnt = 0;
  // rep(i,m) {
  //   rep(j,m) {
  //     if(i + 1 < m) {
  // 	if(mp[{s[i][j], s[i+1][j]}] != pi{0, 0}) {
  // 	  // cout << "(" << i << "," << j << ") ";
  // 	  // cnt++;
	  
  // 	  // cout << "(" << mp[{s[i][j], s[i+1][j]}].first << "," << mp[{s[i][j], s[i+1][j]}].second << ")\n";
  // 	  swap(s[i][j], s[i][(j+3)%13]);	  
  // 	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
  // 	}
  // 	mp[{s[i][j], s[i+1][j]}] = {i, j};
  //     }
  //   }
  // }
  // //  cout << cnt << "\n";

  // swap(s[9][7], s[9][0]);
  // swap(s[11][12], s[11][0]);
  // swap(s[11][12], s[10][12]);  
  
  // mp.clear();
  // cnt = 0;
  // rep(i,m) {
  //   rep(j,m) {
  //     if(i + 1 < m) {
  // 	if(mp[{s[i][j], s[i+1][j]}] != pi{0, 0}) {
  // 	  cout << "(" << i << "," << j << ") ";
  // 	  cnt++;
	  
  // 	  cout << "(" << mp[{s[i][j], s[i+1][j]}].first << "," << mp[{s[i][j], s[i+1][j]}].second << ")\n";
  // 	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
  // 	}
  // 	mp[{s[i][j], s[i+1][j]}] = {i, j};
  //     }
  //   }
  // }

  // mp.clear();
  // cnt = 0;
  // rep(i,m) {
  //   rep(j,m) {
  //     if(i + 1 < m) {
  // 	if(mp[{s[i][j], s[i+1][j]}] != pi{0, 0}) {
  // 	  cout << "(" << i << "," << j << ") ";
  // 	  cnt++;
	  
  // 	  cout << "(" << mp[{s[i][j], s[i+1][j]}].first << "," << mp[{s[i][j], s[i+1][j]}].second << ")\n";
  // 	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
  // 	}
  // 	mp[{s[i][j], s[i+1][j]}] = {i, j};	  
  //     }
  //     if(j + 1 < m) {
  // 	if(mp[{s[i][j], s[i][j+1]}] != pi{0, 0}) {
  // 	  cout << "(" << i << "," << j << ") ";
  // 	  cnt++;
	  
  // 	  cout << "(" << mp[{s[i][j], s[i][j+1]}].first << "," << mp[{s[i][j], s[i][j+1]}].second << ")\n";
  // 	  //	  cout << s[i][j] << " " << s[i+1][j] << "\n";
  // 	}
  // 	mp[{s[i][j], s[i][j+1]}] = {i, j};	  
  //     }      
  //   }
  // }
  // cout << cnt << "\n";
  
  rep(i,13) {
    rep(j,13) {
      cout << s[i][j] << " ";
      //      cout << (char)('a' + s[i][j]);
    }
    cout << "\n";
  }
  
  return 0;
}
