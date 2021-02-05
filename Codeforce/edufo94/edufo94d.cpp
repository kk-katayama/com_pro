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
    vi a(n);
    rep(i,n) scanf("%d", &a[i]);
    vi mp(n+1, 0);
    rep(i,n) {
      mp[a[i]]++;
    }

    mp[a[0]]--;
    ll res = 0;
    rep(i,n-3) {
      mp[a[i+1]]--;
      vi mp1(n+1, 0), mp2;
      mp2 = mp;
      ll sum = 0;
      for (int j = i+1; j < n-1; ++j) {
	sum -= mp1[a[j+1]];
	mp2[a[j+1]]--;
	mp1[a[j]]++;
	sum += mp2[a[j]];
	if(a[i] == a[j+1]) res += sum;
      }      
    }
    cout << res << "\n";
  }
  return 0;
}
