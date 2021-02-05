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
  int n, I; cin >> n >> I;
  vi a(n);
  rep(i,n) cin >> a[i];

  sort(a.begin(), a.end());
  vector<pi> p = rle(a);
  int m = sz(p);
  vi b(m);
  rep(i,m) {
    b[i] = p[i].second;
  }

  int mx = 8*I / n;
  int t = 1;
  if(t >= m) {
    cout << 0 << "\n";
    return 0;
  }  
  while(mx > 0) {
    t *= 2;
    if(t >= m) {
      cout << 0 << "\n";
      return 0;
    }
    mx--;
  }
  int sum = 0;
  rep(i,m) {
    sum += b[i];
  }

  int tmp = 0;
  rep(i,t) {
    tmp += b[i];
  }

  int res = sum - tmp;
  for (int i = t; i < m; ++i) {
    tmp += b[i];
    tmp -= b[i-t];
    chmin(res, sum - tmp);
  }
  cout << res << "\n";
  
  return 0;
}

