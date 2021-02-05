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
  int n,k; cin >> n >> k;
  string s; cin >> s;
  vi pow2(k+1);
  pow2[0] = 1;
  rep(i,k) {
    pow2[i+1] = min(101, pow2[i]*2);
  }

  auto f = [](char a, char b)->char{
    if(a == b) return a;
    if((a == 'R' && b == 'S') || (a == 'P' && b == 'R') || (a == 'S' && b == 'P')) return a;
    else return b;
  };
  for (int i = k; i > 0; --i) {
    int m = sz(s);
    string t = "";
    if(m >= pow2[k]) {
      rep(i,pow2[k]) {
	char x = f(s[i], s[i+1]);
	i++;
	t.push_back(x);
      }
    }
    else {
      if(m % 2 == 0) {
	rep(i,m) {
	  char x = f(s[i], s[i+1]);
	  i++;
	  t.push_back(x);
	}	
      }
      else {
	s += s;
	rep(i,2*m) {
	  char x = f(s[i], s[i+1]);
	  i++;
	  t.push_back(x);
	}	
      }
    }
    swap(s,t);
  }

  cout << s[0] << "\n";
  return 0;
}
