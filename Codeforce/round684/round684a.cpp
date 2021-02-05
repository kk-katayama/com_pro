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
  auto prin = [](int a, int b){
    cout << a << " " << b << " ";
  };
  int q; cin >> q;
  while(q-- > 0) {
    int n,m; cin >> n >> m;
    vector<string> s(n);
    rep(i,n) {
      cin >> s[i];
    }
    int cnt = 0;
    rep(i,n) {
      rep(j,m) {
	if(s[i][j] == '1') {
	  cnt++;
	}
      }
    }
    cout << cnt*3 << "\n";
    rep(i,n) {
      rep(j,m) {
	if(s[i][j] == '1') {
	  if(i + 1 < n && j + 1 < m) {
	    prin(i+1, j+1);
	    prin(i+1, j+2);
	    prin(i+2, j+1);
	    cout << "\n";
	    prin(i+1, j+1);
	    prin(i+1, j+2);
	    prin(i+2, j+2);
	    cout << "\n";
	    prin(i+1, j+1);
	    prin(i+2, j+1);
	    prin(i+2, j+2);
	    cout << "\n";	    
	  }
	  else if(i + 1 < n && j - 1 >= 0) {
	    prin(i+1, j+1);
	    prin(i+1, j);
	    prin(i+2, j+1);
	    cout << "\n";
	    prin(i+1, j+1);
	    prin(i+1, j);
	    prin(i+2, j);
	    cout << "\n";
	    prin(i+1, j+1);
	    prin(i+2, j+1);
	    prin(i+2, j);
	    cout << "\n";	    	    
	  }
	  else if(i - 1 >= 0 && j + 1 < m) {
	    prin(i+1, j+1);
	    prin(i+1, j+2);
	    prin(i, j+1);
	    cout << "\n";
	    prin(i+1, j+1);
	    prin(i+1, j+2);
	    prin(i, j+2);
	    cout << "\n";
	    prin(i+1, j+1);
	    prin(i, j+1);
	    prin(i, j+2);
	    cout << "\n";	    
	  }
	  else if(i - 1 >= 0 && j - 1 >= 0) {
	    prin(i+1, j+1);
	    prin(i+1, j);
	    prin(i, j+1);
	    cout << "\n";
	    prin(i+1, j+1);
	    prin(i+1, j);
	    prin(i, j);
	    cout << "\n";
	    prin(i+1, j+1);
	    prin(i, j+1);
	    prin(i, j);
	    cout << "\n";	    	    
	  }
	}
      }
    }
  }
  return 0;
}
