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
  vi a;
  rep(i,n) {
    int tmp; cin >> tmp;
    if(tmp < k) a.push_back(tmp);
  }
  int m = sz(a);
  
  vvi dp1(m+1, vi(k, 0));
  dp1[0][0] = 1;
  rep(i,m) {
    rep(j,k) {
      if(dp1[i][j] == 0) continue;
      if(j+a[i] < k) dp1[i+1][j+a[i]] = 1;
      dp1[i+1][j] = 1;
    }
  }

  vvi dp2(m+1, vi(k, 0));
  dp2[0][0] = 1;
  int id = 0;
  for(int i = m-1; i >= 0; --i) {
    rep(j,k) {
      if(dp2[id][j] == 0) continue;
      if(j+a[i] < k) dp2[id+1][j+a[i]] = 1;
      dp2[id+1][j] = 1;
    }
  }

  vvi vec1(m+1), vec2(m+1);
  rep(i,m+1) {
    rep(j,k) {
      if(dp1[i][j]) vec1.push_back()
    }
  }

  return 0; 
}
