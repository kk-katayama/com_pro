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
  int n,m,k; cin >> n >> m >> k;
  vector<pi> p(m);
  rep(i,m) {
    int a,b; cin >> a >> b;
    a--;
    p[i] = {a, b};
  }

  sort(p.begin(), p.end(), [](pi a, pi b){
    return a.first + a.second < b.first + b.second;
  });

  vi pre(m, 0), suf(m, 0);
  rep(i,n-k+1) {
    int sum = 0;
    rep(j,m) {
      sum += max(0, min(p[j].second, i+k) - max(p[j].first, i));
      chmax(pre[j], sum);
    }
  }

  rep(i,n-k+1) {
    int sum = 0;
    for (int j = m-1; j >= 0; --j) {
      sum += max(0, min(p[j].second, i+k) - max(p[j].first, i));
      chmax(suf[j], sum);
    }
  }  

  int res = max(pre[m-1], suf[0]);
  rep(i,m-1) {
    chmax(res, pre[i] + suf[i+1]);
  }
  cout << res << "\n";
  
  return 0;
}
