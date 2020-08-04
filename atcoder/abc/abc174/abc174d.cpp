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
  string s; cin >> s;
  vector<int> wsum(n+1),rsum(n+1);
  wsum[0] = 0;
  rsum[0] = 0;
  rep(i,n) {
    if(s[i] == 'W') {
      wsum[i+1] = wsum[i] + 1;
      rsum[i+1] = rsum[i];
    }
    else {
      wsum[i+1] = wsum[i];
      rsum[i+1] = rsum[i] + 1;      
    }
  }

  int res = 1e+6;
  rep(i,n+1) {
    int tmp = max(wsum[i], rsum[n] - rsum[i]);
    chmin(res, tmp);
  }
  cout << res << "\n";
  
  return 0;
}
