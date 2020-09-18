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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rep1(i,n) for(int i = 1; i <= n; ++i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
int main()
{
  int t; cin >> t;
  while(t-- > 0) {
    int n; cin >> n;
    string s; cin >> s;
    map<int,ll> mp;
    int sum = 0;
    mp[0] = 1;
    ll res = 0;
    rep(i,n) {
      int x = s[i] - '0';
      sum += x;
      int k = sum - (i + 1);
      res += mp[k];
      mp[k]++;
    }
    cout << res << "\n";
  }
  return 0;
}
