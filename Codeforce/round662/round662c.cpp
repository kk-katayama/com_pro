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
    vector<int> a(n);
    map<int,int> mp;
    rep(i,n) {
      cin >> a[i];
      mp[a[i]]++;
    }
    int cnt = 1;int maxi = 0;
    for(auto val: mp) {
      if(val.second > maxi) {
	maxi = val.second;
	cnt = 1;
      }
      else if(val.second == maxi) {
	cnt++;
      }
    }
    int res = (n - cnt * maxi) / (maxi - 1) + cnt - 1;
    cout << res << "\n";
  }
  return 0;
}
