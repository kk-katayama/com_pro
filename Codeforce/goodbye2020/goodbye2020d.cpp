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
    int n; cin >> n;
    vl w(n);
    rep(i,n) scanf("%lld", &w[i]);
    vector<pl> p;
    vl num(n, 0);
    rep(i,n-1) {
      int a,b; scanf("%d%d", &a, &b);
      a--; b--;
      num[a]++;
      num[b]++;
    }
    ll sum = 0;
    rep(i,n) {
      sum += w[i];
      if(num[i] == 1) continue;
      p.push_back({w[i], num[i]});
    }
    sort(p.begin(), p.end(), [](pl a, pl b){
      return a.first > b.first;
    });
    int idx = 0;
    rep(i,n-1) {
      cout << sum << " ";
      if(i == n-2) break;
      sum += p[idx].first;
      p[idx].second--;
      if(p[idx].second == 1) idx++;
    }
    cout << "\n";
  }
  return 0;
}
