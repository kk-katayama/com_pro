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
// ランレングス圧縮.配列の連続している要素をまとめてしまう圧縮.
vector<pair<int,int>> rle(vector<int> a){
  vector<pair<int,int>> res;
  int n = a.size();
  int cnt = 1;
  pair<int,int> p;
  p.first = a[0];
  rep(i,n-1){
    if(a[i]==a[i+1]){
      cnt++;
    }
    else{
      p.second = cnt;
      res.push_back(p);
      cnt = 1;
      p.first = a[i+1];
    }
  }
  p.second = cnt;
  res.push_back(p);
  return res;
}


int main()
{
  int n,m; cin >> n >> m;
  vi x(n);
  rep(i,n) cin >> x[i];

  sort(x.begin(), x.end());
  vector<pi> r = rle(x);
  vi kosu(m, 0), noko(m, 0);
  for(auto val: r) {
    auto [num, cnt] = val;
    kosu[num % m] += cnt;
    noko[num % m] += cnt / 2 * 2;
  }

  int res = 0;
  res += kosu[0] / 2;
  for(int i = 1; 2*i <= m; ++i) {
    if(i == m - i) {
      res += kosu[i] / 2;
      continue;
    }
    if(kosu[i] < kosu[m-i]) {
      res += kosu[i];
      res += max(0, min(kosu[m-i] - kosu[i], noko[m-i]) / 2);
    }
    else {
      res += kosu[m-i];
      res += max(0, min(kosu[i] - kosu[m-i], noko[i]) / 2);      
    }
  }
  cout << res << "\n";
  
  return 0;
}
