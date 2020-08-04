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
  ll n; cin >> n;
  vector<ll> a(n+1);
  rep(i,n) cin >> a[i];

  a[n] = 0;
  ll kane = 1000;
  ll kabu = 0;
  ll bef = 300;
  rep(i,n) {
    if(a[i] <= bef && a[i] < a[i+1]) {
      kabu += kane / a[i];
      kane -= kane / a[i] * a[i];
    }
    if(bef <= a[i] && a[i+1] < a[i]) {
      kane += kabu * a[i];
      kabu = 0;
    }
    bef = a[i];
  }
  cout << kane << "\n";
  
  return 0;
}
