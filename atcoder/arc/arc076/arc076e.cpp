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
#include <stack>
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
  int r,c; cin >> r >> c;
  int n; cin >> n;
  vector<pi> x0,y0,xr,yc;
  rep(i,n) {
    int x,y; cin >> x >> y;
    if(x == 0) x0.push_back({y,i});
    else if(x == r) xr.push_back({y,i});
    else if(y == 0) y0.push_back({x,i});
    else if(y == c) yc.push_back({x,i});
    cin >> x >> y;
    if(x == 0) x0.push_back({y,i});
    else if(x == r) xr.push_back({y,i});
    else if(y == 0) y0.push_back({x,i});
    else if(y == c) yc.push_back({x,i});
  }

  sort(x0.begin(),x0.end());
  sort(y0.begin(),y0.end());
  sort(xr.begin(),xr.end());
  sort(yc.begin(),yc.end());

  reverse(xr.begin(),xr.end());
  reverse(y0.begin(),y0.end());

  vector<pi> arr;
  for(auto tmp: x0) arr.push_back(tmp);
  for(auto tmp: yc) arr.push_back(tmp);
  for(auto tmp: xr) arr.push_back(tmp);
  for(auto tmp: y0) arr.push_back(tmp);
  
  vi cnt(n, 0);
  for(auto tmp: arr) {
    cnt[tmp.second]++;
  }

  stack<int> sta;
  for(auto tmp: arr) {
    auto [i, num] = tmp;
    if(cnt[num] == 1) continue;
    if( !sta.empty() ) {
      int num2 = sta.top();
      if(num == num2) sta.pop();
      else sta.push(num);
    }
    else sta.push(num);
  }
  if( sta.empty() ) cout << "YES" << "\n";
  else cout << "NO" << "\n";
  return 0;
}
