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
using vi = vector<int>;
using vii = vector<vi>;
int main()
{
  int n; cin >> n;
  vi dp(n+1, 1);
  rep1(i,n) {
    int tmp = i;
    int next = i;
    while(tmp > 0) {
      next += tmp % 10;
      tmp /= 10;
    }
    if(next > n) continue;
    dp[next] += dp[i];
  }
  cout << dp[n] << "\n";
  
  return 0;
}
