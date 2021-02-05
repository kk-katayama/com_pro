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
  vector<char> ch(62);
  rep(i,26) {
    ch[i] = char(i + 'a');
  }
  rep(i,26) {
    ch[i+26] = char(i + 'A');
  }
  rep(i,10) {
    ch[i+52] = char(i + '0');
  }  
  int t; cin >> t;
  while(t-- > 0) {
    int r,c,k; cin >> r >> c >> k;
    vector<string> s(r);
    rep(i,r) cin >> s[i];

    int cnt = 0;
    rep(i,r) {
      rep(j,c) {
	if(s[i][j] == 'R') cnt++;
      }
    }

    int x = cnt / k;
    int y = cnt % k;
    int tmp = 0;
    int id = 0;
    vector<vector<char>> res(r, vector<char>(c));
    rep(i,r) {
      if(i % 2 == 0) {
	rep(j,c) {
	  if(y > 0) {
	    if(id == k) res[i][j] = ch[id-1];
	    else res[i][j] = ch[id];
	    if(s[i][j] == 'R') tmp++;
	    if(tmp == x+1) {
	      tmp = 0;
	      id++;
	      y--;
	    }
	  }
	  else {
	    if(id == k) res[i][j] = ch[id-1];
	    else res[i][j] = ch[id];	    
	    if(s[i][j] == 'R') tmp++;
	    if(tmp == x) {
	      tmp = 0;
	      id++;
	    }	    
	  }
	}
      }
      else {
	for(int j = c-1; j >= 0; --j) {
	  if(y > 0) {
	    if(id == k) res[i][j] = ch[id-1];
	    else res[i][j] = ch[id];	    
	    if(s[i][j] == 'R') tmp++;
	    if(tmp == x+1) {
	      tmp = 0;
	      id++;
	      y--;
	    }
	  }
	  else {
	    if(id == k) res[i][j] = ch[id-1];
	    else res[i][j] = ch[id];	    
	    if(s[i][j] == 'R') tmp++;
	    if(tmp == x) {
	      tmp = 0;
	      id++;
	    }	    
	  }
	}
      }      
    }
    rep(i,r) {
      rep(j,c) {
	cout << res[i][j];
      }
      cout << "\n";
    }
  }
  return 0;
}
