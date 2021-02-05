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
  int n; cin >> n;
  vector<pl> p(n);
  rep(i,n) {
    cin >> p[i].first >> p[i].second;
  }

  sort(p.begin(), p.end(), [](pl a, pl b){
    return a.first*2 + a.second > b.first*2 + b.second;
  });

  ll sum = 0;
  rep(i,n) {
    sum += p[i].first;
  }

  rep(i,n) {
    sum -= p[i].first*2 + p[i].second;
    if(sum < 0) {
      cout << i+1 << "\n";
      return 0;
    }
  }
  
  return 0;
}
