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
  ll n,k; cin >> n >> k;
  vvl t(n, vl(n));
  rep(i,n) {
    rep(j,n) {
      cin >> t[i][j];
    }
  }

  ll res = 0;
  vi vec(n-1);
  rep(i,n-1) vec[i] = i+1;
  do{
    ll sum = 0;
    int now = 0;
    rep(i,n-1) {
      sum += t[now][vec[i]];
      now = vec[i];
    }
    sum += t[now][0];
    if(sum == k) res++;
  } while(next_permutation(vec.begin(), vec.end()));
  cout << res << "\n";
  return 0;
}
