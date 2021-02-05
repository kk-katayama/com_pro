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
  int n, Q; cin >> n >> Q;
  int M = 1;
  rep(i,n) M *= 3;
  auto n2a = [&](int num)-> vi{
    vi res;
    rep(i,n) {
      res.push_back(num % 3);
      num /= 3;
    }
    return res;
  };

  auto a2n = [&](vi arr)-> int{
    int res = 0;
    int bit = 1;
    rep(i,n) {
      res += arr[i]*bit;
      bit *= 3;
    }
    return res;
  };

  vi d(M, inf);
  queue<int> q;
  rep(i,M) {
    vi tmp = n2a(i);
    bool f = true;
    rep(i,n-1) {
      if(tmp[i] > tmp[i+1]) f = false;
    }
    if(f) {
      q.push(i);
      d[i] = 0;
    }
  }

  while( !q.empty() ) {
    int id = q.front(); q.pop();
    vi buf = n2a(id);
    rep(i,n) {
      int tmp = 0;
      int bit = 1;
      for (int j = i; j >= 0; --j) {
	tmp += buf[j]*bit;
	bit *= 3;
      }
      for (int j = i+1; j < n; ++j) {
	tmp += buf[j]*bit;
	bit *= 3;
      }
      if(d[tmp] == inf) {
	d[tmp] = d[id] + 1;
	q.push(tmp);
      }
    }
  }
  
  
  while(Q-- > 0) {
    string s; cin >> s;
    int tmp = 0;
    int bit = 1;
    rep(i,n) {
      if(s[i] == 'B') tmp += bit;
      if(s[i] == 'C') tmp += bit*2;
      bit *= 3;
    }
    cout << d[tmp] << "\n";
  }
  return 0;
}
