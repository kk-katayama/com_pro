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
  ll x,k,d; cin >> x >> k >> d;
  if(x < 0) x *= -1;
  if(x / d > k) {
    cout << x - k * d << "\n";
  }
  else {
    ll m = x / d;
    if( (k - m) % 2 == 0) {
      cout << x - m * d << "\n";
    }
    else {
      cout << (m + 1) * d - x << "\n";
    }
  }

  return 0;
}
