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
ll P = 200003;
int main()
{
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll sum = 0, psum = 0;
  rep(i,n) {
    sum += a[i];
    psum += a[i]*a[i];
  }

  ll x = (sum * sum - psum) / 2;
  ll cnt = 0;
  rep(i,n) {
    rep(j,n) {
      if(i >= j) continue;
      cnt += a[i]*a[j] / P;
    }
  }
  cout << x - cnt * P << "\n";
  
  return 0;
}
