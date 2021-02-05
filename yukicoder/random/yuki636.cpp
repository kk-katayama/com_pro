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

  vvl dp1(2, vl(2, infll/2));
  dp1[0][0] = 0;
  dp1[1][0] = 1;
  rep(i,n) {
    vvl dp2(2, vl(2, infll/2));
    int c = int(s[i] - '0');
    rep(j,10) {
      if(c < j) {
	if(c+1 < j) chmin(dp2[1][1], dp1[0][0] + j/5 + j%5 + (j-c-1)/5 + (j-c-1)%5);
	chmin(dp2[1][1], dp1[1][0] + j/5 + j%5 + (j-c-1)/5 + (j-c-1)%5);	      
	chmin(dp2[1][0], dp1[1][0] + j/5 + j%5 + (j-c)/5 + (j-c)%5);
	chmin(dp2[1][0], dp1[0][0] + j/5 + j%5 + (j-c)/5 + (j-c)%5);	
      }
      if(c == j) {
	chmin(dp2[1][1], dp1[1][0] + j/5 + j%5 + (9)/5 + (9)%5);
	chmin(dp2[1][0], dp1[1][0] + j/5 + j%5);
	chmin(dp2[0][0], dp1[0][0] + j/5 + j%5);
      }
      if(c > j) {
	chmin(dp2[1][1], dp1[1][0] + j/5 + j%5 + (9 + j - c)/5 + (9 + j - c)%5);
	chmin(dp2[1][1], dp1[1][1] + j/5 + j%5 + (9 + j - c)/5 + (9 + j - c)%5);
	chmin(dp2[1][0], dp1[1][0] + j/5 + j%5 + (10 + j - c)/5 + (10 + j - c)%5);
	chmin(dp2[1][0], dp1[1][1] + j/5 + j%5 + (10 + j - c)/5 + (10 + j - c)%5);		
      }
    }
    swap(dp1, dp2);
    //    cout << i << ":" << dp1[0][0] << ":" << dp1[1][0] << ";" << dp1[0][1] << ":" << dp1[1][1] << "\n";
  }
  cout << min(dp1[0][0], dp1[1][0]) << "\n";
  
  return 0;
}
