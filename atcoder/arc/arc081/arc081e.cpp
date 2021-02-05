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
  string s; cin >> s;

  int n = sz(s);
  vvi id(26);
  rep(i,n) {
    int c = int(s[i] - 'a');
    id[c].push_back(i);
  }

  vi table(26, 0), d(n);
  int sum = 0, cnt = 0;
  
  for (int i = n-1; i >= 0; --i) {
    int c = int(s[i] - 'a');
    if(table[c] == 0) {
      table[c] = 1;
      sum++;
    }
    if(sum == 26) {
      table.assign(26, 0);
      sum = 0;
      cnt++;
    }
    d[i] = cnt;
  }
  d.push_back(0);
  
  int x = d[0];
  int piv = -1;
  string res;
  rep(i,d[0]+1) {
    rep(j,26) {
      int lb = -1, ub = sz(id[j]);
      while(ub - lb > 1) {
	int mid = (ub + lb) / 2;
	(piv < id[j][mid] ? ub : lb) = mid;
      }
      if(i == d[0] && ub == sz(id[j])) {
	res.push_back(char('a' + j));
	break;	
      }
      int tmp = id[j][ub] + 1;
      if(d[tmp] == x-1) {
	res.push_back(char('a' + j));
	piv = tmp-1;
	x--;
	break;
      }
    }
  }

  cout << res << "\n";
  
  return 0;
}
