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
  int n; cin >> n;
  map<int,int> mp;
  int x = 7;
  int res = 1;
  while(1) {
    int tmp = x % n;
    if(mp[tmp] > 0) {
      cout << -1 << "\n";
      return 0;
    }
    mp[tmp]++;
    if(tmp == 0) {
      cout << res << "\n";
      return 0;
    }
    res++;
    x = tmp*10 + 7;
  }
  return 0;
}
