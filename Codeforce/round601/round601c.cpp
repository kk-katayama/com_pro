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
  vi cnt(n+1, 0);
  vvi edge(n+1);
  map<pi,vi> mp;
  rep(i,n-2) {
    int a,b,c; cin >> a >> b >> c;
    cnt[a]++; cnt[b]++; cnt[c]++;
    edge[a].push_back(b);
    edge[a].push_back(c);
    edge[b].push_back(a);
    edge[b].push_back(c);
    edge[c].push_back(b);
    edge[c].push_back(a);
    mp[{min(a,b), max(a,b)}].push_back(c);
    mp[{min(b,c), max(b,c)}].push_back(a);
    mp[{min(c,a), max(c,a)}].push_back(b);    
  }

  int s;
  rep1(i,n) {
    if(cnt[i] == 1) {
      s = i;
      break;
    }
  }

  int x = edge[s][0], y = edge[s][1];
  if(cnt[x] > cnt[y]) swap(x,y);
  vi res(n);
  res[0] = s;
  res[1] = x;
  rep(i,n-2) {
    cnt[res[i]]--;
    cnt[res[i+1]]--;
    for(auto val: mp[{min(res[i], res[i+1]), max(res[i], res[i+1])}]) {
      if(cnt[val] > 0) {
	res[i+2] = val;
	cnt[val]--;
      }
    }
  }
  for(auto val: res) cout << val << " ";
  cout  << "\n";
  
  return 0;
}
