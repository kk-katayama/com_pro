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
#define rep(i,n) for(ll i = 0; i < n; ++i)
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
  int n; cin >> n;
  ll D,K; cin >> D >> K;
  vvl p(2);
  rep(i,n) {
    ll P,S; cin >> P >> S;
    P--;
    p[P].push_back(S);
  }

  ll res = n;
  rep(i,2) sort(p[i].begin(), p[i].end());
  vl dp1(2, 0);
  rep(i,n) {
    vl dp2(2, infll);
    int lb = -1, ub = sz(p[0]);
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (dp1[0] < p[0][mid] ? ub : lb) = mid;
    }
    if(ub != sz(p[0])) chmin(dp2[0], p[0][ub]);

    lb = -1, ub = sz(p[1]);
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (dp1[1] < p[1][mid] ? ub : lb) = mid;
    }
    if(ub != sz(p[1])) chmin(dp2[1], p[1][ub]);

    
    lb = -1, ub = sz(p[0]);
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (dp1[1] < p[0][mid] - D - K*i ? ub : lb) = mid;
    }
    if(ub != sz(p[0])) chmin(dp2[0], p[0][ub]);

    lb = -1, ub = sz(p[1]);
    while(ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (dp1[0] < p[1][mid] - D - K*i ? ub : lb) = mid;
    }
    if(ub != sz(p[1])) chmin(dp2[1], p[1][ub]);    

    if(dp2[0] == infll && dp2[1] == infll) {
      res = i;
      break;
    }
    //    cout << dp2[0] << ":" << dp2[1] << "\n";
    swap(dp1, dp2);
  }
  cout << res << "\n";
  return 0;
}
