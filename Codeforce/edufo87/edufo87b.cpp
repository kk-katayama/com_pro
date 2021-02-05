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
    string s; cin >> s;
    int n = sz(s);
    int f1 = -1, f2 = -1, f3 = -1;
    vi fro1(n),fro2(n),fro3(n);
    rep(i,n) {
      if(s[i] == '1') f1 = i;
      if(s[i] == '2') f2 = i;
      if(s[i] == '3') f3 = i;
      fro1[i] = f1;
      fro2[i] = f2;
      fro3[i] = f3;
    }
    int b1 = n, b2 = n, b3 = n;
    vi bac1(n),bac2(n),bac3(n);
    for (int i = n-1; i >= 0; --i) {
      if(s[i] == '1') b1 = i;
      if(s[i] == '2') b2 = i;
      if(s[i] == '3') b3 = i;
      bac1[i] = b1;
      bac2[i] = b2;
      bac3[i] = b3;
    }

    int res = inf;
    rep(i,n) {
      if(s[i] == '1') {
	if(fro2[i] != -1 && bac3[i] != n) chmin(res, bac3[i] - fro2[i] + 1);
	if(fro3[i] != -1 && bac2[i] != n) chmin(res, bac2[i] - fro3[i] + 1);	
      }
      if(s[i] == '2') {
	if(fro1[i] != -1 && bac3[i] != n) chmin(res, bac3[i] - fro1[i] + 1);
	if(fro3[i] != -1 && bac1[i] != n) chmin(res, bac1[i] - fro3[i] + 1);	
      }
      if(s[i] == '3') {
	if(fro2[i] != -1 && bac1[i] != n) chmin(res, bac1[i] - fro2[i] + 1);
	if(fro1[i] != -1 && bac2[i] != n) chmin(res, bac2[i] - fro1[i] + 1);	
      }      
    }
    cout << (res == inf ? 0 : res) << "\n";
  }
  return 0;
}
