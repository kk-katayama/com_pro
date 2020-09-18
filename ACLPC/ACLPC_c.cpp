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
#define rep2(i,s,t) for(int i = s; i <= t; ++i)
#define rev(i,n) for(int i = n-1; i >= 0; --i)
#define rev1(i,n) for(int i = n; i > 0; --i)
#define rev2(i,s,t) for(int i = s; i >= t; --i)
#define F first
#define S second
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a < b){ a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(a > b){ a = b; return 1; } return 0; }
using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vii = vector<vi>;

ll floor_sum(ll n, ll m, ll a, ll b) {
  ll res = 0;
  if(a >= m) {
    res += n*(n - 1)*(a/m) / 2;
    a %= m;
  }
  if(b >= m) {
    res += n*(b/m);
    b %= m;
  }

  ll ymax = (a*n + b)/m, xmax = m*ymax - b;
  if(ymax == 0) return res;
  res += ymax*(n - (xmax + a - 1)/a);
  res += floor_sum(ymax, a, m, (a - xmax%a)%a);
  return res;
}

int main()
{
  int t; scanf("%d", &t);
  while(t-- > 0) {
    ll n,m,a,b; scanf("%lld %lld %lld %lld", &n, &m, &a, &b);
    printf("%lld\n", floor_sum(n,m,a,b));
  }
  return 0;
}
